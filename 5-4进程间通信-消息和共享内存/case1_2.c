#include <unistd.h>
#include <stdio.h>
#include <sys/shm.h>

int main(int argc, char const *argv[])
{
	key_t key;
	int shmid;
	key = ftok(".", 3);
	printf("before ipcrm\n");
	if((shmid = shmget(key, 0, 0)) == -1){
		printf("the shm is not exist\n");
		return -1;
	}else {
		printf("the shm is exist\n");
		printf("atfer ipcrm\n");
		char cmd[128];
		sprintf(cmd, "ipcrm -m %d", shmid);
		system(cmd);
		execl(argv[0], argv[0], NULL);
	}
	return 0;
}