#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	pid_t pid;
	int status;
	pid = fork();
	if(pid == 0){
		printf("this is a child, pid = %d!\nchild died!", getpid());
	}else if(pid > 0){
		printf("this is a father, pid = %d\n", getpid());
		//wait(&status);
		sleep(100);
		printf("father died!\n");
	}else{
		perror("fork");
		return -1;
	}
	return 0;
}