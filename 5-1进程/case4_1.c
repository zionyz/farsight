#include <stdio.h>
#include <unistd.h>

#define USE_EXECVP 1


int main(int argc, char const *argv[])
{
	int ret;

#if USE_EXECVP	
	char *parav[4] = {0};
	char para1[] = "ls";
	char para2[] = "-l";
	char para3[] = "-t";
	parav[0] = para1;
	parav[1] = para2;
	parav[2] = para3;
	printf("use execvp\n");
	ret = execvp("ls", parav);
#else
	printf("use execlp\n");
	ret = execlp("ls", "ls", "-l", "-t", NULL);	
#endif	
	
	perror("execlp");
	return 0;
}