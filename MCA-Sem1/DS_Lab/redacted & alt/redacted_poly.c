#include<stdio.h>
#include<stdlib.h>

/**
 * The structure for the polynomial
 * This is a linked list with two variable
 * int coeff The Coefficient
 * int pow The power of x
 */
typedef struct link {
	int coeff;
	int pow;
	struct link* next;
} polynomial;

/** The prototypes
void create_poly(polynomial**);
void display(polynomial*);
void add_poly(polynomial**, polynomial*, polynomial*);
*/

/**
 * The create polynomial function
 * @param polynomial ** node The pointer to the head of the polynomial
 * We will modify the parameter and will store the base address
 * @return void
 */
void create_poly(polynomial** node) {
	system("cls");
	int flag; //A flag to control the menu
	int coeff, pow;
	polynomial* tmp_node; //To hold the temporary last address
	tmp_node = (polynomial*)malloc(sizeof(polynomial)); //create the first node
	*node = tmp_node; //Store the head address to the reference variable
	do {
		//Get the user data
		printf("\nEnter Coeff:");
		scanf("%d", &coeff);
		tmp_node->coeff = coeff;
		printf("\nEnter Pow:");
		scanf("%d", &pow);
		tmp_node->pow = pow;
		//Done storing user data

		//Now increase the Linked on user condition
		tmp_node->next = NULL;

		//Ask user for continuation
		printf("\nContinue adding more terms to the polynomial list?(Y = 1/N = 0): ");
		scanf("%d", &flag);
		//printf("\nFLAG: %c\n", flag);
		//Grow the linked list on condition
		if (flag) {
			tmp_node->next = (polynomial*)malloc(sizeof(polynomial)); //Grow the list
			tmp_node = tmp_node->next;
			tmp_node->next = NULL;
		}
	} while (flag);
}

/**
 * The show polynomial function
 * Prints the Polynomial in user readable format
 * @param polynomial * node The polynomial linked list
 * @return void
 */
void display(polynomial* node) {
	system("cls");
	printf("\nThe polynomial expression is:\n");
	while (node != NULL) {
		printf("%dx^%d", node->coeff, node->pow);
		node = node->next;
		if (node != NULL)
			printf(" + ");
	}
}

/**
 * The polynomial add function
 * Adds two polynomial to a given variable
 * @param polynomial ** result Stores the result
 * @param polynomial * polynomial1 The first polynomial expression
 * @param polynomial * polynomial2 The second polynomial expression
 * @return void
 */
void add_poly(polynomial** result, polynomial* polynomial1, polynomial* polynomial2) {
	polynomial* tmp_node; //Temporary storage for the linked list
	tmp_node = (polynomial*)malloc(sizeof(polynomial));
	tmp_node->next = NULL;
	*result = tmp_node; //Copy the head address to the result linked list

	//Loop while both of the linked lists have value
	while (polynomial1 && polynomial2) {
		if (polynomial1->pow > polynomial2->pow) {
			tmp_node->pow = polynomial1->pow;
			tmp_node->coeff = polynomial1->coeff;
			polynomial1 = polynomial1->next;
		}
		else if (polynomial1->pow < polynomial2->pow) {
			tmp_node->pow = polynomial2->pow;
			tmp_node->coeff = polynomial2->coeff;
			polynomial2 = polynomial2->next;
		}
		else {
			tmp_node->pow = polynomial1->pow;
			tmp_node->coeff = polynomial1->coeff + polynomial2->coeff;
			polynomial1 = polynomial1->next;
			polynomial2 = polynomial2->next;
		}

		//Grow the linked list on condition
		if (polynomial1 && polynomial2) {
			tmp_node->next = (polynomial*)malloc(sizeof(polynomial));
			tmp_node = tmp_node->next;
			tmp_node->next = NULL;
		}
	}

	//Loop while either of the linked lists has value
	while (polynomial1 || polynomial2) {
		//We have to create the list at beginning
		//As the last while loop will not create any unnecessary node
		tmp_node->next = (polynomial*)malloc(sizeof(polynomial));
		tmp_node = tmp_node->next;
		tmp_node->next = NULL;

		if (polynomial1) {
			tmp_node->pow = polynomial1->pow;
			tmp_node->coeff = polynomial1->coeff;
			polynomial1 = polynomial1->next;
		}
		if (polynomial2) {
			tmp_node->pow = polynomial2->pow;
			tmp_node->coeff = polynomial2->coeff;
			polynomial2 = polynomial2->next;
		}
	}

	printf("\nAddition Complete");
}

// Menu in main function.
int main(void) {
	int ch;
	do {
		system("cls");
		polynomial* polynomial1, * polynomial2, * polynomial3;

		printf("\nCreate 1st expression\n");
		create_poly(&polynomial1);
		printf("\nStored the 1st expression");
		display(polynomial1);

		printf("\nCreate 2nd expression\n");
		create_poly(&polynomial2);
		printf("\nStored the 2nd expression");
		display(polynomial2);

		add_poly(&polynomial3, polynomial1, polynomial2);
		display(polynomial3);

		printf("\nAdd two more expressions? (Y = 1/N = 0): ");
		scanf("%d", &ch);
	} while (ch);
	return 0;
}