#include<stdio.h>
#include<stdlib.h>

void fact(int n) {
	int fact = 1;
	while (n != 0) {
		fact = fact * n;
		n--;
	}
	printf("Factorial of %d is %d\n", n, fact);
}

void prime(int n) {
	if (n == 0 || n == 1)
		printf("%d is not a prime number\n", n);
	else {
		int m = n / 2, flag = 0;
		for (int i = 2;i <= m;i++) {
			if (n % i == 0) {
				printf("%d is not a prime number\n", n);
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			printf("%d is a prime number\n", n);
		}
	}
}

void oddeven(int n) {
	if (n % 2 == 0)
		printf("%d is even!\n", n);
	else
		printf("%d is odd\n", n);
}

void main() {
	int ch, n;
	system("cls");
	do {
		printf("** Menu **\n1.Factorial\n2.Prime\n3.Even / Odd\n0.Exit\nEnter your choice!: ");
		scanf("%d", &ch);
		printf("Enter the number: ");
		if (ch != 0)
			scanf("%d", &n);
		system("cls");
		switch (ch)
		{
		case 1:
			fact(n);
			break;
		case 2:
			prime(n);
			break;
		case 3:
			oddeven(n);
			break;
		case 0:
			printf("** Exit! **\n");
			break;
		default:
			printf("** INPUT ERROR! **\n");
			break;
		}
	} while (ch != 0);
}