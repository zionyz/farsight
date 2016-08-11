#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void * fun(void * para)
{
	printf("O\n");
	alarm(1);
	return NULL;
}
int main(int argc, char const *argv[])
{
	printf("this is a example for alarm!\n");
	signal(SIGALRM, fun);
	alarm(1);
	while(1){
		pause();
	}
	return 0;
}