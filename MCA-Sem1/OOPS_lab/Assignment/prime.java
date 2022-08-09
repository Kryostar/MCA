package Assignment;
// Q1 OOPS Assignment

import java.util.Scanner;

public class prime {
	public static void main(String[] args) {
		Scanner S = new Scanner(System.in);
		System.out.print("\033[H\033[2J");
		System.out.flush();
		System.out.print("Enter the number: ");
		int num = S.nextInt();
		S.close();

		/*
		 * Check if the number is '0' or '1'
		 * Can't divide 0/2
		 * and '1' is neither prime nor composite
		 */
		if (num == 0 || num == 1) {
			System.out.println(num + " is not a prime number");
		}

		else {
			int m = num / 2, flag = 0;
			for (int i = 2; i <= m; i++)
			/*
			 * Starting from i=2
			 * Since we already checked for '0' and '1'
			 */
			{
				if (num % i == 0) // For prime numbers, remainder cannot be '0'
				{
					System.out.println(num + " is not a prime number");
					flag = 1;
					break;
				}
			}

			if (flag == 0) {
				System.out.println(num + " is a prime number");
			}
		}
	}
}