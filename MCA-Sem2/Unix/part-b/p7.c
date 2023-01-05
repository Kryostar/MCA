// write a program that illustrates file locking using semaphores
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>

int main() {
	// Create a semaphore
	sem_t* sem = sem_open("/my_semaphore", O_CREAT, 0644, 1);

	// Lock the semaphore
	sem_wait(sem);

	// Open a file
	FILE* f = fopen("file.txt", "w");

	// Write to the file
	fprintf(f, "Writing to file...\n");

	// Close the file
	fclose(f);

	// Unlock the semaphore
	sem_post(sem);

	// Close the semaphore
	sem_close(sem);

	return 0;
}
