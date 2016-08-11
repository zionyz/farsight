#include <stdio.h>
#include <unistd.h>

int main()
{
	int c;
	int len = 0;
	FILE * fp = fopen("case2.ppp", "r");
	if(fp == NULL){
		perror("fopen");
		return 0;
	}
	while((c = fgetc(fp)) != EOF){
		printf("%c", c);
		fflush(stdout);
		//fflush(0);
		usleep(5000);
	}
	fclose(fp);	
}