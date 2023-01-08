#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_MESSAGE_LENGTH 256

// A structure to represent a message
typedef struct {
	long type;
	char text[MAX_MESSAGE_LENGTH];
} message_t;

int main(int argc, char* argv[]) {
	// Create a message queue
	int msgid = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);
	if (msgid == -1) {
		perror("msgget");
		exit(EXIT_FAILURE);
	}

	// Send a message
	message_t message;
	message.type = 1;
	strcpy(message.text, "Hello, world!");
	if (msgsnd(msgid, &message, sizeof(message_t) - sizeof(long), 0) == -1) {
		perror("msgsnd");
		exit(EXIT_FAILURE);
	}

	// Receive a message
	if (msgrcv(msgid, &message, sizeof(message_t) - sizeof(long), 0, 0) == -1) {
		perror("msgrcv");
		exit(EXIT_FAILURE);
	}
	printf("Received: %s\n", message.text);

	// Destroy the message queue
	if (msgctl(msgid, IPC_RMID, NULL) == -1) {
		perror("msgctl");
		exit(EXIT_FAILURE);
	}

	return 0;
}