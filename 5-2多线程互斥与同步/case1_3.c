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
	int count = 50;
	if( 0 != pthread_create(&thid, NULL, thread_a, &count)){
		perror("pthread_creat");
		return -1;
	}
	
	while(1){
		printf("*");
		fflush(0);
		if(++i > 100)break;
	}
	sleep(3);
	//pthread_join(thid, NULL);
	return 0;
}

void * thread_a(void * para)
{
	int i = 0;
	int count = *(int *)para;
	while(1){
		printf("-");
		fflush(0);
		if(++i > count)break;
	}
	return NULL;	
}