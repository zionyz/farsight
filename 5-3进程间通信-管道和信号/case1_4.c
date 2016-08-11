#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <wait.h>
#include <string.h>
#include <stdlib.h> 
#include <errno.h>
#if 1
int main(int argc, char const *argv[])
{
	int fd[2];
	pid_t pid;
	char buf[5120] ="";
	int ret;
	if(-1 == pipe(fd)){
		perror("pipe");
		return -1;
	}

	pid = fork();
	if(pid == 0){
		dup2(fd[1], STDOUT_FILENO);
		execlp("ifconfig", "ifconfig", NULL);
		perror("execlp");
	}else if(pid > 0){
		wait(NULL);
		ret = read(fd[0], buf, sizeof(buf));
		if(ret < 0){
			perror("read");
		}else if(ret > 0){
			printf("get result form process(pid = %d):\n", pid);
			printf("%s", buf);
		}
	}
	return 0;
}
#endif

#if 0

int main(int argc, char const *argv[])
{
	int fd[2];
	pid_t pid;
	char buf[5120];
	int ret;
	if(-1 == pipe2(fd, O_NONBLOCK)){
		perror("pipe");
		return -1;
	}

	pid = fork();
	if(pid == 0){
		dup2(fd[1], STDOUT_FILENO);
		execlp("top", "top", NULL);
		perror("execlp");
	}else if(pid > 0){
		while(1){
			bzero(buf, sizeof(buf));
			if(waitpid(pid, NULL, WNOHANG) > 0)break;
			ret = read(fd[0], buf, sizeof(buf));
			if(ret < 0 && errno != EAGAIN){
				perror("read");
				break;
			}else if(ret > 0){
				printf("%s", buf);
				fflush(0);
			}
		}
	}
	close(fd[0]);
	close(fd[1]);
	return 0;
}
#endif