// Basic Calculator

import java.util.Scanner;

/**
 * It's a calculator that takes in two numbers and an operator and then performs the operation on the
 * two numbers
 */
public class calc {
	public static void main(String[] args) {
		Scanner S = new Scanner(System.in);
		System.out.print("\033[H\033[2J");
		System.out.flush();
		int num, res, flag = 0;
		char c;
		System.out.print(">");
		res = S.nextInt();
		do {
			System.out.print(">");
			num = S.nextInt();
			System.out.println("+ - / % *");
			c = S.next().charAt(0);
			System.out.print("\033[H\033[2J");
			System.out.flush();
			switch (c) {
				case '+':
					res = res + num;
					System.out.println("= " + res);
					break;
				case '-':
					res = res - num;
					System.out.println("= " + res);
					break;
				case '/':
					res = res / num;
					System.out.println("= " + res);
					break;
				case '*':
					res = res * num;
					System.out.println("= " + res);
					break;
				case '%':
					res = res % num;
					System.out.println("= " + res);
					break;
				default:
					System.out.println("Exit");
					flag = 1;
					break;
			}
		} while (flag != 1);
		S.close();
	}
}