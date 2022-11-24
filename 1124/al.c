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
void my_alram_hander(int signal)
{
    alarm(2);
    printf("alarm\n");
}
int main()
{
    struct sigaction sa;
    sa.sa_handler=my_int_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags=0;
    sigaction(SIGINT,&sa,NULL);

    struct sigaction s_quit;
    s_quit.sa_handler=my_quit_hander;
    sigemptyset(&s_quit.sa_mask);
    s_quit.sa_flags=0;
    sigaction(SIGQUIT,&s_quit,NULL);
    
    struct  sigaction al;
    al.sa_handler=my_alram_hander;
    al.sa_flags=0;
    sigemptyset(&al.sa_mask);
    sigaction(SIGALRM,&al,NULL);
    alarm(5);

 while(1)
 {
     printf("pid: %d\n",getpid());
     sleep(2);
 }

}


