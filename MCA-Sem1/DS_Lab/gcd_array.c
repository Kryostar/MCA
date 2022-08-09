/**
 * The function gcd(a,b) returns the greatest common divisor of a and b
 */
#include<stdio.h>
void main()
{
	int a[] = { 4,12,24,86,72 };
	int final = a[0];
	for (int i = 0;i < 5;i++) {
		final = gcd(final, a[i]);
	}
	printf("GCD is %d", final);
}
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}