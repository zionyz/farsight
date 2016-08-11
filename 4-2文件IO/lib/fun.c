#include "fun.h"

int myerrno = 0;

float devide(float a, float b)
{
	if(b == 0){
		myerrno = 1;
		return -1;
	}
	return a/b;
}
