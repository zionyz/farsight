#include <stdio.h>

int main(int argc, char ** argv)
{
	if(argc != 2){
		printf("usage:\t%s file1\n", argv[0]);
		return 0;
	}
	char buf[1024] ={0};
	int  ret, i;
	FILE * fp = fopen(argv[1], "r+");
	
	if(fp == NULL)
	{
		perror("fopen");
		return 0;
	}
	while(!feof(fp)){
		ret = fread(buf, 1, sizeof(buf), fp);
		if(ret > 0){
			for(i = 0; i < ret; i++)buf[i] ^= 0x33; 
			fseek(fp, 0 - ret, SEEK_CUR);
			fwrite(buf, 1, ret, fp);
		}
	}
	fclose(fp);
	return 0;
}