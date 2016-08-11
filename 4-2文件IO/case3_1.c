#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	unsigned char buf[256] = {0};
	int i = 0, ret;
	int fd;	
	fd = open("newfile3_1", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if(fd == -1 ){
		perror("open");
		return 0;
	}
	printf("creat file ok\n");
	while(i < 0x100){
		//buf[i] = i++; buf[i++] = i;均是不正确的，思考下为什么？
		buf[i] = i;
		i++;
	}
	ret = write(fd, buf, sizeof(buf));
	if(sizeof(buf) == ret)printf("write file ok\n");
	else {
		printf("need write again\n");
		ret = write(fd, buf + ret, sizeof(buf) - ret);
	}
	close(fd);
	return 0;
	/*可使用命令hd newfile3_1查看写入是否正确 */
}