import java.util.Scanner;

public class multi {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		System.out.print("Enter the starting range: ");
		int x = s.nextInt();
		System.out.print("Enter the ending range: ");
		int y = s.nextInt();
		s.close();
		for (int i = 1; i <= 10; i++) {
			for (int j = x; j <= y; j++) {
				System.out.print(j + "*" + i + "=" + j * i + "\t");
			}
			System.out.println();
		}
	}
}