/**
 * This class prints a triangle of stars in reverse order
 */
public class rev_Triangle {
	public static void main(String args[]) {
		for (int i = 10; i > 0; i--) {
			for (int j = i; j > 0; j--) {
				System.out.print(" ");
			}
			for (int k = 0; k < i + 1; k++) {
				System.out.print("*");
			}
			System.out.println();
		}
	}
}