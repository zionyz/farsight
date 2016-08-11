#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <pthread.h>


void * thread_a(void * para);
int main(int argc, char const *argv[])
{
	pthread_t thid = 0;
	int i = 0;
	if( 0 != pthread_create(&thid, NULL, thread_a, NULL)){
		perror("pthread_creat");
		return -1;
	}
	
	while(1){
		printf("*");
		fflush(0);
		if(++i > 100)break;
	}
	pthread_join(thid, NULL);
	return 0;
}

void fun()
{
	int i = 0;
	while(1){
		printf("-");
		fflush(0);
		if(++i > 1000)break;
	}
	pthread_exit(0);
}
void * thread_a(void * para)
{	
	fun();
	printf("thread_a return!\n");
	return NULL;	
}


