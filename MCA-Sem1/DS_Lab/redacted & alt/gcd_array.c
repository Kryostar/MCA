#include<stdio.h>
void main()
{
	int a[5], final = a[0];
	printf("Enter 5 numbers: ");
	for (int i = 0;i < 5;i++) {
		scanf("%d", &a[i]);
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