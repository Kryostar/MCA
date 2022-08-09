/**
 * The function takes a postfix expression as input and evaluates it
 * 
 * @param item the item to be pushed onto the stack
 * 
 * @return The result of the expression evaluation.
 */

#include <stdio.h>
#include <ctype.h>

#define MAXSTACK 100
#define POSTFIXSIZE 100

int stack[MAXSTACK];
int top = -1;
/* define push operation */
void push(int item)
{

	if (top >= MAXSTACK - 1) {
		printf("stack over flow");
		return;
	}
	else {
		top = top + 1;
		stack[top] = item;
	}
}

/* define pop operation */
int pop()
{
	int item;
	if (top < 0) {
		printf("stack under flow");
	}
	else {
		item = stack[top];
		top = top - 1;
		return item;
	}
}

void EvalPostfix(char postfix[])
{

	int i;
	char ch;
	int val;
	int A, B;

	for (i = 0; postfix[i] != ')'; i++) {
		ch = postfix[i];
		if (isdigit(ch)) {
			push(ch - '0');
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			A = pop();
			B = pop();

			switch (ch) /* ch is an operator */
			{
			case '*':
				val = B * A;
				break;

			case '/':
				val = B / A;
				break;

			case '+':
				val = B + A;
				break;

			case '-':
				val = B - A;
				break;
			}
			push(val);
		}
	}
	printf("\nResult of expression evaluation : %d \n", pop());
}

void main()
{
	system("cls");
	int i;
	char postfix[POSTFIXSIZE];
	printf("Enter postfix expression: ");
	scanf("%f",&postfix);
	EvalPostfix(postfix);
}