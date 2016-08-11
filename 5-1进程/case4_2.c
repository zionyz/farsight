#include <stdio.h>
#include <unistd.h>



int main(int argc, char const *argv[])
{
	int ret;
	sleep(10);
	ret = execlp("sol", "sol", "--freecell", NULL);	
	perror("execlp");
	return 0;
}