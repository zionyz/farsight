#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

/*ubuntu 系统里面，如果你插入一个U盘，会生成这样的一个文件目录,
可用来检测USB存储设备的插入和拔出*/
int main()
{
	int fd;
	while(1){
		fd = open("/proc/scsi/usb-storage", 0);
		if(fd == -1 && errno == 2){//打开失败，且原因是文件不存在
			usleep(50000);
		}else break;
	}
	printf("you insert a usb storage devices\n");
	close(fd);
	return 0;
}