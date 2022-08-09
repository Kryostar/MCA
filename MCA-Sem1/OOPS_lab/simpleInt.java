/**
 * This class takes the principle, rate and time as input and calculates the simple interest
 */
import java.util.Scanner;

public class simpleInt {
	public static void main(String[] args) {
		System.out.print("\033[H\033[2J");
		System.out.flush();
		Scanner s = new Scanner(System.in);
		System.out.print("Enter the Principle, Rate and Time: ");
		float Principle = s.nextFloat();
		float Rate = s.nextFloat();
		float Time = s.nextFloat();
		s.close();
		float SI = (Principle * Rate * Time) / 100;
		System.out.println("Simple interest = " + SI);
	}
}