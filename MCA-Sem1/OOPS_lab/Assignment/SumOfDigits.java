package Assignment;
// Q2 OOPS Assignment

import java.util.Scanner;

public class SumOfDigits {
	public static void main(String[] args) {
		int number, digit, sum = 0;
		System.out.print("\033[H\033[2J");
		System.out.flush();
		Scanner s = new Scanner(System.in);
		System.out.print("Enter the number: ");
		number = s.nextInt();
		s.close();
		while (number > 0) {
			// finds the last digit of the given number
			digit = number % 10;
			// adds last digit to the variable sum
			sum = sum + digit;
			// removes the last digit from the number
			number = number / 10;
		}
		System.out.println("Sum of Digits: " + sum);
	}
}
