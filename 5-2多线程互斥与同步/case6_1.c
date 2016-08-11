#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>

int fd;
void * thread_a(void * para);
//pthread_mutex_t mutex;
sem_t sem;

int main(int argc, char const *argv[])
{
	pthread_t thid = 0;
	int i = 0;
	fd = open("testfile", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if(fd < 0){
		perror("open");
		return -1;
	}
	//pthread_mutex_init(&mutex, NULL);
	sem_init(&sem, 0, 1);
	if( 0 != pthread_create(&thid, NULL, thread_a, NULL)){
		perror("pthread_creat");
		return -1;
	}
	while(1){
		//pthread_mutex_lock(&mutex);
		sem_wait(&sem);
		lseek(fd, i+1, SEEK_SET);
		if( 1 != write(fd, ".", 1)){
			perror("write");
		}
		//pthread_mutex_unlock(&mutex);
		sem_post(&sem);
		i += 2;
		if(i > 1000)break;
	}
	pthread_join(thid, NULL);
	return 0;
}

void * thread_a(void * para)
{
	int i = 0;
	while(1){
		//pthread_mutex_lock(&mutex);
		sem_wait(&sem);
		lseek(fd, i, SEEK_SET);
		if( 1 != write(fd, "*", 1)){
			perror("write");
		}
		//pthread_mutex_unlock(&mutex);
		sem_post(&sem);
		i += 2;
		if(i > 1000)break;
	}
	return NULL;	
}
