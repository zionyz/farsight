#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>


void * thread_a(void * para);


int main(int argc, char const *argv[])
{
	int i = 0;
	pthread_t thid;
	int count = 1000;
	while(i++ < count){
		if(0 != pthread_create(&thid, NULL, thread_a, NULL)){
			perror("pthread_creat");
			return -1;
		}
		printf("%d\n", thid);
		usleep(100000);
	}	
	return 0;
}

void * thread_a(void * para)
{
	pthread_detach(pthread_self());
	printf("new thread! %d\n", pthread_self());
	return NULL;	
}