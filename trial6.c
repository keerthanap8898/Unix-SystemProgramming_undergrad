#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
static void charatatime(char *);
int main(int argc, char*argv[])
{
pid_t pid;
if((pid=fork())<0)
printf("error");
if(pid==0)
charatatime("this is output from child");
else
charatatime("this is output from parent");
exit(1);
}
void charatatime(char *str)
{
char *ptr,c;
setbuf(stdout, NULL); 
for (ptr=str;(c=*ptr++)!=0;)
putc(c,stdout);
}

