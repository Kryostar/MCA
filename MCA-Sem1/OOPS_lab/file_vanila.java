import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.FilenameFilter;
import java.util.Scanner;

public class file_vanila {
	/**
	 * The createNewFile() method is used to create a file in Java, and return a boolean value : true if
	 * the file is created successful; false if the file is already exists
	 */
	void create() {
		File file = new File("newFile.txt");
		try {

			// trying to create a file based on the object
			boolean value = file.createNewFile();
			if (value) {
				System.out.println("The new file is created.");
			} else {
				System.out.println("The file already exists.");
			}
		} catch (Exception e) {
			e.getStackTrace();
		}
	}

	/**
	 * The read() method reads the contents of the file and stores it in the array
	 */
	void read() {
		char[] array = new char[100];
		try {
			// Creates a reader using the FileReader
			FileReader input = new FileReader("newFile.txt");

			// Reads characters
			input.read(array);
			System.out.println("Data in the file:");
			System.out.println(array);

			// Closes the reader
			input.close();
		} catch (Exception e) {
			e.getStackTrace();
		}
	}

	/**
	 * The function creates a new file called newFile.txt and writes the string "This is the data in the
	 * output file" to it
	 */
	void write() {
		String data = "This is the data in the output file";
		try {
			// Creates a Writer using FileWriter
			FileWriter output = new FileWriter("newFile.txt");

			// Writes string to the file
			output.write(data);
			System.out.println("Data is written to the file.");

			// Closes the writer
			output.close();
		} catch (Exception e) {
			e.getStackTrace();
		}
	}

	/**
	 * The delete() method deletes the file or directory denoted by the abstract pathname
	 */
	void delete() {
		// creates a file object
		File file = new File("newFile.txt");

		// deletes the file
		boolean value = file.delete();
		if (value) {
			System.out.println("The File is deleted.");
		} else {
			System.out.println("The File is not deleted.");
		}
	}

	/**
	 * It takes a directory as input, filters out all the .java files in it, and writes the names of the
	 * files to a new file
	 */
	void dir() {
		try {
			File f = new File("C:/Users/1kryo/Code/Personal/MCA/OOPS_lab");
			FileWriter output = new FileWriter("newFile.txt");
			FilenameFilter filter = new FilenameFilter() {
				@Override
				public boolean accept(File f, String name) {
					// We want to find only .java files
					return name.endsWith(".java");
				}
			};

			// Note that this time we are using a File class as an array,
			// instead of String
			File[] files = f.listFiles(filter);

			// Get the names of the files by using the .getName() method
			for (int i = 0; i < files.length; i++) {
				try (FileWriter fw = new FileWriter("newFile.txt", true);
						BufferedWriter bw = new BufferedWriter(fw)) {

					bw.write(files[i].getName());
					bw.newLine(); // add new line, System.lineSeparator()

				}
			}
			output.close();
		} catch (Exception e) {
			System.err.println(e.getMessage());
		}
	}

	/**
	 * clrscr() replacement
	 */
	void clr() {
		System.out.print("\033[H\033[2J");
	}

	/**
	 * A menu driven program that allows the user to create, read, write, delete and list files.
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		file_vanila fv = new file_vanila();
		fv.clr();
		while (true) {
			System.out.print("~MENU~\n1.Create\n2.Read\n3.Write\n4.Delete\n5.Dir\n0.Exit\nEnter choice: ");
			switch (sc.nextInt()) {
				case 1:
					fv.clr();
					fv.create();
					break;
				case 2:
					fv.clr();
					fv.read();
					break;
				case 3:
					fv.clr();
					fv.write();
					break;
				case 4:
					fv.clr();
					fv.delete();
					break;
				case 5:
					fv.clr();
					fv.dir();
					break;
				case 0:
					fv.clr();
					System.out.print("~EXIT~");
					System.exit(0);
					break;
			}
			sc.close();
		}
	}
}