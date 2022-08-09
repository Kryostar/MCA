// STACK program to push and pop elements
#include<stdio.h>
#include<process.h>
#define MAX 5

int top = -1, stack[MAX];
void push()
{
	system("cls");
	int element;
	if (top == MAX - 1)
	{
		printf("\nStack is FULL!");
	}
	else {
		printf("\nEnter Element to be pushed to Stack: ");
		scanf("%d", &element);
		top += 1;
		stack[top] = element;
	}
}

void pop()
{
	system("cls");
	if (top == -1)
	{
		printf("\nStack is EMPTY!");
	}
	else {
		printf("\nElement deleted from top is: %d", stack[top]);
		top -= 1;
	}
}

void display()
{
	system("cls");
	int i;
	if (top == -1)
	{
		printf("\nStack is EMPTY!");
	}
	else {
		printf("\nStack:");
			for (i = top;i >= 0;i--)
				printf("\n%d",stack[i]);
	}
}

void main()
{
	int choice;
	do {
		printf("\nStack Operations\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\nEnter your choice:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
			printf("Program will EXIT");
			break;
		default:
			printf("Please enter a valid option!");
			break;
		}
	} 	while (choice != 4);
}