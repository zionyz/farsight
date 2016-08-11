#include <stdio.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char const *argv[])
{
	if(argc != 2 || strlen(argv[1]) > 510){
		printf("usage:\t%s code.c\n", argv[0]);
		return 0;
	}

	int ret;
	int status;
	pid_t pid;
	char elfname[512] = "./";
	strcat(elfname, argv[1]);
	strtok(elfname + 2, ".");
	if( 0 == access(elfname, R_OK) ){
		remove(elfname);
	}

	pid = fork();
	if(pid < 0){
		perror("fork");
		return -1;
	}else if(pid == 0){
		printf("gcc...\n");
		execlp("gcc", "gcc", argv[1], "-o", elfname, NULL);
	}else{
		wait(&status);
		printf("gcc ok\n");
		if( 0 != access(elfname, R_OK) ){
			printf("%s is not exist\n", elfname);
			return -1;
		}
		execlp(elfname, elfname, NULL);
		perror("execlp");
	}
	
	return 0;
}