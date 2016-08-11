#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
	printf("main start\n");
	raise(SIGKILL);
	//kill(getpid(), SIGKILL);
	printf("main end\n");
	return 0;
}