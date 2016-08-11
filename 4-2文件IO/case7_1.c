#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>



int main(int argc, char const *argv[])
{
	int fd;	
	DIR * dir;
	struct dirent * lpdir;
	if(argc != 2){
		printf("list dir content\nusage:\t%s, directory", argv[1]);
		return 0;
	}
	dir = opendir(argv[1]);
	if(dir == NULL){
		perror("opendir");
		return 0;
	}
	lpdir = readdir(dir);
	while(lpdir){
		printf("%s\n", lpdir->d_name);
		lpdir = readdir(dir);
	}
	closedir(dir);
	return 0;
}	