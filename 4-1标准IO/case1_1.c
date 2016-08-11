#include <stdio.h>

int main()
{
	FILE * fp = fopen("new1", "w");
	if(fp == NULL){
		perror("fopen");
	}else{
		printf("creat file ok!\n");
	}
	fclose(fp);
	return 0;
}