#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>

#define NUM_MSGQ        4

typedef enum {
	PROC_TEST1 = 0,
	PROC_TEST2,
	PROC_TEST3,
	PROC_TEST4,
	PROC_TEST5,
	PROC_MAX,
}TASK_NUM;

typedef struct {
	char Dir[20];
	char Name[20];
}TASK_INFO;

TASK_INFO 	TaskList[] =
{
	{"./PROC_TEST1", "PROC_TEST1"},
	{"./PROC_TEST2", "PROC_TEST2"},
	{"./PROC_TEST3", "PROC_TEST3"},
	{"./PROC_TEST4", "PROC_TEST4"},
	{"./PROC_TEST5", "PROC_TEST5"},
};

int max_task_num = sizeof (TaskList) / sizeof(TASK_INFO);    /* TASKÀÇ °¹¼ö*/

int MsgQId[NUM_MSGQ];

int main(void) 
{

	memset(MsgQId, 0, sizeof(int) * NUM_MSGQ);

    /* Create MSQ */
    for (int i = 0; i < NUM_MSGQ; i++)
	{
        key_t MsgQ_Key = (key_t)i+100;
		if (-1 == (MsgQId[i] = msgget(MsgQ_Key, IPC_CREAT | 0666)))
		{
            perror("MSQ Create Fail");
			exit(EXIT_FAILURE);
		}
        else
        {
            printf("Create MsgQ, id: %u key: %x\r\n", i, MsgQ_Key);
        }
	}

	/* Create Process */
    for (int i = 0; i < PROC_MAX; i++) 
	{
        pid_t pid = fork();
        
        if (pid < 0) 
		{
            perror("fork error");
            return 1;
        } 
		else if (pid == 0) 
		{
			if(execlp (TaskList[i].Dir, TaskList[i].Name, NULL) == -1)
			{
				printf ("%s Task Create Failed. [%s]\n", TaskList[i].Name, "Error");
			}
			else
			{
				printf ("%s Task Create Successed. \n", TaskList[i].Name);
			}

            // If execlp fails
            perror("execlp error");
            return 1;
        } 
		else 
		{
            // Parent process
            ;
        }
    }
    
    return 0;
}