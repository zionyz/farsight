#include <unistd.h>
#include <stdio.h>
#include <sys/shm.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char * msg;
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
	strcpy(msg, "this is a message from shm");
	shmdt(msg);
	return 0;
}