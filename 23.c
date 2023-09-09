#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	pid_t child_pid=fork();

	if(child_pid==-1){
		perror("Fork has failed");
		return -1;
	}
	if(child_pid==0){
		printf("Child process , PID: %d\n",getpid());
		exit(0);
	}
	else{
		printf("Parent Process , PID: %d , Child process , PID is %d\n",getpid(),child_pid);
		sleep(10);
		printf("Parent is exiting, PID: %d\n",getpid());
	}
	return 0;

}

