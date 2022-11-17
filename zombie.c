#include <sys/types.h>
#include <unistd.h>
#include<wait.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
    pid_t p=fork();
    if(p==0) //child
    {
     printf("c: pid: %d, ppid: %d\n",getpid(),getppid()); 
     for(int i=0;i<100;i++) {
        printf("%d ",i);
     fflush(NULL);
     }
     exit(101);
    }
    else //wait를 안할때  ppid <-> parent pid 가 다를 수 가있음 zombie 프로세스
    {
        //while(1);

        int exitstatus;
        for(int i=100;i<200;i++) {
            printf("%d ",i);
            fflush(NULL);
        }
        wait(&exitstatus);
    printf("p: pid: %d, ppid: %d\n",getpid(),getppid());
    printf("exitcode: %d\n",WEXITSTATUS(exitstatus));
    }

}