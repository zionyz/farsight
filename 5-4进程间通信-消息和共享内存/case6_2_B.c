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
			switch(msg.action){
				case OPEN_ACTION:
					printf("open the door (%d)\n", msg.doorid);
					break;
				case LOCK_ACTION:
					printf("lock the door (%d)\n", msg.doorid);
					break;
				default:
					printf("unknowed cmd!\n");
					break;
			}
		}else{
			perror("msg");
			return -1;
		}
	}
	

	return 0;
}