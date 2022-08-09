// 13. Write a JAVA Program to implement an array of objects of a class.
import java.util.Scanner;

/**
 * The above class is used to create an array of Student objects and display the details of each
 * student
 */
class q13 {

	public static void main(String args[]) {
		System.out.print("\033[H\033[2J");
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the number of students:");
		int size = sc.nextInt();
		Student[] arr = new Student[size];
		for (int i = 0; i < size; i++) {
			int x = i + 1;
			System.out.print("(" + x + ") Enter Student ID:");
			int a = sc.nextInt();
			sc.nextLine();
			System.out.print("(" + x + ") Enter Student Name:");
			String n = sc.nextLine();
			// System.out.print("\033[H\033[2J");
			arr[i] = new Student(a, n);
		}
		sc.close();
		System.out.print("\033[H\033[2J");
		System.out.print("Displaying the Student details:\n");
		for (int i = 0; i < size; i++) {
			arr[i].display();
		}
	}
}

/**
 * The Student class has two data members id and name. It has a constructor to initialize these data
 * members and a display() method to display the data.
 */
class Student {

	public int id;
	public String name;

	// Student class constructor
	Student(int id, String name) {
		this.id = id;
		this.name = name;
	}

	// display() method to display
	// the student data
	public void display() {
		System.out.println("Student ID: " + id + " "
				+ "\nStudent Name: "
				+ name);
		System.out.println();
	}
}
