#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <pthread.h>
#include <string.h>

static int flags = 0;

int main(int argc, char const *argv[])
{
	time_t start, now;
	char buf[1024];

	int flag = fcntl(0, F_GETFL, 0);
    flag |= O_NONBLOCK;
    if (fcntl(0, F_SETFL, flag) < 0) {      /* fgets no-block now */
        perror("fcntl");
        return -1;
    }

	time(&start);
	while(1){
		time(&now);
		if(now - start > 10){
			printf("都老了，没戏了！\n");
			break;
		}else if(flags == 1){
			printf("结婚吧，生娃吧！\n");
			break;
		}

		fgets(buf, sizeof(buf), stdin);
		if(!strcmp(buf, "I love you!\n")){
			flags = 1;
		}
	}
	return 0;
}
