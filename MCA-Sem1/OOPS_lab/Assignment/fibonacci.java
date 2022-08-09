package Assignment;
// Q4 OOPS Assignment

import java.util.Scanner;

public class fibonacci {
	static int n1 = 0, n2 = 1, n3 = 0;

	static void fib(int num) {
		if (num > 0) {
			n3 = n1 + n2;
			n1 = n2;
			n2 = n3;
			System.out.print(" " + n3);
			fib(num - 1);
		}
	}

	public static void main(String args[]) {
		Scanner s = new Scanner(System.in);
		int num = s.nextInt();
		s.close();
		System.out.print("\033[H\033[2J");
		System.out.flush();
		System.out.print(n1 + " " + n2);
		fib(num - 2);
	} 
}