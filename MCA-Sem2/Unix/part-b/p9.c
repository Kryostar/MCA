#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024  /* make it a 1K shared memory segment */

int main() {
	// Create a key for the shared memory segment
	key_t key = ftok("shmfile", 65);

	// Create the shared memory segment
	int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);

	// Attach the shared memory segment to the current process
	char* str = (char*)shmat(shmid, (void*)0, 0);

	// If this is the parent process
	if (fork() == 0) {
		// Write a message to the shared memory
		strcpy(str, "Hello, world!");
	}
	// If this is the child process
	else {
		// Wait for the parent process to write to the shared memory
		sleep(1);

		// Read the message from the shared memory
		printf("Child process received: %s\n", str);

		// Detach the shared memory segment from the current process
		shmdt(str);

		// Remove the shared memory segment
		shmctl(shmid, IPC_RMID, NULL);
	}

	return 0;
}
