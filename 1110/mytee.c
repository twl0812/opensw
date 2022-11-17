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
    int fp=open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,0644);
    if(fp==-1) 
    {
        printf("error");
        return 0;
    }
    while(1)
    {
    int nb=read(0,buff,BUF_SZ);
    if(nb==0) break;
    write(fp,buff,nb);
    write(1,buff,nb);
    }
    close(fp);
    int idx=argc;
    if(idx==2) return 0;
     else
    {
        int fd[idx+1];
      for(int i=2;i<=idx;i++)
     {
        char buf[BUF_SZ];
        fp=open(argv[1],O_RDONLY);
        fd[i]=open(argv[i],O_RDWR|O_CREAT|O_TRUNC,0644);
            while(1)
            {
                 int nb=read(fp,buf,BUF_SZ);
                 if(nb==0) break;
                 write(fd[i],buf,nb);
            }
            close(fd[i]);
            close(fp);
        }
    }
}
