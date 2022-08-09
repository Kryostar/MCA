#include<stdio.h>
#include<stdlib.h>

struct TreeNode
{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct TreeNode* insert(struct TreeNode* root, int x)
{
	if (root == NULL)
	{
		root = malloc(sizeof(struct TreeNode));
		root->data = x;
		root->left = root->right = NULL;
	}
	else if (x < root->data)
		root->left = insert(root->left, x);
	else if (x > root->data)
		root->right = insert(root->right, x);
	return root;
}

void main()
{
	struct TreeNode* root;
	struct TreeNode* temp;
	int n, tmp, ch;
	root = NULL;
	system("cls");
	do {
		printf(""); // add 8.Find
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			system("cls");
			printf("Enter number of elements: ");
			scanf("%d", &n);
			printf("Enter the elements: ");
			while (n != 0) {
				scanf("%d", &tmp);
				root = insert(root, tmp);
				n--;
			}
			break;
		case 2:
			system("cls");
			printf("Height: %d\n", findHeight(root));
			break;
		default:
			system("cls");
			printf("Open your eyes");
			break;
		}

	} while (ch != 0);
	getch();
}