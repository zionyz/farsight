#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <string.h>

int gethwname(char * buf, char * hwname, int hwname_size);

int main(int argc, char const *argv[])
{
	int fd[2];
	pid_t pid;
	int ret;
	char buf[1024] = "";
	char hwname[64];
	int status;

	if(-1 == pipe(fd)){
		perror("pipe");
		return -1;
	}
	pid = fork();
	if(pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		execlp("ifconfig", "ifconfig", NULL);
		perror("execlp");
	}else if(pid > 0){
		wait(NULL);
		ret = read(fd[0], buf, sizeof(buf));
		if(ret > 0){
			if(0 == gethwname(buf, hwname, sizeof(hwname))){
				pid = fork();
				if(pid == 0)
				{
					dup2(fd[1], STDOUT_FILENO);
					//dup2(fd[1], STDERR_FILENO);
					execlp("ifconfig", "ifconfig", hwname, "192.168.15.7", "netmask", "255.255.255.0", NULL);
					perror("execlp");
				}else if(pid > 0){
					wait(&status);
					if(status == 0)printf("set ok\n");
					else {
						printf("set failed\n");
					}
				}
			}else{
				printf("can't find eth interface name!\n");
				return -1;
			}
		}
	}else{
		perror("fork");
		return -1;
	}
	return 0;
}

int gethwname(char * buf, char * hwname, int hwname_size)
{
	char * lptemp = buf;
	char hwtype[128] = "";
	while(lptemp != NULL && lptemp  < buf + strlen(buf)){	
		bzero(hwname, hwname_size);
		sscanf(lptemp, "%s      Link encap:%s", hwname, hwtype);
		if(!strcmp(hwtype, "以太网")){
			printf("%s\n", hwname);
			return 0;
		}
		lptemp = strstr(lptemp + 2, "\n\n");

	}
	return -1;
}

