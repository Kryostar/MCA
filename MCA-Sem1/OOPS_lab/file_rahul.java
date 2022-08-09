import java.io.File;

public class file_rahul {
	private static void listFiles(String path, int index) {
		File folder = new File(path);
		File[] files = folder.listFiles();
		for (File file : files) {
			for (int i = 0; i < index; i++) {
				System.out.print(" |.. ");
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