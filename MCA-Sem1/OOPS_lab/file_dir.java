import java.io.File;

/**
 * It creates a new File instance by converting the given pathname string into an abstract pathname,
 * and then populates the array with names of files and directories
 */
public class file_dir {

	public static void main(String[] args) {
		// Creates an array in which we will store the names of files and directories
		String[] pathnames;

		// Creates a new File instance by converting the given pathname string
		// into an abstract pathname
		File f = new File("C:/Users/1kryo/Code/Personal/MCA/OOPS_lab");

		// Populates the array with names of files and directories
		pathnames = f.list();

		// For each pathname in the pathnames array
		for (String pathname : pathnames) {
			// Print the names of files and directories
			System.out.println(pathname);
		}
	}
}