public class ProducerConsumerTest {
	public static void main(String[] args) {
		Sp c = new Sp();
		Producer p1 = new Producer(c, 1);
		Consumer c1 = new Consumer(c, 1);
		p1.start();
		c1.start();
	}
}

class Sp {
	private int contents;
	private boolean available = false;

	public synchronized int get() {
		while (available == false) {
			try {
				wait();
			} catch (InterruptedException e) {
			}
		}
		available = false;
		notifyAll();
		return contents;
	}

	public synchronized void put(int value) {
		while (available == true) {
			try {
				wait();
			} catch (InterruptedException e) {
			}
		}
		contents = value;
		available = true;
		notifyAll();
	}
}

class Consumer extends Thread {
	private Sp space;
	private int number;

	public Consumer(Sp c, int number) {
		space = c;
		this.number = number;
	}

	public void run() {
		int value = 0;
		for (int i = 0; i < 10; i++) {
			value = space.get();
			System.out.println("Consumer #" + this.number + " got: " + value);
		}
	}
}

class Producer extends Thread {
	private Sp space;
	private int number;

	public Producer(Sp c, int number) {
		space = c;
		this.number = number;
	}

	public void run() {
		for (int i = 0; i < 10; i++) {
			space.put(i);
			System.out.println("Producer #" + this.number + " put: " + i);
			try {
				sleep((int) (Math.random() * 100));
			} catch (InterruptedException e) {
			}
		}
	}
}
