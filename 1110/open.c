#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
int main(int argc,char *argv[]) //argc num,argv parameter
{
    if(argc!=2) // first -> 명령어
    {
        printf("usage: opentest filename\n");
        exit(0);
    }
    printf("first parameter: %s\n",argv[0]);
     printf("secend parameter: %s\n",argv[1]);
     int fp=open(argv[1],O_RDONLY); //file descripter

     if(fp==-1) //open error
     {
        perror("open: ");
        exit(-1);
     }
     printf("file %s success!",argv[1]);
     close(fp);
}