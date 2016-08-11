#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <pthread.h>
#include <string.h>

static int flags = 0;
void * thread_a(void * para);
int main(int argc, char const *argv[])
{
	pthread_t thid = 0;
	time_t start, now;
	if( 0 != pthread_create(&thid, NULL, thread_a, NULL)){
		perror("pthread_creat");
		return -1;
	}
	time(&start);
	while(1){
		time(&now);
		if(now - start > 10){
			printf("都老了，没戏了！\n");
			break;
		}else if(flags == 1){
			printf("结婚吧，生娃吧！\n");
			break;
		}
	}
	return 0;
}

void * thread_a(void * para)
{
	char buf[1024];
	
	while(1){
		fgets(buf, sizeof(buf), stdin);
		if(!strcmp(buf, "I love you!\n")){
			flags = 1;
			break;
		}
	}
	return NULL;	
}