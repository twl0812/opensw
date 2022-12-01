#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX 1

volatile static long long cnt=0;
volatile static char is_run=1;
void *myfunc(void *arg)
{
    printf("hello thread world\n");
    pthread_exit(NULL);
}
void *func(void *arg)
{
        while(is_run) {
            cnt++;
        }
        exit(1);
}
int main()
{
    pthread_t myp[MAX];
    int i;
    int p[MAX];
    for(int j=0;j<MAX;j++) p[j]= pthread_create(&myp[j],NULL,func, NULL);


    for(int j=0;j<10;j++)
    {
        printf("%lld\n",cnt);
        sleep(1);
    }
    is_run=0;

    for(int j=0;j<MAX;j++) pthread_join(myp[j],NULL);
    return 0;
}
