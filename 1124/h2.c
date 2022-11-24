#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


void my_int_handler(int signo)
{
    printf("h %di\n",signo);
}
int main()
{
    struct sigaction sa;
    sa.sa_handler=my_int_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags=0;
    sigaction(SIGINT,&sa,NULL);
 while(1)
 {
     printf("pid: %d\n",getpid());
     sleep(2);
 }

}
