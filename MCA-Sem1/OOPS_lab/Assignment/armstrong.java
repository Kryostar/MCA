// Q8 OOPS Assignment
package Assignment;

import java.util.Scanner;

public class armstrong {
	public static void main(String[] args) {
		System.out.print("\033[H\033[2J");
		System.out.flush();
		Scanner s = new Scanner(System.in);
		System.out.print("Enter a Number:");
		int num = s.nextInt();
		s.close();

		int sum = 0, temp = num, rm, pow = 0;
		if (num > 0) {

			// to find the number of digits in 'num'
			temp = num;
			while (temp > 0) {
				temp = temp / 10;
				pow++;
			}

			temp = num;
			while (temp > 0) {
				rm = temp % 10; // extract last digit from 'temp'
				sum += (Math.pow(rm, pow));
				temp = temp / 10; // remove last digit from 'temp'
			}
			if (sum == num) {
				System.out.println(num + " is an Armstrong number");
			} else
				System.out.println(num + " is not an Armstrong number");
		} else
			System.out.println("Enter a number > 0");
	}
}
