#include  <stdio.h>
#include  <sys/types.h>

#define   MAX_COUNT  200

void  ChildProcess(int);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
     int i;
     pid_t  pid;
     for (i=0; i<2; i++){
     pid = fork();
     if (pid == 0) 
          ChildProcess(i);
     else if (pid < 0)
          printf("Error in fork \n");
     }
          ParentProcess();
}

void  ChildProcess(int mypid)
{
     int random_number;
     printf("Child Process PID: %d is going to sleep!", getpid());
     srand(getpid());
     random_number = rand() % 10;
     sleep(random_number + 1);
     printf("Child Pid: is awake!\nWhere is my Parent: %d?\n", getpid());
}

void  ParentProcess(void)
{
     int i;
     int pid;
     int status;
     
     for (i = 0; i <= 2; i++){
     pid = wait(&status);
     printf("Child Pid: %d has completed\n",pid);
     }
}