#include <stdio.h>

int main()
{
	unsigned char buf[1024];
	scanf("%s", buf);
	printf("printf in stdout [%s]\n", buf);
	//fprintf(stdout, "printf in stdout [%s]\n", buf);
	fprintf(stderr, "printf in stderr [%s]\n", buf);
	return 0;
}