#include <stdio.h>


int main(int argc, char ** argv)
{
	char c;
	int i;
	int flen = 0;
	
	if(argc != 2){
		printf("按字符颠倒打印一个文件\nusage:\t%s file1 \n", argv[0]);
		return 0;
	}
	FILE * fp = fopen(argv[1], "r");
	if(fp == NULL )
	{
		perror("fopen");
		return 0;
	}
	fseek(fp, -1, SEEK_END);
	while(ftell(fp) > 0){
		fread(&c, 1, 1, fp);
		printf("%c", c);
		fseek(fp, -2, SEEK_CUR);
	}
	fread(&c, 1, 1, fp);
	printf("%c", c);
	fclose(fp);
}