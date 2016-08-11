#include <stdio.h>
#include <unistd.h>
#include <signal.h>


void * fun()
{
	printf("O\n");
	return NULL;
}
int main(int argc, char const *argv[])
{
	signal(SIGUSR1, fun);
	while(1){
		pause();
	}
	return 0;
}