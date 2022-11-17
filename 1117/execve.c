#include <unistd.h>
#include<stdio.h>
#include <sys/types.h>
#include<sys/wait.h>
#include <unistd.h>
#include<stdlib.h>

int main()
{
    pid_t p = fork();
    if(p==0)
    {
   char * new_argv[]={"ls","-a","-l",NULL}; // 길이가 계속 바뀌기 때문에 널 전에 넣고 싶은 옵션을 넣어줌
   execve("/bin/ls",new_argv,NULL);//pathname절대경로
    exit(101);
    }
    else
    {
        int e;
        wait(&e);
    }
    printf("\n\nhello world\n");
   return 0;
}