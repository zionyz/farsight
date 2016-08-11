#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


void change_to_daemon();

int main(int argc, char const *argv[])
{
	change_to_daemon();
	//do something you want as daemon process
	sleep(100);
	return 0;
}

void change_to_daemon()
{
	pid_t pid;
	int i;
	pid = fork();
	if(pid > 0){
		exit(0);
	}

	setsid();

	umask(0);

	chdir("/tmp");

	for (i = 0; i < getdtablesize(); ++i)
	{
		close(i);
	}
	return;
}