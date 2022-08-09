public class q16 {
	public static void main(String[] args) {
		new A().start();
		new B().start();
		new C().start();
	}
}

class A extends Thread {
	public void run() {
		System.out.println("A");
	}
}

class B extends Thread {
	public void run() {
		System.out.println("B");
	}
}

class C extends Thread {
	public void run() {
		System.out.println("C");
	}
}
