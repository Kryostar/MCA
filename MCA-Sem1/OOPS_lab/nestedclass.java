class outerclass {
	int x = 10;

	class InnerClass {
		int y = 5;
	}
}

public class nestedclass {
	public static void main(String[] args) {
		outerclass a = new outerclass();
		outerclass.InnerClass b = a.new InnerClass();
		System.out.println(b.y + a.x);
	}
}