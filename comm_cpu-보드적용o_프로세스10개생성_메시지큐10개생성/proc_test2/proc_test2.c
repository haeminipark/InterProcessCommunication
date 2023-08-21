#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "mydefine.h"

typedef struct {
    long type;
    char text[MSG_TEXT_MAX];
} Message;

pthread_mutex_t send_mutex;
pthread_mutex_t recv_mutex;

void *tx_thread_function(void *arg)
{
	Message message;
	memset(&message, 0, sizeof(message));
    message.type = 1;
	

	for(int i=0; i<MSG_TEXT_MAX; i++)
        message.text[i] = 20+i;

	while(1)
	{
//		printf("[2] tx_thread_function\r\n");
		pthread_mutex_lock(&send_mutex);

        if (msgsnd(MsgQId[MSGQ_2], &message, sizeof(message), IPC_NOWAIT) < 0) 
        {
            perror("msgsnd");
            exit(EXIT_FAILURE);
        }

		printf("proc2_tMsgQ[%02u]: ", MSGQ_2);
		for(int i=0; i<MSG_TEXT_MAX; i++)
        {
            printf("%03u ", message.text[i]);
        }
        printf("\r\n");

		pthread_mutex_unlock(&send_mutex);
		sleep(1);
	}

}

void *rx_thread_function(void *arg)
{
	Message message;
	memset(&message, 0, sizeof(message));
	message.type = 1;

	while(1)
	{
//		printf("[2] rx_thread_function\r\n");
		pthread_mutex_lock(&recv_mutex);

        if (msgrcv(MsgQId[MSGQ_3], &message, sizeof(message), message.type, IPC_NOWAIT) < 0) 
        {
            if (errno == ENOMSG)    // msgrcv: No message of desired type 에러방지
            {
                printf("proc2_rMsgQ[%02u]: No message.\n", MSGQ_3);
            }
            else
            {
                perror("msgrcv");
                exit(EXIT_FAILURE);
            }
        }

        printf("proc2_rMsgQ[%02u]: ", MSGQ_3);
        for(int i=0; i<MSG_TEXT_MAX; i++)
        {
            printf("%03u ", message.text[i]);
        }
        printf("\r\n");

		pthread_mutex_unlock(&recv_mutex);
		sleep(1);
	}
}

int main(void)
{
    pthread_t send_threads;
    pthread_t recv_threads;

	/* Get MsgQ */
	key_t Key = ftok(".", MSGQ_2);
	if (-1 == (MsgQId[MSGQ_2] = msgget(Key, 0666)))
	{
        perror("MSQ Create Fail");
		exit(EXIT_FAILURE);
	}
    else
    {
        printf("MsgQ[%u] key: %u\r\n", MSGQ_2, Key);
    }

	Key = ftok(".", MSGQ_3);
	if (-1 == (MsgQId[MSGQ_3] = msgget(Key, 0666)))
	{
        perror("MSQ Create Fail");
		exit(EXIT_FAILURE);
	}
    else
    {
        printf("MsgQ[%u] key: %u\r\n", MSGQ_3, Key);
    }

    /* Create Thread */
	pthread_mutex_init(&send_mutex, NULL);
    pthread_mutex_init(&recv_mutex, NULL);

    if (pthread_create(&send_threads, NULL, tx_thread_function, NULL) != 0) 
    {
        perror("[PROC_TEST2] tx_thread_function");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("[PROC_TEST2] Create send_threads\r\n");
    }
	
    if (pthread_create(&recv_threads, NULL, rx_thread_function, NULL) != 0) 
    {
        perror("[PROC_TEST2] rx_thread_function");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("[PROC_TEST2] Create receive_threads\r\n");
    }

    // Wait for all send threads to finish
	pthread_join(send_threads, NULL);
	pthread_join(recv_threads, NULL);
			
    return 0;
}
