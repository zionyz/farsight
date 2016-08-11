#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>


int main(int argc, char const *argv[])
{
	struct stat st_stat;
	int fd;	
	if(argc != 2){
		printf("get file length\nusage:\t%s, file1", argv[1]);
		return 0;
	}
	stat(argv[1], &st_stat);
	printf("%s\n", argv[1]);
	if(S_ISREG(st_stat.st_mode))printf(" is regular file\n" );
	else if(S_ISDIR(st_stat.st_mode))printf(" is directory\n" );
	else printf("not directory or regular file\n");
	return 0;
}	