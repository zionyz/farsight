#include <stdio.h>
#include <stdio.h>
#include <sys/msg.h>

int main(int argc, char const *argv[])
{
	system("ipcs -q");
	key_t key;
	int msgid;
	key = ftok(".", 3);
	if((msgid = msgget(key, IPC_CREAT | 0600)) == -1){
		perror("msgget");
		return -1;
	}else {
		printf("msgget ok\n");
	}
	system("ipcs -q");
	return 0;
}