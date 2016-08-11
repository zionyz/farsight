#include <stdio.h>
#include <unistd.h>

int main()
{
	int c;
	FILE * fp = fopen("case2.ppp", "r");
	if(fp == NULL){
		perror("fopen");
		return -1;
	}
	while((c = fgetc(fp)) != EOF){
		printf("%c", c);
		usleep(5000);
	}
	fclose(fp);	
	return 0;
}