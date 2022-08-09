package Assignment;
// Q5 OOPS Assignment

import java.util.Scanner;

public class matrixAdd {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		System.out.println("Enter rows and columns (m x n)");
		int m = s.nextInt();
		int n = s.nextInt();
		int m1[][] = new int[m][n];
		int m2[][] = new int[m][n];
		int m3[][] = new int[m][n];

		// Input Matrix values
		System.out.println("Enter values of Matrix 1");
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				m1[i][j] = s.nextInt();
			}
		}
		System.out.println("Enter values of Matrix 2");
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				m2[i][j] = s.nextInt();
			}
		}
		s.close();
		System.out.print("\033[H\033[2J");
		System.out.flush();
		// matrix addition and printing
		System.out.println("The Resultant Matrix is: ");
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				m3[i][j] = m1[i][j] + m2[i][j];
				System.out.print(m3[i][j] + " ");
			}
			System.out.println();
		}
	}
}
