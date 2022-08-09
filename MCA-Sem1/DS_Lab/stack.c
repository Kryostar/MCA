#include<stdio.h>
#define MAX 5
int top = -1, stack[MAX];

void push()
{
	system("cls");
	int val;
	if (top == MAX - 1)
	{
		printf("The Stack is Full");
	}
	else
	{
		printf("Enter element to push:");
		scanf("%d", &val);
		top = top + 1;
		stack[top] = val;
	}
	printf("\n");
}

void pop()
{
	system("cls");
	if (top == -1)
	{
		printf("The Stack is empty");
	}
	else
	{
		printf("The Deleted element is %d", stack[top]);
		top = top - 1;
	}
	printf("\n");
}

void display()
{
	system("cls");
	int i;
	if (top == -1)
	{
		printf("The Stack is empty");
	}
	else
	{
		printf("The Stack is: ");
		for (i = top;i >= 0;--i)
			printf("%d ", stack[i]);
	}
	printf("\n");
}

void main()
{
	int ch;
	system("cls");
	do
	{
		printf("Stack Operations\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter Opertaion: ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1: push();
			break;
		case 2: pop();
			break;
		case 3: display();
			break;
		case 4:
			printf("*EXIT*");
			break;
		default:
			printf("\nWrong Choice\n");
		}
	} while (ch != 4);
}