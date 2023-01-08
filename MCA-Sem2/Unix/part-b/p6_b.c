#include <stdio.h>
#include <stdlib.h>

#define NUM_PROCESSES 5

// A structure to represent a process
typedef struct {
	int id;
	int burst_time;
} process_t;

// Compare function for qsort()
int compare(const void* a, const void* b) {
	process_t* p1 = (process_t*)a;
	process_t* p2 = (process_t*)b;
	return p1->burst_time - p2->burst_time;
}

int main(int argc, char* argv[]) {
	// Create an array of processes
	process_t processes[NUM_PROCESSES] = {
		{1, 6}, {2, 8}, {3, 7}, {4, 3}, {5, 4}
	};

	// Sort the processes by burst time
	qsort(processes, NUM_PROCESSES, sizeof(process_t), compare);

	// Print the schedule
	printf("Process ID\tBurst Time\n");
	for (int i = 0; i < NUM_PROCESSES; i++) {
		printf("%d\t\t%d\n", processes[i].id, processes[i].burst_time);
	}

	return 0;
}
