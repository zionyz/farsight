#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



int main(int argc, char const *argv[])
{
	daemon(0, 0);
	char * file_me = NULL;
	char * file_other = NULL;
	char * file_tmp = NULL;
	char  file_1[] = "/tmp/1";
	char  file_2[] = "/tmp/2";
	int   fd;
	int count = 0;
	int status;
	pid_t pid;
	//do something you want as daemon process
	if( 0 != access(file_1, R_OK)){
		file_me = file_1;
		file_other = file_2;
	}else if( 0 != access(file_2, R_OK)){
		file_me = file_2;
		file_other = file_1;
	}else{
		//initial failed!
		return -1;
	}

	while(1){
		if( 0 != access(file_me, R_OK)){
			//printf("file not exist, i creat it\n");
			if(fd = creat(file_me, 0600) < 0){
				perror("creat");
				exit(0);
			}
			close(fd);
			count = 0;
		}else{
			//printf("file exist\n");
			count++;
			if(count > 10){
				count = 0;
				pid = fork();
				if(pid < 0){
					perror("fork");
				}else if(pid == 0){
					daemon(0, 0);
					file_tmp = file_me;
					file_me = file_other;
					file_other = file_tmp;
				}else{
					wait(&status);
				}
			}
		}		
		remove(file_other);
		usleep(1000);
		
	}

	return 0;
}
