#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	int fd[2];
	int ret;
	int totalBytes;
	if( -1 == pipe(fd) ){
		perror("pipe");
		return -1;
	}
	while(1){
		ret = write(fd[1], "1", 1);
		if(ret < 1)break;
		else totalBytes += ret;
		printf("\rtotal %8d bytes in pipe", totalBytes);
		fflush(0);
	}
	close(fd[0]);
	close(fd[1]);
	return 0;
}