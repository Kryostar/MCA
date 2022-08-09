package Assignment;
// Q7 OOPS Assignment

import java.util.Scanner;

public class factorial {
	public static void main(String[] args) {
		System.out.print("\033[H\033[2J");
		System.out.flush();
		Scanner s = new Scanner(System.in);
		System.out.print("Enter a number:");
		int num = s.nextInt();
		s.close(); // Close the scanner
		int fact = 1; // Initialize fact as 1 to avoid garbage values
		if (num > 0) {
			for (int i = 1; i <= num; i++) {
				fact = fact * i;
			}
			System.out.println("Factorial of " + num + " is " + fact);
		}
	}
}