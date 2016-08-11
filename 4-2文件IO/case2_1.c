#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd;	
	fd = open("newfile1", O_EXCL | O_CREAT, 0600);
	if(fd == -1 ){
		perror("open");
		return 0;
	}
	printf("creat file ok\n");
	close(fd);
	return 0;
}