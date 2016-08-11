#include <stdio.h>
#include <sys/sem.h>


int main(int argc, char const *argv[])
{
	key_t key = 91;
	int semid;
	if((semid = semget(key, 1, 0600)) == -1){
		if((semid = semget(key, 1, IPC_CREAT | 0600)) == -1){
			perror("semget");
			return -1;
		}else{
			semctl(semid, 0, SETVAL, 1);
		}
	}
	struct sembuf sops[1];
	sops[0].sem_num = 0;
	sops[0].sem_op = -1;
	sops[0].sem_flg = SEM_UNDO | IPC_NOWAIT;

	if( -1 == semop(semid, sops, 1)){
		printf("already has a process\n");
	}else{
		sleep(5);
	}
	
	return 0;
}