/**
 * The compareTo() method compares two strings lexicographically. The comparison is based on the
 * Unicode value of each character in the strings. The method returns 0 if the string is equal to the
 * other string. If not, it returns positive or negative value. The result is positive if the first
 * string is lexicographically greater than the second string else the result would be negative
 */
public class compare {
	public static void main(String[] args) {
		String name[] = { "Madras", "Delhi", "Bangalore", "Calcutta" };
		int size = name.length;
		String temp = null;
		for (int i = 0; i < size; i++) {
			for (int j = i + 1; j < size; j++) {
				if (name[j].compareTo(name[i]) < 0) {
					temp = name[i];
					name[i] = name[j];
					name[j] = temp;
				}
			}
		}
		for (int i = 0; i < size; i++) {
			System.out.println(name[i]);
		}
	}
}
