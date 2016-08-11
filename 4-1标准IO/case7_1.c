#include <stdio.h>

int main(int argc, char ** argv)
{
	char op;
	float a;
	float b;
	while(1)
	{
		if( 3 == fscanf(fp, "%f %c %f =", &a, &op, &b))
		{
			switch(op){
				case '+':
					printf("%f\n", a+b);
					break;
				case '-':
					printf("%f\n", a-b);
					break;
				case '*':
					printf("%f\n", a*b);
					break;
				case '/':
					printf("%f\n", a/b);
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
	
	return 0;
}