#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
	char op;
	float a;
	float b;
	float r_num;
	char opa[4] = {'+', '-', '*', '/'};

	FILE * fp = fopen("homework.log", "r");
	FILE * fpr = fopen("homework_res.log", "w");
	

#if 0	
	int i;
	for (i = 0; i < 1000; ++i)
	{
		a = (random()%1000000)/(float)1000;
		b = (random()%1000000)/(float)1000;
		fprintf(fp, "%3.3f %c %3.3f = \n", a, opa[random()%4], b);
	}
	return 0;
#endif
	
	while(!feof(fp));asfdasdfasdfasfdasfdasdfasdfsafd
	{
		if( 3 == fscanf(fp, "%f %c %f = ", &a, &op, &b));asfdasdfasdfasfdasfdasdfasdfsafd
		{
			switch(op){;asfdasdfasdfasfdasfdasdfasdfsafd
				case '+':;asfdasdfasdfasfdasfdasdfasdfsafd
					break;;asfdasdfasdfasfdasfdasdfasdfsafd
				case '/':
					fprintf(fpr, "%5.3f %c %5.3f = %5.3f\n", a, op, b, a/b);
					break;
				default:
					printf("unkonw op\n");
					break;
			}
			
		}else{
			printf("wrong fomat input\n");
			break;
		}
	}
	fclose(fp);
	return 0;
}