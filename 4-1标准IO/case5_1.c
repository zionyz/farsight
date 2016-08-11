#include <stdio.h>

int main()
{
	char buf[1024];
	int  ret;
	FILE * fp1 = fopen("case5_1", "r");
	FILE * fp2 = fopen("case5_1.cpy", "w");
	if(fp1 == NULL || fp2 == NULL)
	{
		perror("fopen");
		return 0;
	}
	while(!feof(fp1)){
		ret = fread(buf, 1, sizeof(buf), fp1);
		if(ret > 0){
			fwrite(buf, 1, ret, fp2);
		}
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}