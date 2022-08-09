#include<stdio.h>
#include<stdlib.h>

struct TreeNode
{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
};

/**
 * It deletes the tree.
 * 
 * @param root The root of the tree.
 * 
 * @return The root of the tree.
 */
struct TreeNode* makeEmpty(struct TreeNode* root)
{
	if (root != NULL)
	{
		makeEmpty(root->left);
		makeEmpty(root->right);
		free(root);
	}
	return NULL;
}

/**
 * If the root is NULL, create a new node and return it. Otherwise, if the value is less than the root,
 * insert it into the left subtree. Otherwise, if the value is greater than the root, insert it into
 * the right subtree
 * 
 * @param root The root of the tree.
 * @param x the value to be inserted
 * 
 * @return The root of the tree.
 */
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

/**
 * If the root is NULL, return NULL. If the root's left child is NULL, return the root. Otherwise,
 * return the minimum value in the root's left subtree
 * 
 * @param root The root of the tree.
 * 
 * @return The minimum value in the tree.
 */
struct TreeNode* findMin(struct TreeNode* root)
{
	if (root == NULL)
		return NULL;
	else if (root->left == NULL)
		return root;
	else
		return findMin(root->left);
}

/**
 * It finds the maximum value in the tree.
 * 
 * @param root The root of the tree
 * 
 * @return The maximum value in the tree.
 */
struct TreeNode* findMax(struct TreeNode* root)
{
	if (root == NULL)
		return NULL;
	else if (root->right == NULL)
		return root;
	else
		return findMax(root->right);
}

/**
 * If the root is NULL, return NULL; if x is less than the root, return the result of searching the
 * left subtree; if x is greater than the root, return the result of searching the right subtree;
 * otherwise, return the root
 * 
 * @param root The root of the tree
 * @param x The value to be searched in the tree.
 * 
 * @return The node that contains the value x.
 */
struct TreeNode* find(struct TreeNode* root, int x)
{
	if (root == NULL)
		return NULL;
	else if (x < root->data)
		return find(root->left, x);
	else if (x > root->data)
		return find(root->right, x);
	else
		return root;
}

/**
 * If the root is NULL, return -1. Otherwise, return the maximum of the heights of the left and right
 * subtrees, plus 1
 * 
 * @param root The root of the tree
 * 
 * @return The height of the tree.
 */
int findHeight(struct TreeNode* root)
{
	int lefth, righth;
	if (root == NULL)
		return -1;
	lefth = findHeight(root->left);
	righth = findHeight(root->right);
	return (lefth > righth ? lefth : righth) + 1;
}

/**
 * If the node to be deleted has two children, replace it with its inorder successor; otherwise, delete
 * it
 * 
 * @param root The root of the tree
 * @param x The value to be deleted from the tree.
 * 
 * @return The root of the tree.
 */
struct TreeNode* delete(struct TreeNode* root, int x)
{
	struct TreeNode* temp;
	if (root == NULL)
		return NULL;
	else if (x < root->data)
		root->left = delete(root->left, x);
	else if (x > root->data)
		root->right = delete(root->right, x);
	else if (root->left && root->right)
	{
		temp = findMin(root->right);
		root->data = temp->data;
		root->right = delete(root->right, root->data);
	}
	else
	{
		temp = root;
		if (root->left == NULL)
			root = root->right;
		else if (root->right == NULL)
			root = root->left;
		free(temp);
	}
	return root;
}

/**
 * Inorder traversal of a binary tree is to traverse the left subtree first, then root and right
 * subtree
 * 
 * @param root The root of the tree
 * 
 * @return the root of the tree.
 */
void inorder(struct TreeNode* root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

void main()
{
	system("cls");
	struct TreeNode* root;
	struct TreeNode* temp;
	int n, tmp, ch;
	root = NULL;

	do {
		printf("\n**Menu**\n1.Enter elements\n2.Check height\n3.In order\n4.Min\n5.Max\n6.Delete\n7.Empty Tree\n8.Find\n0.Exit\nEnter Choice : "); // add 8.Find
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
		case 3:
			system("cls");
			printf("In order: ");
			inorder(root);
			break;
		case 4:
			system("cls");
			temp = findMin(root);
			printf("Min Element: %d\n", temp->data);
			break;
		case 5:
			system("cls");
			temp = findMax(root);
			printf("Max Element: %d\n", temp->data);
			break;
		case 6:
			system("cls");
			printf("Enter Element: ");
			scanf("%d", &tmp);
			root = delete(root, tmp);
			break;
		case 7:
			system("cls");
			printf("Empty!\n");
			root = makeEmpty(root);
			break;
		case 8:
			system("cls");
			printf("Enter value to be searched: ");
			scanf("%d", &tmp);
			temp = find(root, tmp); // Use of find() function maybe wrong here.
			printf("\nThe Element is at: %d", temp);
			break;
		case 0:
			system("cls");
			printf("**Exit**");
			break;
		default:
			system("cls");
			printf("Open your eyes");
			break;
		}

	} while (ch != 0);
	getch();
}