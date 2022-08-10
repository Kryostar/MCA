import java.io.File;

// Question 19
public class file_rahul {
	/**
	 * It takes a path to a directory and an index as parameters. It then prints the name of the directory
	 * and calls itself recursively on all the files and directories inside the directory
	 * 
	 * @param path The path of the directory to be listed.
	 * @param index This is the number of "|.." that will be printed before the file name.
	 */
	private static void listFiles(String path, int index) {
		File folder = new File(path);
		File[] files = folder.listFiles();
		for (File file : files) {
			for (int i = 0; i < index; i++)
				System.out.print("|..");
			if (file.isFile())
				System.out.println(file.getName());
			else if (file.isDirectory()) {
				System.out.println("[" + file.getName() + "]");
				listFiles(file.getAbsolutePath(), index + 1);
			}
		}
	}

	public static void main(String[] args) {
		listFiles("C:/Users/1kryo/Documents/Github/MCA/MCA-Sem1", 0);
	}
}