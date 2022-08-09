#include <stdio.h>
/**
 * A node is a structure that contains an integer, a pointer to a node, and a pointer to a node.
 * @property {int} data - The data stored in the node.
 * @property leftChild - A pointer to the left child of the node.
 * @property rightChild - The right child of the node.
 */
struct node {
	int data;
	struct node* leftChild;
	struct node* rightChild;
};

/**
 * If the tree is empty, then the root is the new node. Otherwise, if the new node is less than the
 * current node, then it goes to the left. Otherwise, it goes to the right. If it can't go any further,
 * then it inserts the new node as a leaf
 * 
 * @param data the data to be inserted into the tree
 * 
 * @return the root of the tree.
 */
struct node* root = NULL;
void insert(int data) {
	struct node* tempNode = (struct node*)malloc(sizeof(struct node));
	struct node* current;
	struct node* parent;
	tempNode->data = data;
	tempNode->leftChild = NULL;
	tempNode->rightChild = NULL;
	//if tree is empty
	if (root == NULL) {
		root = tempNode;
	}
	else {
		current = root;
		parent = NULL;
		while (1) {
			parent = current;
			//go to left of the tree
			if (data < parent->data) {
				current = current->leftChild;
				//insert to the left
				if (current == NULL) {
					parent->leftChild = tempNode;
					return;
				}
			} //go to right of the tree
			else {
				current = current->rightChild;
				//insert to the right
				if (current == NULL) {
					parent->rightChild = tempNode;
					return;
				}
			}
		}
	}
}
//FIXME:Unfinished Search function
/*struct node* search(int data) {
	struct node* current = root;
	printf("Visiting elements: ");
	while (current->data != data) {
		if (current != NULL)
			printf("%d ", current->data);
		//go to left tree
		if (current->data > data) {
			current = current->leftChild;
		}
		//else go to right tree
		else {
			current = current->rightChild;
		}
		//not found
		if (current == NULL) {
			return NULL;
		}
	}
	return current;
}
*/

/**
 * If the root is not NULL, print the root's data, then recursively call the function on the root's
 * left child, then recursively call the function on the root's right child
 * 
 * @param root The root of the tree.
 */
void pre_order_traversal(struct node* root) {
	if (root != NULL) {
		printf("%d ", root->data);
		pre_order_traversal(root->leftChild);
		pre_order_traversal(root->rightChild);
	}
}

/**
 * If the root is not null, then traverse the left subtree, print the root, and traverse the right
 * subtree
 * 
 * @param root The root of the tree.
 */
void inorder_traversal(struct node* root) {
	if (root != NULL) {
		inorder_traversal(root->leftChild);
		printf("%d ", root->data);
		inorder_traversal(root->rightChild);
	}
}

/**
 * If the root is not null, then traverse the left subtree, then traverse the right subtree, then print
 * the root
 * 
 * @param root The root of the tree.
 */
void post_order_traversal(struct node* root) {
	if (root != NULL) {
		post_order_traversal(root->leftChild);
		post_order_traversal(root->rightChild);
		printf("%d ", root->data);
	}
}

/**
 * The function takes a pointer to a node as an argument and returns the height of the tree rooted at
 * that node
 */
void main() {
	int ch, n, i;
	system("cls");
	do {
		printf("\n**MENU**\n1.Enter Elements\n0.Exit\nEnter your Choice: ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			system("cls");
			printf("Enter number of elements: ");
			scanf("%d", &i);
			printf("Enter the elements: ");
			while (i != 0) {
				scanf("%d", &n);
				insert(n);
				i--;
			}
			system("cls");
			printf("\nPreorder Traversal: ");
			pre_order_traversal(root);
			printf("\nInorder Traversal: ");
			inorder_traversal(root);
			printf("\nPost order Traversal: ");
			post_order_traversal(root);
			break;
		case 0:
			printf("**EXIT!**");
			break;
		}
	} while (ch != 0);
	getch();
}