/**
 * > If b is 0, return a, otherwise return the gcd of b and a mod b
 *
 * @param a The first number
 * @param b 0
 *
 * @return The greatest common divisor of a and b.
 */
int gcd3(int a, int b)
{
	if (b == 0)
		return a;
	return gcd3(b, a % b);
}

/**
 * It finds the GCD of three numbers.
 */
void main(){
	int a, b, c;
	system("cls"); // use clrscr();
	printf("Enter three numbers:");
	scanf("%d %d %d", &a, &b, &c);

	system("cls");
	int final = gcd3(a, gcd3(b, c));
	printf("GCD of %d, %d & %d is %d", a, b, c, final);
}
