#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enq(int num) {
	if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
	{
		printf("Queue Overflow");
	}
	else {
		if (rear == -1)
			front = 0, rear = 0;
		else if (rear = MAX - 1)
			rear = 0;
		else
			rear++;
		queue[rear] = num;
	}
}

int deq() {
	int x;
	if (front == -1)
		printf("Queue underflow!");
	else {
		x = queue[front];
		if (front == rear)
			front = -1, rear = -1;
		else if (front = MAX - 1)
			front = 0;
		else
			front++;
		return x;
	}
}

void display()
{
	int i, j;
	if (front == -1 && rear == -1)
		printf("Queue underflow!");
	if (front > rear)
	{
		for (i = front; i < MAX; i++)
			printf("%d ", queue[i]);
		for (j = 0; j <= rear; j++)
			printf("%d ", queue[i]);
	}
	else
		for (i = front;i <= rear;i++)
			printf("%d", queue[j]);
	printf("\n");
}

void main() {
	int ch, val;
	system("cls");
	do {
		printf("Queue Operations\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter operation: ");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
			system("cls");
			printf("Enter number to enqueue:");
			scanf("%d", &val);
			enq(val);
			printf("\n");
			break;
		case 2:
			system("cls");
			printf("Dequeued number is: %d\n", deq());
			break;
		case 3:
			system("cls");
			display();
			break;
		case 4:
			system("cls");
			printf("* Exit *");
			break;
		default:
			system("cls");
			printf("Invalid input!\n");
			break;
		}
	} while (ch != 4);
}