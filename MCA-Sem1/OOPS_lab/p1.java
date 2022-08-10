public class p1 {
	public static void main(String[] args) {
		int a = 10, b = 5, c = 20;
		int x = ++a - b + c++ + a * b + c * a - --b + c % b * a;
		System.out.println("before overriding the operator precedence: " + x);
		System.out.println("updated a b c values are: " + a + "\t" + b + "\t" + c);
		int y = (++a - b) * c++ + a * b + c * (a - --b) + c % b * a;
		System.out.println("the value of y is: " + y);
		System.out.println("values of a, b & c is: " + a + "\t" + b + "\t" + c);
	}
}