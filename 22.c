#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(){
	int fd=open("output.txt",O_CREAT | O_RDWR | O_TRUNC, 0666);

	if(fd==-1){
		perror("failed to open the file");
		return -1;
	}

	pid_t pid=fork();
	if(pid==-1){
		perror("Can't fork");
		return -1;
	}
	const char* msg;
	if(pid==0){
		msg="Child is here\n";
		write(fd,msg,strlen(msg));
	}
	else{
		msg="parent is here\n";
		write(fd,msg,strlen(msg));

		wait(NULL);
	}
	close(fd);
	return 1;

}

