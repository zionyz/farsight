#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	pid_t pid;
	int i = 10000;
	pid = fork();
	if(pid == 0){
		printf("this is a child, pid = %d!\n", getpid());
		while(i--){
			printf(".");
			fflush(0);
		}
	}else if(pid > 0){
		printf("this is a father, pid = %d\n", getpid());
		while(i--){
			printf("*");
			fflush(0);
		}
	}else{
		perror("fork");
		return -1;
	}
	return 0;
}