public class dispatch_new {
	public static void main(String[] args) {
		A a = new A();
		A b = new B();
		a.move();
		b.move();
	}
}

class A {
	public void move() {
		System.out.println("A");
	}
}

class B extends A {
	public void move() {
		System.out.println("B");
	}
}
