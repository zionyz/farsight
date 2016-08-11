#include <stdio.h>
#include <string.h>

int main()
{
	char buf[1024] ={
		"我住长江头，君住长江尾。\n"
		"日日思君不见君，共饮长江水。\n"
		"此水几时休？此恨何时已？\n"
		"只愿君心似我心，定不负相思意。\n"
	};
	int  ret;
	FILE * fp = fopen("卜算子.log", "w+");

	if(fp == NULL )
	{
		perror("fopen");
		return 0;
	}
	fwrite(buf, 1, strlen(buf), fp);
	flose(fp);	
	return 0;
}