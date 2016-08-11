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
	printf("file length = %ld\n", st_stat.st_size);
	
	printf("last modified time = %s\n", ctime(&(st_stat.st_mtime)));

	return 0;
}	