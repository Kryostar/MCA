// write a program that illustrates file locking using semaphores
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>

int main() {
	sem_t* sem = sem_open("/my_semaphore", O_CREAT, 0644, 1); // Create a semaphore
	sem_wait(sem); // Lock the semaphore
	FILE* f = fopen("file.txt", "w"); // Open a file
	fprintf(f, "Writing to file...\n"); // Write to the file
	fclose(f); // Close the file
	sem_post(sem); // Unlock the semaphore
	sem_close(sem); // Close the semaphore
	return 0;
}
