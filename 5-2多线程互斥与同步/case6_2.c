#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

void * encrypt_thread( void * para);
sem_t sem;

int main(int argc, char const *argv[])
{
	pthread_t thid;
	sem_init(&sem, 0, 5);
	int i = 0;
	char * filename;

	while(1){
		sem_wait(&sem);
		filename = calloc(1, 512);
		sprintf(filename, "file_%d.log", i++);
		if( 0 != pthread_create(&thid, NULL, encrypt_thread, filename)){
			perror("pthread_create");
			return -1;
		}	
	}
	return 0;
}

void * encrypt_thread( void * para)
{
	char * filename = para;
	printf("encrypt: %s\n", filename);
	//do something
	sleep(1);
	free(filename);
	sem_post(&sem);
	return NULL;
}