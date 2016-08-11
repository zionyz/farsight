#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv)
{
	if(argc != 3){
		printf("usage:\t%s file1 file2\n", argv[0]);
		return 0;
	}
	char buf[1024] ={0};
	int  ret, i;
	FILE * fp1 = fopen(argv[1], "r");
	FILE * fp2 = fopen(argv[2], "w");
	if(fp1 == NULL || fp2 == NULL)
	{
		perror("fopen");
		return 0;
	}
	while(!feof(fp1)){
		ret = fread(buf, 1, sizeof(buf), fp1);
		if(ret > 0){
			for(i = 0; i < ret; i++)buf[i] ^= 0x33; 
			fwrite(buf, 1, ret, fp2);
		}
	}
	return 0;
}