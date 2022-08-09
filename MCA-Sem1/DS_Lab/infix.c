#include <stdio.h>
#include <ctype.h>

#define SIZE 50            

char stack[SIZE];
int top = -1;

/* Pushing the element into the stack. */
push(char ele)
{
	stack[++top] = ele;
}

/**
 * It returns the top element of the stack and then decrements the top.
 * 
 * @return The top element of the stack.
 */
char pop()
{
	return(stack[top--]);
}

/**
 * It returns the precedence of the operator passed to it
 * 
 * @param symbol The symbol to check the precedence of.
 * 
 * @return The precedence of the operator.
 */
int precedence(char symbol)
{
	if (symbol == '^')
	{
		return(3);
	}
	else if (symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if (symbol == '+' || symbol == '-')
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

/**
 * The function takes an infix expression as input and converts it into a postfix expression
 */
void main()
{
	char infix[50], postfix[50], ch, ele;
	int i = 0, k = 0;
	system("cls");
	printf("Enter Infix Expression : ");
	scanf("%s", infix);
	push('$');
	while ((ch = infix[i++]) != '\0')
	{
		if (ch == '(')
			push(ch);
		if (ch == ')')
		{
			while (stack[top] != '(')
				postfix[k++] = pop();
			ele = pop();
		}
		else
		{
			while (precedence(stack[top]) >= precedence(ch))
				postfix[k++] = pop();
			push(ch);
		}
		if (isalnum(ch))
			postfix[k++] = ch;
	}
	while (stack[top] != '$')
		postfix[k++] = pop();
	postfix[k] = '\0';
	printf("\nPostfix Expression =  %s\n", postfix);
}