import java.util.Scanner;

public class operations {
	/**
	 * It takes two numbers as input, and prints their sum, difference, product, quotient, and remainder
	 */
	public static void main(String[] args) {
		Scanner S = new Scanner(System.in);
		System.out.print("\033[H\033[2J");
		System.out.flush();
		System.out.print("Enter two numbers: ");
		int a = S.nextInt();
		int b = S.nextInt();
		S.close();
		System.out.println("For inputs " + a + " and " + b +
				"\nSum is: " + (a + b) +
				"\nDifference is: " + (a - b) +
				"\nProduct is: " + (a * b) +
				"\nQuotient is: " + (a / b) +
				"\nRemainder is: " + (a % b));
	}
}
