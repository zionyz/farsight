#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>

void copyfile(char * fname1, char * fname2, int mode);

int main(int argc, char const *argv[])
{
	struct stat st_stat;
	unsigned char newfilename[1024];
	DIR * dir;
	struct dirent * lpdir;
	if(argc != 3){
		printf("copy directory \nusage:\t%s, dir1 dir2 ", argv[0]);
		return 0;
	}
	dir = opendir(argv[1]);
	if(dir == NULL){
		perror("opendir");
		return 0;
	}
	mkdir(argv[2], 0777);

	lpdir = readdir(dir);
	while(lpdir){
		sprintf(newfilename, "%s/%s", argv[2], lpdir->d_name);
		stat(lpdir->d_name, &st_stat);
		copyfile(lpdir->d_name, newfilename, st_stat.st_mode & 0777);
		lpdir = readdir(dir);
	}
	closedir(dir);
	return 0;
}	


void copyfile(char * fname1, char * fname2, int mode)
{
	int fd1;
	int fd2;
	int ret;
	char buf[1024];
	fd1 = open(fname1, O_RDONLY | O_EXCL);
	fd2 = open(fname2, O_CREAT | O_WRONLY, mode);
	if(fd1 < 0 || fd2 < 0){
		perror("open");
		return;
	}
	while((ret = read(fd1, buf, sizeof(buf))) > 0){
		write(fd2, buf, ret);
	}
	close(fd1);
	close(fd2);
	return;
}