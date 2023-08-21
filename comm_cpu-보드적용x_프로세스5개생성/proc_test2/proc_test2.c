#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

pthread_mutex_t send_mutex;
pthread_mutex_t recv_mutex;

void *send_thread_function(void *arg)
{
	while(1)
	{
		printf("[2] send_thread_function\r\n");
		pthread_mutex_lock(&send_mutex);
		pthread_mutex_unlock(&send_mutex);
		sleep(1);
	}

}

void *recv_thread_function(void *arg)
{
	while(1)
	{
		printf("[2] recv_thread_function\r\n");
		pthread_mutex_lock(&send_mutex);
		pthread_mutex_unlock(&send_mutex);
		sleep(1);
	}
}

int main(void)
{
    pthread_t send_threads;
    pthread_t recv_threads;

    /* Create Thread */
	pthread_mutex_init(&send_mutex, NULL);
    pthread_mutex_init(&recv_mutex, NULL);

    if (pthread_create(&send_threads, NULL, send_thread_function, NULL) != 0) 
    {
        perror("[proc_test2] send_thread_function");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("[proc_test2] Create send_threads\r\n");
    }
	
    if (pthread_create(&recv_threads, NULL, recv_thread_function, NULL) != 0) 
    {
        perror("[proc_test2] recv_thread_function");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("[proc_test2] Create receive_threads\r\n");
    }

    // Wait for all send threads to finish
	pthread_join(send_threads, NULL);
	pthread_join(recv_threads, NULL);
			
    return 0;
}
