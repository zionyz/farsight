#include <stdio.h>


int main(int argc, char ** argv)
{
	long length;
	if(argc != 2){
		printf("get file length\nusage:\t%s file1 \n", argv[0]);
		return -1;
	}
	FILE * fp = fopen(argv[1], "r");
	if(fp == NULL )
	{
		perror("fopen");
		return -1;
	}
	fseek(fp, 0, SEEK_END);
	length = ftell(fp);
	printf("length of [%s] is [%d]\n", argv[1], length);
	fclose(fp);
}