package Assignment;
// Q3 OOPS Assignment
import java.util.Scanner;

public class sumArray {
	public static void main(String[] args) {
		System.out.print("\033[H\033[2J");
		System.out.flush();
		Scanner S = new Scanner(System.in);
		int arr[] = new int[10];
		int sum = 0;
		System.out.println("Enter 10 numbers: ");
		for (int i : arr) {
			arr[i] = S.nextInt();
			sum = sum + arr[i];
		}
		S.close();
		System.out.println("Sum of Array is: " + sum);
	}
}
