#include <unistd.h>
#include <stdio.h>
#include <sys/shm.h>

int main(int argc, char const *argv[])
{
	system("ipcs -m");
	key_t key;
	int shmid;
	key = ftok(".", 3);
	if((shmid = shmget(key, 1024, IPC_CREAT | 0600)) == -1){
		perror("shmget");
		return -1;
	}else {
		printf("shmget ok\n");
	}
	system("ipcs -m");
	return 0;
}