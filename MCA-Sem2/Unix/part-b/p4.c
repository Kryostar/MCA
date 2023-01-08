// write a program to create a zombie process
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	pid_t child_pid = fork();

	if (child_pid == 0) {
		// This is the child process. Exit immediately.
		return 0;
	}
	else {
		// This is the parent process. Wait for the child to exit,
		// but don't reap the child's status, so that it becomes a zombie.
		sleep(1);
		// Print the child's PID and its status (should be "defunct")
		printf("Child PID: %d\n", child_pid);
		system("ps");
	}
	return 0;
}
