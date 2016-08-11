#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <linux/input.h>

int main(int argc, char const *argv[])
{
	int ret;
	struct input_event st_key_input;
	int fd = open("key_record.log", O_RDONLY);
	int fd_event0 = open("/dev/input/event0", O_WRONLY);
	if(fd < 0 || fd_event0 < 0)
	{
		perror("open");
		return;
	}
	sleep(10);
	printf("playback!!!\n");
	while(1)
	{
		usleep(5000);
		ret = read(fd, &st_key_input, sizeof(struct input_event));
		if( ret > 0 ){
			ret = write(fd_event0, &st_key_input, ret);
		}else{
			break;			
		}
	}
	printf("playback end!\n");
	close(fd);
	close(fd_event0);
}	