#include <stdio.h>
/*
注意：
	如果用char类型接收fgetc的返回值，就无法用返回值是否等于EOF的逻辑判断文件是否结束
*/
int main()
{

	int c;
	int i = 0;
	FILE * fp = fopen("case2.ppp", "r");
	FILE * fpcpy = fopen("case2.cpy", "w");
	if(fp == NULL || fpcpy == NULL){
		perror("fopen");
		return -1;
	}

	while((c = fgetc(fp)) != EOF){
		fputc(c, fpcpy);
	}
	// while(i++ < 1000){
	// 	c = fgetc(fp);
	// 	fputc(c, fpcpy);
	// }
	
	fclose(fp);
	fclose(fpcpy);
	return 0;
}