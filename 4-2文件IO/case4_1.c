#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char ** argv)
{
	long length;
	int fd;	
	if(argc != 2){
		printf("calc file length\nusage:\t%s, file1", argv[1]);
		return -1;
	}
	fd = open(argv[1], O_RDONLY );
	if(fd == -1 ){
		perror("open");
		return -1;
	}
	length = lseek(fd, 0, SEEK_END);
	printf("file length = %ld\n", length);
	close(fd);
	return 0;
}