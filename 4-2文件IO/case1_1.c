#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd;	
	fd = open("newfile", O_WRONLY | O_CREAT |O_TRUNC, 0644);
	if(fd == -1 ){
		perror("open");
		return -1;
	}
	printf("open ok\n");
	close(fd);
	return 0;	
}