#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];  // The shared buffer
int fill_ptr = 0;  // The index of the next item to be produced
int use_ptr = 0;  // The index of the next item to be consumed
int count = 0;  // The number of items in the buffer

sem_t empty;  // Semaphore to track the number of empty slots
sem_t full;   // Semaphore to track the number of full slots
pthread_mutex_t mutex;  // Mutex to protect shared variables

// The producer thread
void* producer(void* arg) {
	while (1) {
		sem_wait(&empty);  // Decrement the number of empty slots
		pthread_mutex_lock(&mutex);  // Acquire the mutex

		// Produce an item and add it to the buffer
		buffer[fill_ptr] = rand();
		fill_ptr = (fill_ptr + 1) % BUFFER_SIZE;
		count++;

		pthread_mutex_unlock(&mutex);  // Release the mutex
		sem_post(&full);  // Increment the number of full slots
	}
	return NULL;
}

// The consumer thread
void* consumer(void* arg) {
	while (1) {
		sem_wait(&full);  // Decrement the number of full slots
		pthread_mutex_lock(&mutex);  // Acquire the mutex

		// Consume an item and remove it from the buffer
		int item = buffer[use_ptr];
		use_ptr = (use_ptr + 1) % BUFFER_SIZE;
		count--;

		pthread_mutex_unlock(&mutex);  // Release the mutex
		sem_post(&empty);  // Increment the number of empty slots
	}
	return NULL;
}

int main(int argc, char* argv[]) {
	// Initialize the semaphores and mutex
	/* `sem_init` initializes the semaphore. */
	sem_init(&empty, 0, BUFFER_SIZE);
	sem_init(&full, 0, 0);
	pthread_mutex_init(&mutex, NULL);

	// Create the producer and consumer threads
	pthread_t producer_thread, consumer_thread;
	pthread_create(&producer_thread, NULL, producer, NULL);
	pthread_create(&consumer_thread, NULL, consumer, NULL);

	// Wait for the threads to finish
	pthread_join(producer_thread, NULL);
	pthread_join(consumer_thread, NULL);

	// Destroy the semaphores and mutex
	sem_destroy(&empty);
	sem_destroy(&full);
	pthread_mutex_destroy(&mutex);

	return 0;
}