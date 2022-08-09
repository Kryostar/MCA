import java.util.Scanner;

/**
 * It takes 9 elements from the user and displays them in a 3x3 matrix form
 */
public class matrix {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		System.out.print("\033[H\033[2J");
		System.out.flush();
		System.out.println("Enter 9 elements");
		int a[] = new int[9];

		// User input
		for (int i = 0; i < 9; i++) {
			a[i] = s.nextInt();
		}
		s.close();
		// Display elements in 3x3 Matrix form
		System.out.println("Displaying Elements in 3x3 Matrix Form: ");
		for (int i = 0, k = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				System.out.print(a[k] + " ");
				k++;
			}
			System.out.println();
		}
	}
}
