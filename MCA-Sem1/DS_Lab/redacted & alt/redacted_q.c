#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX];
int front = 0;
int rear = 0;
int count = 0;


void enq(int num) {
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
}