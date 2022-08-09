
import java.util.Scanner;

/**
 * This class calculates the area of a square, triangle, circle and rectangle.
 */
class area {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		System.out.print("\033[H\033[2J");
		System.out.flush();
		System.out.print("Enter one side of the square: ");
		int sqa = s.nextInt();
		System.out.println("Area of Square is: " + (sqa * sqa));
		System.out.print("Enter base and height values of Triangle: ");
		int b = s.nextInt();
		int h = s.nextInt();
		System.out.println("Area of Triangle is: " + (0.5 * b * h));
		System.out.print("Enter radius of circle: ");
		int r = s.nextInt();
		System.out.println("Area of Square is: " + (3.14 * r * r));
		System.out.print("Enter length and breadth of Rectangle: ");
		int l = s.nextInt();
		int bh = s.nextInt();
		System.out.println("Area of Rectangle is: " + (l * bh));
		s.close();
	}
}