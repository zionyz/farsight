#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>



int main(int argc, char const *argv[])
{
	if(argc < 2){
		printf("usage: %s msg_to_pipe\n", argv[0]);
		return 0;
	}
	char filename[] = "/tmp/pipetest";
	if(-1 == access(filename, 0)){
		if(errno == 2 && -1 == mkfifo(filename, 0644)){
			perror("mkfifo");
			return -1;
		}else if(errno != 2){
			perror("access");
			return -1;
		}		
	}

	int fd;
	int ret;
	int wBytes;
	fd = open(filename, O_WRONLY | O_EXCL);
	if(fd < 0){
		perror("open");
		return -1;
	}
	
	wBytes = strlen(argv[1]);
	ret = write(fd, argv[1], wBytes);
	if(ret == wBytes){
		printf("write %d bytes in pipe\n", wBytes);
	}else{
		perror("write");
	}

	return 0;
}