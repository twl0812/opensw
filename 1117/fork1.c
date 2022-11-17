#include <sys/types.h>
#include <unistd.h>
#include<wait.h>
#include<stdio.h>

int main()
{
    pid_t p=fork();
    if(p==0) //child
    {
     printf("c: pid: %d, ppid: %d\n",getpid(),getppid()); 
    }
    else //wait를 안할때  ppid <-> parent pid 가 다를 수 가있음 zombie 프로세스
    {
        int exitstatus;
        wait(&exitstatus);
    printf("p: pid: %d, ppid: %d\n",getpid(),getppid());
    }

}