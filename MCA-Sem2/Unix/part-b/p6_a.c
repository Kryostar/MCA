// Round robin
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 10
#define MAX_TIME_SLICE 10

typedef struct {
	char name[32];
	int arrival_time;
	int burst_time;
	int priority;
} Process;

int compare_processes(const void* a, const void* b) {
	const Process* p1 = (const Process*)a;
	const Process* p2 = (const Process*)b;
	if (p1->arrival_time != p2->arrival_time) {
		return p1->arrival_time - p2->arrival_time;
	}
	else {
		return p1->priority - p2->priority;
	}
}

void simulate_round_robin(Process* processes, int num_processes) {
	// Sort the processes by arrival time and priority
	qsort(processes, num_processes, sizeof(Process), compare_processes);

	// Initialize the time and current process
	int time = 0;
	int current_process = 0;

	// Loop until all processes have completed
	while (current_process < num_processes) {
		Process* p = &processes[current_process];
		printf("Running process %s at time %d with priority %d\n", p->name, time, p->priority);

		// Update the burst time and check if the process has completed
		p->burst_time -= MAX_TIME_SLICE;
		if (p->burst_time <= 0) {
			printf("Completed process %s at time %d\n", p->name, time + MAX_TIME_SLICE);
			current_process++;
		}

		// Move to the next process
		time += MAX_TIME_SLICE;
		current_process = (current_process + 1) % num_processes;
	}
}

int main() {
	// Create some test processes
	Process processes[] = {
		{"p1", 0, 20, 3},
		{"p2", 0, 10, 1},
		{"p3", 5, 15, 4},
		{"p4", 10, 5, 2},
		{"p5", 20, 10, 5},
	};
	int num_processes = sizeof(processes) / sizeof(Process);

	// Simulate the round-robin scheduling algorithm
	simulate_round_robin(processes, num_processes);

	return 0;
}
