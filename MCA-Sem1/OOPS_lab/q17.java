/**
 * A class that extends Thread and overrides the run() method is a thread
 */
public class q17 {
	public static void main(String[] args) {
		A a = new A();
		B b = new B();
		C c = new C();
		a.start();
		b.start();
		c.start();
	}
}

class A extends Thread {
	public void run() {
		while (true) {
			try{
				Thread.sleep(1000);
			}
			catch (InterruptedException e) {
				System.out.println(e);
			}
			System.out.println("Good Morning");
		}
	}
}

class B extends Thread {
	public void run() {
		while (true) {
			try {
				Thread.sleep(2000);
			} catch (InterruptedException e) {
				System.out.println(e);
			}
			System.out.println("Hello");
		}
	}
}

class C extends Thread {
	public void run() {
		while (true) {
			try {
				Thread.sleep(3000);
			} catch (InterruptedException e) {
				System.out.println(e);
			}
			System.out.println("Welcome");
		}
	}
}
