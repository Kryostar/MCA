#include <stdio.h>
#include <stdlib.h>

// Data structure to represent a queue
struct queue
{
	int* items;     // array to store queue elements
	int maxsize;    // maximum capacity of the queue
	int front;      // front points to the front element in the queue (if any)
	int rear;       // rear points to the last element in the queue
	int size;       // current capacity of the queue
};

// Utility function to initialize a queue
/**
 * It creates a new queue with a given size.
 * 
 * @param size The size of the queue.
 * 
 * @return A pointer to a queue.
 */
struct queue* newQueue(int size)
{
	struct queue* pt = NULL;
	pt = (struct queue*)malloc(sizeof(struct queue));
	pt->items = (int*)malloc(size * sizeof(int));
	pt->maxsize = size;
	pt->front = 0;
	pt->rear = -1;
	pt->size = 0;
	return pt;
}

// Utility function to return the size of the queue
int size(struct queue* pt) {
	return pt->size;
}

// Utility function to check if the queue is empty or not
int isEmpty(struct queue* pt) {
	return !size(pt);
}

// Utility function to return the front element of the queue
int front(struct queue* pt)
{
	if (isEmpty(pt))
	{
		printf("Underflow\n");
		//exit(EXIT_FAILURE);
		return;
	}

	return pt->items[pt->front];
}
int rear(struct queue* pt)
{
	return pt->items[pt->rear];
}

// Utility function to add an element `x` to the queue
void enqueue(struct queue* pt, int x)
{
	if (size(pt) == pt->maxsize)
	{
		printf("Overflow\n");
		// exit(EXIT_FAILURE);
		return;
	}

	printf("Inserting %d\t", x);

	pt->rear = (pt->rear + 1) % pt->maxsize;    // circular queue
	pt->items[pt->rear] = x;
	pt->size++;

	printf("front = %d, rear = %d\n", pt->front, pt->rear);
}

// Utility function to dequeue the front element
int dequeue(struct queue* pt)
{
	if (isEmpty(pt))    // front == rear
	{
		printf("Underflow\n");
		// exit(EXIT_FAILURE);
		return;
	}

	printf("Removing %d\t", front(pt));

	pt->front = (pt->front + 1) % pt->maxsize;  // circular queue
	pt->size--;

	printf("front = %d, rear = %d\n", pt->front, pt->rear);
}

void main()
{
	system("cls");
	int s, ch, data;
	printf("Enter the size of Queue: ");
	scanf("%d", &s);
	struct queue* pt = newQueue(s);
	do {
		printf("1.enqueue\n2.dequeue\n3.size\n4.front\n5.rear\n0.exit\nEnter choice: ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			system("cls");
			printf("Enter element to be enqueued: ");
			scanf("%d", &data);
			enqueue(pt, data);
			break;
		case 2:
			system("cls");
			dequeue(pt);
			break;
		case 3:
			system("cls");
			printf("Size of Queue is %d\n", size(pt));
			break;
		case 4:
			system("cls");
			printf("Front: %d\n", front(pt));
			break;
		case 5:
			system("cls");
			printf("Rear: %d\n", rear(pt));
			break;
		case 0:
			system("cls");
			printf("** EXIT! **");
			break;
		default:
			system("cls");
			printf("** Error! **\n");
		}
	} while (ch);


	// printf("size = %d\n", size(pt));

	// if (isEmpty(pt)) {
	// 	printf("The queue is empty");
	// }
	// else {
	// 	printf("The queue is not empty");
	// }

	getch();
}