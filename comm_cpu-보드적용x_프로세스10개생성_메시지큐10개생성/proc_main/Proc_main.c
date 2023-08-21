#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>

#include "mydefine.h"


typedef enum {
	PROC_TEST0 = 0,
	PROC_TEST1,
	PROC_TEST2,
	PROC_TEST3,
	PROC_TEST4,
	PROC_TEST5,
	PROC_TEST6,
	PROC_TEST7,
	PROC_TEST8,
	PROC_TEST9,
	PROC_MAX,
}TASK_NUM;

typedef struct {
	char Dir[20];
	char Name[20];
}TASK_INFO;

TASK_INFO 	TaskInfo[] =
{
	{"./PROC_TEST0", "PROC_TEST0"},
	{"./PROC_TEST1", "PROC_TEST1"},
	{"./PROC_TEST2", "PROC_TEST2"},
	{"./PROC_TEST3", "PROC_TEST3"},
	{"./PROC_TEST4", "PROC_TEST4"},
	{"./PROC_TEST5", "PROC_TEST5"},
	{"./PROC_TEST6", "PROC_TEST6"},
	{"./PROC_TEST7", "PROC_TEST7"},
	{"./PROC_TEST8", "PROC_TEST8"},
	{"./PROC_TEST9", "PROC_TEST9"},
};

int max_task_num = sizeof (TaskInfo) / sizeof(TASK_INFO);    /* TASKÀÇ °¹¼ö*/


int main(void) 
{

	memset(MsgQId, 0, sizeof(int) * MSGQ_MAX);

    /* Create MSQ */
    for (int i = 0; i < MSGQ_MAX; i++)
	{
        key_t Key = ftok(".", i);
		if (-1 == (MsgQId[i] = msgget(Key, IPC_CREAT | 0666)))
		{
            perror("MSQ Create Fail");
			exit(EXIT_FAILURE);
		}
        else
        {
			printf("MsgQ[%u] key: %u\r\n", i, Key);
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
			if(execlp (TaskInfo[i].Dir, TaskInfo[i].Name, NULL) == -1)
			{
				printf ("%s Task Create Failed. [%s]\n", TaskInfo[i].Name, "Error");
			}
			else
			{
				printf ("%s Task Create Successed. \n", TaskInfo[i].Name);
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