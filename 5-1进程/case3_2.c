#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char const *argv[])
{
	pid_t pid;
	int status;
	pid = fork();
	if(pid == 0){
		printf("this is a child, pid = %d!\nBye,bye!", getpid());
		sleep(1);
	}else if(pid > 0){
		printf("this is a father, pid = %d\n", getpid());
		while(1){
			if(waitpid(pid, &status, WNOHANG) > 0)break;
			printf("这个月生活费1000元。\n");
			usleep(100000);
		}
		printf("你毕业了，自己花钱自己挣！\n");
	}else{
		perror("fork");
		return -1;
	}
	return 0;
}