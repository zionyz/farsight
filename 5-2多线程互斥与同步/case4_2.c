#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <pthread.h>

void * thread_a(void * para);
pthread_mutex_t mutex_a;
pthread_mutex_t mutex_b;
int main(int argc, char const *argv[])
{
	pthread_t thid = 0;
	int i = 0;
	pthread_mutex_init(&mutex_a, NULL);
	pthread_mutex_init(&mutex_b, NULL);
	if( 0 != pthread_create(&thid, NULL, thread_a, NULL)){
		perror("pthread_creat");
		return -1;
	}
	
	pthread_mutex_lock(&mutex_b);
	// pthread_mutex_lock(&mutex_a);
	while(1){
		pthread_mutex_lock(&mutex_a);
		printf("*");
		fflush(0);
		pthread_mutex_unlock(&mutex_b);
		if(++i > 1000)break;

	}
	pthread_join(thid, NULL);
	return 0;
}

void * thread_a(void * para)
{
	int i = 0;
	while(1){
		pthread_mutex_lock(&mutex_b);
		printf("-");
		fflush(0);
		pthread_mutex_unlock(&mutex_a);
		if(++i > 1000)break;
	}
	return NULL;	
}