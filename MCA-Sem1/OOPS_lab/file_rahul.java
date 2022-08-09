import java.io.File;
// Question 19
public class file_rahul {
	/**
	 * It takes a path and an index as parameters. It creates a File object with the path. It creates a
	 * File array with the list of files in the folder. It loops through the files and prints the name of
	 * the file. If the file is a directory, it prints the name of the directory and calls the function
	 * again with the path of the directory and an incremented index
	 * 
	 * @param path The path of the directory to be listed.
	 * @param index This is the number of spaces to print before the file or directory name.
	 */
	private static void listFiles(String path, int index) {
		File folder = new File(path);
		File[] files = folder.listFiles();
		for (File file : files) {
			for (int i = 0; i < index; i++) {
				System.out.print("|..");
			}
			if (file.isFile()) {
				System.out.println(file.getName());
			} else if (file.isDirectory()) {
				System.out.println("[" + file.getName() + "]");
				listFiles(file.getAbsolutePath(), index + 1);
			}
		}
	}

	public static void main(String[] args) {
		listFiles("C:/Users/1kryo/Documents/Github/MCA/MCA-Sem1", 0);
	}
}