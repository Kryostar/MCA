package Assignment;
// Q9 OOPS Assignment

import java.util.Scanner;

public class evenodd {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		System.out.print("How many elements? ");
		int n = s.nextInt();
		System.out.println("Enter " + n + " elements");
		int a[] = new int[n];

		// Read user input
		for (int i = 0; i < n; i++) {
			a[i] = s.nextInt();
		}
		s.close();

		// print even numbers
		System.out.print("Even numbers in the list are: ");
		for (int i = 0; i < n; i++) {
			if (a[i] % 2 == 0) {
				System.out.print(a[i] + " ");
			}
		}

		// print odd numbers
		System.out.print("\nOdd numbers in the list are: ");
		for (int i = 0; i < n; i++) {
			if (a[i] % 2 != 0) {
				System.out.print(a[i] + " ");
			}
		}
	}
}
