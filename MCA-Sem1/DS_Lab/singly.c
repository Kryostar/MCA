#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
struct node* root = NULL;
int len;

void insert(void);
int length(void);
void display(void);
void delete(void);
void main()
{
	int ch;
	while (1)
	{
		printf("singly linked list:\n");
		printf("1.insert\n");
		printf("2.length\n");
		printf("3.display\n");
		printf("4.delete\n");
		printf("5.exit\n");


		printf("enter your choice:");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1: insert();
			break;
		case 2:len = length();
			printf("Length :%d\n\n", len);
			break;
		case 3:display();
			break;
		case 4:delete();
			break;
		case 5:exit(0);
		default:printf("invalid input\n\n");
		}
	}
}

void insert()
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("enter node data :");
	scanf("%d", &temp->data);
	temp->link = NULL;
	if (root == NULL)
	{
		root = temp;
	}
	else
	{
		struct node* p;
		p = root;
		while (p->link != NULL)
		{
			p = p->link;
		}
		p->link = temp;
	}
}

int length()
{
	int count = 0;
	struct node* temp;
	temp = root;

	while (temp != NULL)
	{
		count++;
		temp = temp->link;

	}
	return count;
}

void display()
{
	struct node* temp;
	temp = root;
	if (temp == NULL)
	{
		printf("list is empty\n\n");
	}
	else
	{
		while (temp != NULL)
		{
			printf("%d\t", temp->data);
			temp = temp->link;
		}
		printf("\n\n");
	}
}

void delete(void)
{
	struct node* temp;
	int loc;
	printf("enter location to delete:");
	scanf("%d", &loc);
	if (loc > length())
	{
		printf("invalid location\n");
	}
	else if (loc == 1)
	{
		temp = root;
		root = temp->link;
		temp->link = NULL;
		free(temp);
	}
	else
	{
		struct node* p = root, * q; // p and q are temp
		int i = 1;
		while (i < loc - 1)
		{
			p = p->link;
			i++;
		}
		q = p->link;
		p->link = q->link; // NULL
		q->link = NULL;
		free(q);
	}
}