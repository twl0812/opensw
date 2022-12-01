#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX 1

struct thread_data{
    long long start;
    long long end;
    long long sum;
};
void *worker(void* args)
{
    struct  thread_data * data;
    data=(struct thread_data *)args;

    for(long long i=data->start;i<=data->end;i++)
    {
        data->sum+=i;
    }
    pthread_exit(NULL);
}
int main(void)
{
    pthread_t my_thread;
    struct thread_data my_data;
    my_data.start=0;
    my_data.end=100;
    my_data.sum=0;
    pthread_create(&my_thread,NULL,worker,(void *)&my_data);

    pthread_join(my_thread,NULL);

    printf("sum: %lld\n",my_data.sum);
}
