#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <utime.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
int main(int argc,char *argv[])
{
struct utimbuf times;
struct stat buf1;
struct stat buf2;
if(stat(argv[1],&buf1)<0)
printf("error");
if(stat(argv[2],&buf2)<0)
printf("error");
printf("before mod a and m %s %s",ctime(&buf1.st_atime),ctime(&buf1.st_mtime));
times.actime=buf2.st_atime;
times.modtime=buf2.st_mtime;
if(utime(argv[1],&times)<0)
printf("error");
if(stat(argv[1],&buf1)<0)
printf("error");
printf("after mod a and m %s %s",ctime(&buf1.st_atime),ctime(&buf1.st_mtime));
}
