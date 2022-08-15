#include<stdio.h>

/**
 * If a and b are both 0, return 0. Otherwise, if a is 0, return b. Otherwise, if b is 0, return a.
 * Otherwise, if a equals b, return a. Otherwise, if a is greater than b, return gcd(a-b,b). Otherwise,
 * return gcd(a,b-a)
 * 
 * @param a The first number
 * @param b the base
 * 
 * @return The greatest common divisor of two integers.
 */
int gcd(int a, int b)
{
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	if (a == b)
		return a;
	if (a > b)
		return gcd(a - b, b);
	return gcd(a, b - a);
}

/**
 * The function gcd() takes two integers as arguments and returns the greatest common divisor of the
 * two integers
 * 
 * @return The GCD of the two numbers.
 */
int main()
{
	int a, b;
	// use clrscr();
	system("cls");
	printf("Enter two numbers:");
	scanf("%d%d", &a, &b);
	printf("GCD of %d and %d is %d ", a, b, gcd(a, b));
	return 0;
}
