#include<stdio.h>
#include<stdlib.h>
int my_system(char *command)
{
    //your code comes here.....
    //use fork() and exec...
}
int main()
{
    system("ls -l | wc -l");
    printf("hello world");
    return 0;
}