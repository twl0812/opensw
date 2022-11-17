#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#define BUF_SZ 64
int main(int argc,char *argv[]) //argc num,argv parameter
{
    if(argc!=3) // first -> 명령어
    {
        printf("usage: filename\n");
        exit(0);
    }
    printf("first parameter: %s\n",argv[0]);
     printf("secend parameter: %s\n",argv[1]);
     int fp1=open(argv[1],O_RDONLY); //file descripter
     int fp2=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0644);
     char buff[BUF_SZ];
     if(fp1==-1 ||fp2 ==-1) //open error
     {
        perror("open: ");
        exit(-1);
     }
     while(1)
     {
        int nb=read(fp1,buff,BUF_SZ);
        if(nb==0) { //EOF
            break;
        }
        write(fp2,buff,nb);
     }
     close(fp1);
     close(fp2);
}