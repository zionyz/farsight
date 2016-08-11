#include <stdio.h>
#include <stdio.h>
#include <sys/msg.h>
#include <string.h>

typedef struct{
	long mtype;
	char mtext[128];
}MSG;
#define msglen sizeof(MSG) - sizeof(long)

int main(int argc, char const *argv[])
{
	if(argc != 2 || strlen(argv[1]) > 127){
		printf("usage: %s msg\n", argv[0]);
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
	strcpy(msg.mtext, argv[1]);
	ret = msgsnd(msgid, &msg, msglen, 0);
	if(ret > 0){
		printf("send %d bytes in msg queue\n");
	}else{
		perror("msg");
		return -1;
	}

	return 0;
}