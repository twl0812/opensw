#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void foo()
{
	printf("hello foo\n");
}
void soo()
{
        printf("hello soo\n");
}
void goo()
{
        printf("hello goo\n");
}

int main()
{
 while(1)
 {
 	 printf("pid: %d\n",getpid());
 	sleep(2);
 }

}
