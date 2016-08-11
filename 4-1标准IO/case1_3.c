#include <stdio.h>

int main()
{
	FILE * fp = fopen("existfile", "w");
	if(fp == NULL){
		perror("fopen");
	}else{
		printf("open file ok!\n");
	}
	fclose(fp);
	return 0;
}