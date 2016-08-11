#include <stdio.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
	pid_t pid;
	pid = fork();
	if(pid == 0){
		printf("this is a child, pid = %d!\n", getpid());
	}else if(pid > 0){
		printf("this is a father, pid = %d\n", getpid());
	}else{
		perror("fork");
		return -1;
	}
	sleep(100);
	return 0;
}