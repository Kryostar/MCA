#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

int queue[MAX];
int front = 0;
int rear = 0;
int count = 0;

int peek() {
	return queue[front];
}

int size() {
	return count;
}

bool isEmpty() {
	return count == 0;
}

bool isFull() {
	return count == MAX;
}

void enq(int num) {
	if ((front == 0 && rear == size - 1) || (front == rear + 1))
	{
		printf("Queue is full");
		return;
	}
	else if (rear == -1)
	{
		rear++;
		front++;
	}
	else if (rear == MAX - 1 && front > 0)
	{
		rear = 0;
	}
	else
	{
		rear++;
	}
	queue[rear] = num;
	count++;

	/*
	if ((front == 0 && rear == MAX) ||
		(rear == (front - 1) % (MAX - 1)))
	{
		printf("Queue is Full\n");
		return;
	}

	else if (front == -1)
	{
		front = rear = 0;
		queue[rear] = num;
		count++;
	}

	else if (rear == MAX - 1 && front != 0)
	{
		rear = 0;
		queue[rear] = num;
		count++;
	}

	else
	{
		rear++;
		queue[rear] = num;
		count++;
	}
	*/


	/*
	if (!isFull())
	{
		if (rear == MAX - 1 && front != 0) {
			rear = 0;
		}
		queue[rear] = num;
		count++;
	}
	else if (isFull())
	{
		printf("Queue Overflow!\n");
	}
	*/
}

int deq() {
	int i;
	printf("\n");
	if (front > rear)
	{
		for (i = front; i < MAX; i++)
		{
			printf("%d ", queue[i]);
		}
		for (i = 0; i <= rear; i++)
			printf("%d ", queue[i]);
	}
	else
	{
		for (i = front; i <= rear; i++)
			printf("%d ", queue[i]);
	}
	/*
	system("cls");
	if (front == -1)
	{
		printf("\nQueue is Empty");
	}
	int data = queue[front];
	queue[front] = -1;
	if (front == rear)
	{
		front = rear = -1;
	}
	else if (front == MAX - 1)
		front = 0;
	else
		front++;
	return queue[front++];
	count--;
	*/

	/*if (!isEmpty()) {
		if (front == rear)
		{
			front = rear = -1;
		}
		else if (front == MAX) {
			front = 0;
		}
		int num = queue[front++];
		count--;
		return num;
	}
	else printf("Queue is empty!\n");*/
}
void display()
{
	int i;
	if (!isEmpty()) {
		printf("The Queue is: ");
		for (i = front + 1;i <= rear;i++)
			printf("%d ", queue[i]);
	}
	else
		printf("Queue is Empty!\n");
	printf("\n");
}


void main() {
	int ch, val;
	system("cls");
	do {
		printf("Queue Operations\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Size\n5.Display\n6.Exit\nEnter operation: ");
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
			if (!isEmpty()) {
				printf("Dequeued number is: %d\n", deq());
			}
			else
				printf("Queue Empty!\n");
			break;
		case 3:
			system("cls");
			if (!isEmpty()) {
				printf("Item on the front is: %d\n", peek());
			}
			break;
		case 4:
			system("cls");
			printf("Size is: %d\n", size());
			break;
		case 5:
			system("cls");
			display();
			break;
		case 6:
			system("cls");
			printf("* Exit *");
			break;
		default:
			system("cls");
			printf("Invalid input!\n");
			break;
		}
	} while (ch != 6);
}