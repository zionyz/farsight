#include <stdio.h>


int main(int argc, char ** argv)
{
	char c;
	int i;
	int  readpoint[4] = {1,2,3,100};
	
	FILE * fp = fopen(argv[0], "r");
	if(fp == NULL )
	{
		perror("fopen");
		return 0;
	}
	for(i = 0; i < sizeof(readpoint)/sizeof(int); i++){
		fseek(fp, readpoint[i], SEEK_SET);
		fread(&c, 1, 1, fp);
		printf("char at [%3d] in [%s] is [%x]\n", ftell(fp) - 1, argv[0], c);
	}
	fseek(fp, -1, SEEK_END);
	fread(&c, 1, 1, fp);
	printf("char at [%3d] in [%s] is [%x]\n", ftell(fp) - 1, argv[0], c);
	fclose(fp);
}