#include <stdio.h>
#include <time.h>


int main()
{
	char buf[1024] = "";
	int line = 0;
	FILE * fp1 = fopen("biaobai.ppp", "r");
	FILE * fp2 = fopen("biaobai.cpy", "w");
	if(fp1 == NULL || fp2 == NULL)
	{
		perror("fopen");
		return -1;
	}
	while(fgets(buf, sizeof(buf), fp1) != NULL){
		fputs(buf, fp2);
	}
	fclose(fp1);
	fclose(fp2);	
	return 0;
}


