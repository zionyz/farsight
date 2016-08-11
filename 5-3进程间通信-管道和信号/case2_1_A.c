#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>



int main(int argc, char const *argv[])
{
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
	char buf[1024];
	fd = open(filename, O_RDONLY | O_EXCL);
	if(fd < 0){
		perror("open");
		return -1;
	}
	while(1){
		bzero(buf, sizeof(buf));
		ret = read(fd, buf, sizeof(buf));
		if(ret > 0){
			printf("%s\n", buf);
		}else if(ret < 0){
			perror("read");
			break;
		}
	}

	return 0;
}