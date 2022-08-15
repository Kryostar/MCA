#include<stdio.h>
void main()
{
	int a, b, c;
	printf("Enter 3 numbers: ");
	scanf("%d%d%d", &a, &b, &c);
		printf("GCD of %d, %d & %d is %d", a, b, c, gcd(a, gcd(b, c)));
}
int gcd(int x, int y)
{
	if (y == 0)
		return x;
	return gcd(y, x % y);
}