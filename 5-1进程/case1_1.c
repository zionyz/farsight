#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{	
	printf("My pid = %d!\n", getpid());
	printf("My father pid = %d\n", getppid());	
	sleep(100);
	//getc(stdin);
	return 0;
}