package Assignment;
// Q10 OOPS Assignment

public class prism {
	public static void main(String[] args) {

		// clear screen
		System.out.print("\033[H\033[2J");
		System.out.flush();

		// upper half
		for (int i = 1; i <= 5; i++) {
			for (int j = i; j <= 5; j++) {
				System.out.print(" ");
			}
			for (int k = 1; k <= 2 * i - 1; k++) {
				System.out.print("*");
			}
			System.out.println();
		}

		// lower half
		for (int i = 5 - 1; i >= 1; i--) {
			for (int j = 5; j >= i; j--) {
				System.out.print(" ");
			}
			for (int k = 1; k <= 2 * i - 1; k++) {
				System.out.print("*");
			}
			System.out.println();
		}
	}
}
