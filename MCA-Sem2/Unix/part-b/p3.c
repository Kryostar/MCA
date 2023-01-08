#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const* argv[])
{
	system("clear");
	int pid = fork();
	if (pid < 0) {
		exit(1);
	}
	if (pid == 0) {
		printf("Child Process, PID:%d\nParent's PID:%d\n", getpid(), getppid());
		exit(0);
	}
	else {
		sleep(1);
		printf("Parent Process, PID:%d\nChild's PID:%d\n", getpid(), pid);
		system("ps");
		exit(0);
	}
	return 0;
}

