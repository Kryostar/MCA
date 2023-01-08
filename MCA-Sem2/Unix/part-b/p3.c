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
	else if (pid == 0) {
		printf("Child Process, PID: %d\n", getpid());
		exit(0);
	}
	else {
		printf("Parent Process, PID: %d\n", getpid());
		exit(0);
	}
	return 0;
}

