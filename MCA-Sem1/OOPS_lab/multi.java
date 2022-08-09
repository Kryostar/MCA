import java.util.Scanner;

public class multi {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		System.out.print("\033[H\033[2J");
		System.out.flush();
		System.out.print("Enter the number: ");
		int x = s.nextInt();
		s.close();
		for (int i = 1; i <= 10; i++)
			System.out.println(x + " * " + i + " = " + x * i);
	}
}