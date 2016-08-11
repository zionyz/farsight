#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	int fd[2];
	int ret;
	char buf[1024] = "1111111111";
	if( -1 == pipe(fd)){
		perror("pipe");
		return -1;
	}
	ret = write(fd[1], buf, 10);
	if(ret != 10){
		perror("write");
		return -1;
	}else{
		printf("wirte %d bytes in pipe:\n\t %s\n", ret, buf);
	}
	bzero(buf, sizeof(buf));
	ret = read(fd[0], buf, sizeof(buf));
	if(ret < 0){
		perror("read");
		return -1;
	}else{
		printf("read %d bytes from pipe:\n\t %s\n", ret, buf);
	}
	close(fd[0]);
	close(fd[1]);	
	return 0;
}