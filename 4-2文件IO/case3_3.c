#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	if(argc != 2){
		printf("usage: %s ttynum\n", argv[0]);
		return -1;
	}
	int ttynum = atoi(argv[1]);
	char ttyname[128];
	char buf[1024] = {0};
	sprintf(ttyname, "/dev/pts/%d", ttynum);
	int fd = open(ttyname, O_WRONLY);
	if(fd == -1){
		perror("open");
		return -1;
	}

	while(1){
		fgets(buf, sizeof(buf), stdin);
		if(!strcmp(buf, "quit\n"))break;
		write(fd, buf, strlen(buf));
	}
	return 0;
}