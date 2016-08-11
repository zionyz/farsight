#include <stdio.h>
#include <time.h>


int main()
{
	char buf[1024] = "i love you, Lady Gaga\n";
	int c;
	time_t start, now;

	int line = 0;
	FILE * fp = fopen("biaobai.ppp", "w+");
	time(&start);
	time(&now);
	while(now - start < 5){
		time(&now);
		fputs(buf, fp);
	}
	rewind(fp);
	while(fgets(buf, sizeof(buf), fp) != NULL)line++;
	printf("line = %d\n", line);
	fclose(fp);	
}


