#include <unistd.h>
#include <stdio.h>
#include <sys/shm.h>
#include <signal.h>


char * msg;

void fun()
{
	printf("%s\n", msg);
}

int main(int argc, char const *argv[])
{
	
	key_t key;
	int shmid;
	key = ftok(".", 3);
	if((shmid = shmget(key, 1024, IPC_CREAT | 0600)) == -1){
		perror("shmget");
		return -1;
	}
	msg = shmat(shmid, 0, 0);
	if(msg == NULL){
		perror("shmat");
		return -1;
	}
	signal(SIGUSR1, fun);
	while(1){
		pause();
	}
	return 0;
}