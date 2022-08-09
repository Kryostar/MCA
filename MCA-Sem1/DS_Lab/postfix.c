/**
 * The function takes a string as input and returns the result of the expression
 * 
 * @param x The value to be pushed onto the stack.
 */
#include<stdio.h>
int stack[20];
int top = -1;

void push(int x)
{
	stack[++top] = x;
}

int pop()
{
	return stack[top--];
}

void main() {
	system("cls");
	char exp[20];
	char* e;
	int A, B, C, num;
	printf("Enter the expression :: ");
	scanf("%s", exp);
	e = exp;
	while (*e != '\0')
	{
		if (isdigit(*e))
		{
			// printf("%d ",*e); /* printing the numbers in their ASCII values */
			num = *e - 48; /* 48 is the ASCII value of char '0', we are converting character to digit */
			push(num);
		}
		else
		{
			A = pop();
			B = pop();
			switch (*e)
			{
			case '+':
			{
				C = A + B;
				break;
			}
			case '-':
			{
				C = B - A;
				break;
			}
			case '*':
			{
				C = A * B;
				break;
			}
			case '/':
			{
				C = B / A;
				break;
			}
			}
			push(C);
		}
		e++;
	}
	printf("\nThe result of expression %s  =  %d\n\n", exp, pop());
}