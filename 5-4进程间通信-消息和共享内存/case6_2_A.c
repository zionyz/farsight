#include <stdio.h>
#include <stdio.h>
#include <sys/msg.h>
#include <string.h>

enum{
	OPEN_ACTION,
	LOCK_ACTION
};

typedef struct{
	long mtype;
	int  doorid;
	int  action;
	char mtext[0];
}MSG;

#define msglen sizeof(MSG) - sizeof(long)

int main(int argc, char const *argv[])
{
	if(argc != 3 ){
		printf("usage: %s doorid action\n", argv[0]);
		return -1;
	}
	key_t key;
	int msgid;
	int ret = 0;
	key = ftok(".", 3);
	if((msgid = msgget(key, IPC_CREAT | 0600)) == -1){
		perror("msgget");
		return -1;
	}
	MSG msg;
	msg.mtype = 30;
	msg.doorid = atoi(argv[1]);
	msg.action = atoi(argv[2]);
	ret = msgsnd(msgid, &msg, msglen, 0);
	if(ret > 0){
		printf("send %d bytes in msg queue\n");
	}else{
		perror("msg");
		return -1;
	}

	return 0;
}