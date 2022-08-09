import java.io.*;

/**
 * It copies the contents of a file to another file
 */
public class q18 {
	private static final int BUFFER_SIZE = 4096;

	public static void main(String[] args) {
		String inputFile = "C:/Users/1kryo/Documents/GitHub/MCA/MCA-Sem1/PS-Upgrade.txt";
		String outputFile = "C:/Users/1kryo/Documents/GitHub/MCA/MCA-Sem1/OOPS_lab/out.txt";

		try (
				InputStream inputStream = new FileInputStream(inputFile);
				OutputStream outputStream = new FileOutputStream(outputFile);) {

			byte[] buffer = new byte[BUFFER_SIZE];
			int bytesRead = -1;

			while ((bytesRead = inputStream.read(buffer)) != -1) {
				outputStream.write(buffer, 0, bytesRead);
			}
		} catch (IOException ex) {
			ex.printStackTrace();
		}
	}
}