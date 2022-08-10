import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Scanner;

public class date {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter Date in dd/MM/yyyy format: ");
		String s = sc.nextLine();
		sc.close();
		if (getvalues(s) == 1) {
			System.out.println("Valid date format");
		} else {
			System.out.println("Invalid date format");
		}
	}

	public static int getvalues(String s) {
		if (s.matches("[0-9]{2}[/]{1}[0-9]{2}[/]{1}[0-9]{4}")) {
			SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
			sdf.setLenient(false);
			try {
				sdf.parse(s);
				return 1;
			} catch (ParseException e) {
				return -1;
			}
		} else
			return -1;
	}
}