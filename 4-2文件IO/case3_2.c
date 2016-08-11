#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	unsigned char buf[256] = {0};
	int i = 0, ret;
	int fd;	
	fd = open("newfile3_1", O_RDONLY);
	if(fd == -1 ){
		perror("open");
		return 0;
	}
	printf("open file ok\n");
	ret = read(fd, buf, sizeof(buf));
	if(ret >= 58)
	{
		buf[58] = 0;
		printf("%s\n", buf+48);
	}
	close(fd);
}