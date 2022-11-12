#include <unistd.h>
#include <sys/types.h>
#include<stdio.h>
//make print pid & ppid
int main()
{
    pid_t my_pid;
    pid_t my_ppid;

    my_pid=getpid();
    my_ppid=getppid();

    printf("pid: %d, ppid: %d\n",my_pid,my_ppid);
}
