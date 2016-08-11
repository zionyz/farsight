#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <pthread.h>

int fd;
void * thread_a(void * para);
int main(int argc, char const *argv[])
{
	pthread_t thid = 0;
	int i = 0;
	fd = open("testfile", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if(fd < 0){
		perror("open");
		return -1;
	}
	if( 0 != pthread_create(&thid, NULL, thread_a, NULL)){
		perror("pthread_creat");
		return -1;
	}
	//sleep(1);
	while(1){
		lseek(fd, i+1, SEEK_SET);
		if( 1 != write(fd, ".", 1)){
			perror("write");
		}
		i += 2;
		if(i > 1024)break;
	}
	sleep(3);
	//pthread_join(thid, NULL);
	return 0;
}

void * thread_a(void * para)
{
	int i = 0;
	while(1){
		lseek(fd, i, SEEK_SET);
		if( 1 != write(fd, "*", 1)){
			perror("write");
		}
		i += 2;
		if(i > 1024)break;
	}
	
}