#include "fun.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char ** argv)
{
	if(argc < 3){
		printf("param error\n");
		return 0;
	}
	float a = atof(argv[1]);
	float b = atof(argv[2]);
	printf("a = %f\n", a);
	printf("b = %f\n", b);
	float c;
	c = devide(a, b);
	if(myerrno == 0)printf("result = %.03f\n", c);
	else printf("myerrno = %d!\n", myerrno);
}