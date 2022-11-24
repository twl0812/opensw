#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


void my_int_handler(int signal)
{
    printf("hi %d\n",signal);
}
void my_quit_hander(int signal)
{
    printf("good bye\n");
    exit(0);
}
int main()
{
    struct sigaction sa;
    sa.sa_handler=my_int_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags=0;

    struct sigaction s_quit;
    sa.sa_handler=my_quit_hander;
    sigemptyset(&s_quit.sa_mask);
    s_quit.sa_flags=0;

    sigaction(SIGINT,&sa,NULL);
    sigaction(SIGQUIT,&s_quit,NULL);
 while(1)
 {
     printf("pid: %d\n",getpid());
     sleep(2);
 }
}
