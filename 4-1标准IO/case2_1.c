#include <stdio.h>

int main()
{
	int c = '2';
	int len = 0;
	FILE * fp = fopen("case2.ppp", "w");
	if(fp == NULL){
		perror("fopen");
		return -1;
	}
	while(len < 999){
		fputc(c, fp);
		len++;
	}
	c = '1';
	fputc(c, fp);
	fclose(fp);
	return 0;	
}