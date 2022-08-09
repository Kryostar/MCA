package Assignment;
// Q6 OOPS Assignment

public class sumdiv7 {
	public static void main(String[] args) {
		int sum = 0;
		System.out.print("\033[H\033[2J");
		System.out.flush();
		System.out.println("Numbers between 100 and 200 that are divisible by 7 are:");
		for (int i = 100; i < 200; i++) {
			if (i % 7 == 0) {
				sum += i;
				System.out.print(i + "\t");
			}
		}
		System.out.println("\nSum of the numbers is: " + sum);
	}
}