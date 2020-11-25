#include  <stdio.h>
#include  <sys/types.h>

#define   MAX_COUNT  200

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

int randForProcess(){
  srand((time(NULL)*390));
  int randomNum = ((rand()%30)+1);
  return randomNum;
}

int randForSleep(){
  srand((time(NULL)));
  int randomNum = ((rand()%10)+1);
  return randomNum;
}
void  main(void)
{
     pid_t  pid1, pid2;

     pid1 = fork();
     if (pid1 == 0){
       ChildProcess();
     } 
         // ChildProcess();
     else {
       pid2 = fork();
       if (pid2 == 0){
       ChildProcess();
       }
     }
     ParentProcess();
}

void  ChildProcess(void)
{
     int   i;

     for (i = 1; i <= randForProcess(); i++){
       printf(" Child Pid: %d is going to sleep! \n", getpid());
       sleep(randForSleep());
       printf("Child Pid: %d is awake! \n Where is my parent: %d?\n", getpid(), getppid());  
     }
     exit(0);
       
         // printf("   This line is from child, value = %d\n", i);
    // printf("   *** Child process is done ***\n");
}

void  ParentProcess(void)
{
     wait(NULL);
     int   i;

     //for (i = 1; i <= MAX_COUNT; i++)
        //  printf("This line is from parent, value = %d\n", i);
     printf("Child Pid: %d has completed\n", get pid());
}