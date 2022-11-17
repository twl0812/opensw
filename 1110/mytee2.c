#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#define BUF_SZ 10000
int main(int argc,char *argv[]) //argc num,argv parameter
{
    if(argc==1)
    {


        printf("usage: filename ");
        exit(0);
    }
    char buff[BUF_SZ];
    int fp2=open(argv[1],O_RDWR|O_CREAT|O_TRUNC,0644);
    if(fp2==-1) 
    {
        printf("error");
        return 0;
    }
    while(1)
    {
    int nb=read(0,buff,BUF_SZ);
    if(nb==0) break;
    write(fp2,buff,nb);
    write(1,buff,nb);
    }
    close(fp2);
}
