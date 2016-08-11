#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <wait.h>


int main(int argc, char const *argv[])
{
	int fd[2];
	pid_t pid;
	int ret;
	char buf[1024];
	if(-1 == pipe(fd)){
		perror("pipe");
		return -1;
	}

	pid = fork();
	if(pid == 0){
		while(1){
			usleep(1000);
			ret = read(fd[0], buf, 7);
			if(ret < 0){
				perror("read");
				break;
			}
			else {
				printf("read %d bytes from pipe\n", ret);
			}
		}
	}else if(pid > 0){
		while(1){
			usleep(1000);
			ret = write(fd[1], buf, 20);
			if(ret < 0){
				perror("read");
				break;
			}
			else {
				printf("write %d bytes in pipe!\n", ret);
			}
		}
		wait(NULL);
	}
	close(fd[0]);
	close(fd[1]);
	return 0;
}
