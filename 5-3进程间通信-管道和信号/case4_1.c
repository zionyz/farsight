#include <stdio.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
	printf("this is a example for alarm!\n");
	alarm(3);
	pause();
	printf("wake up!\n");
	return 0;
}