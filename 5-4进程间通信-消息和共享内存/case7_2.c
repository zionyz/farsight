#include <stdio.h>
#include <unistd.h>
#include <sys/msg.h>

typedef struct {
	long mtype;
	char mtext[128];
}MSG;

#define MSGLEN sizeof(MSG) - sizeof(long)

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
	msg.mtype = 30;
	struct msqid_ds msg_info;
	int i;
	for (i = 0; i < 10; ++i)
	{
		if(-1 == msgsnd(msgid, &msg, MSGLEN, 0)){
			perror("msgsnd");
			return -1;
		}
	}
	msgctl(msgid, IPC_STAT, &msg_info);
	printf("total %d msg in msgq\n", msg_info.msg_qnum);
	msgctl(msgid, IPC_RMID, NULL);
	system("ipcs -q");
	
	return 0;
}