
public class dispatch_new {
	public static void main(String[] args) {
		Animal a = new Animal();
		Dog b = new Dog();
		a.move();
		b.move();
	}
}

class Animal {
	public void move() {
		System.out.println("Animal");
	}
}

class Dog extends Animal {
	public void move() {
		System.out.println("Dog");
	}
}
