import java.util.Scanner;

/**
 * It's a class that takes a string and performs various operations on it
 */
public class q14 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter String:");
		String str = sc.nextLine();
		int ch;
		do {
			System.out.println(
					"1.Case\n2.Trim\n3.charAt\n4.startswith\n5.endswith\n6.length\n7.replace\n0.exit");
			ch = Integer.parseInt(sc.nextLine());
			switch (ch) {
				case 1:
					System.out.println(str.toUpperCase());
					System.out.println(str.toLowerCase());
					break;
				case 2:
					System.out.println("Trimmed String is: " + str.trim());
					break;
				case 4:
					System.out.println("Enter the String to check: "); {
					String chk = sc.nextLine();
					System.out.println(str.startsWith(chk));
				}
					break;
				case 5:
					System.out.println("Enter the String to check: "); {
					String chk = sc.nextLine();
					System.out.println(str.endsWith(chk));
				}
					break;
				case 6:
					System.out.println("Length of " + str + " is " + str.length());
					break;
				case 3:
					System.out.println("Enter where to check (num): ");
					int a = sc.nextInt();
					System.out.println("Character At " + a + " is " + str.charAt(a));
					break;
				/*
				 * case 7:
				 * System.out.println("Enter the String to be replaced: ");
				 * String s1 = sc.nextLine();
				 * 
				 */
			}
		} while (ch != 0);
		sc.close();
	}
}
