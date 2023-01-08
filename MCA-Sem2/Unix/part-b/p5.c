#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 100

int main(int argc, char* argv[]) {
	int fd[2];  // File descriptor for the pipe
	pid_t pid;  // Process ID
	char buffer[BUFFER_SIZE];

	// Create the pipe
	pipe(fd);

	// Create a child process
	pid = fork();

	if (pid == 0) {  // Child process
		// Write to the write end of the pipe
		strcpy(buffer, "Hello, world!");
		write(fd[1], buffer, strlen(buffer) + 1);
	}
	else {  // Parent process
		// Read from the read end of the pipe
		read(fd[0], buffer, BUFFER_SIZE);
		printf("Received: %s\n", buffer);
	}

	return 0;
}