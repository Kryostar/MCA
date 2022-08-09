import java.util.Scanner;

public class marks {
	/**
	 * Grades the Student depending on the total marks obtained by the student
	 * 
	 * @param total The total marks obtained by the student.
	 */
	static void grade(int total) {
		if (total >= 90)
			System.out.println("Grade: S");
		else if (total >= 80 && total < 90)
			System.out.println("Grade: A");
		else if (total >= 70 && total < 80)
			System.out.println("Grade: B");
		else if (total >= 60 && total < 70)
			System.out.println("Grade: C");
		else if (total >= 50 && total < 60)
			System.out.println("Grade: D");
		else if (total >= 35 && total < 50)
			System.out.println("Grade: E");
		else if (total < 35)
			System.out.println("Grade: A");
	}

	/**
	 * It takes in the total marks of a student and prints out the grade
	 */
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		System.out.print("\033[H\033[2J");
		System.out.flush();
		System.out.print("Enter class strength: ");
		int x = s.nextInt();
		String name[] = new String[x];
		int m1[] = new int[x];
		int m2[] = new int[x];
		int m3[] = new int[x];
		int i = 0;
		do {
			System.out.print("\033[H\033[2J");
			System.out.flush();
			System.out.println("Student Marks\n1.Enter Details\n2.Display");
			char c = s.next().charAt(0);
			switch (c) {
				// Taking in the details of the student.
				case 1:
					if (i < x) {
						System.out.print("Name: ");
						name[i] = s.nextLine();
						System.out.print("Subject 1:");
						m1[i] = s.nextInt();
						System.out.print("Subject 1:");
						m2[i] = s.nextInt();
						System.out.print("Subject 1:");
						m3[i] = s.nextInt();
						i++;
						break;
					}

				// Taking in the roll number of the student and then printing out the details of the student.
				case 2:
					System.out.print("Roll Number: ");
					s.close();
					int n = s.nextInt();
					int total = m1[n - 1] + m2[n - 1] + m3[n - 1];
					System.out.println("Name: " + name[n - 1] +
							"\nSubject 1 Marks: " + m1[n - 1] +
							"\nSubject 2 Marks: " + m2[n - 1] +
							"\nSubject 3 Marks: " + m3[n - 1] +
							"\nTotal: " + total);
					grade(total);
			}
		} while (true);
	}
}
