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
	key_t key;
	int msgid;
	int ret = 0;
	key = ftok(".", 3);
	if((msgid = msgget(key, IPC_CREAT | 0600)) == -1){
		perror("msgget");
		return -1;
	}
	MSG msg;
	while(1){
		ret = msgrcv(msgid, &msg, msglen, 30, 0);
		if(ret > 0){
			printf("recv %d bytes from msg queue\n%s\n", ret, msg.mtext);
		}else{
			perror("msg");
			return -1;
		}
	}
	

	return 0;
}