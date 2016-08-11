#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



void fun()
{
	printf("in fun!");
	exit(0);
	//_exit(0);
}
int main(int argc, char const *argv[])
{
	fun();
	printf("fun over!\n");
	return 0;
}