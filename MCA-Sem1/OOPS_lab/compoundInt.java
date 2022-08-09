import java.util.Scanner;

/**
 * This class takes in the principle, rate and time and calculates the compound interest
 */
class compoundInt {
	public static void main(String args[]) {
		System.out.print("\033[H\033[2J");
		System.out.flush();
		Scanner s = new Scanner(System.in);
		System.out.print("Enter the Principle, Rate and Time: ");
		float Principle = s.nextFloat();
		float Rate = s.nextFloat();
		float Time = s.nextFloat();
		s.close();
		double CI = Principle *
				(Math.pow((1 + (Rate / 100)), Time));

		System.out.println("Compound Interest is " + CI);
	}
}