public class multithread {

	int counter = 1;
	static int max = 10;

	public static void main(String[] args) {
		final multithread mt = new multithread();

		Thread t1 = new Thread(new Runnable() {
			public void run() {
				mt.printOddNumber();
			}
		}, "Odd-Thread");

		Thread t2 = new Thread(new Runnable() {
			public void run() {
				mt.printEvenNumber();
			}
		}, "Even-Thread");

		t1.start();
		t2.start();

	}

	public void printOddNumber() {
		synchronized (this) {
			while (counter < max) {
				while (counter % 2 == 0) {
					try {
						wait();
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
				System.out.println(Thread.currentThread().getName() + "\t" + counter);
				counter++;
				notify();
			}
		}
	}

	public void printEvenNumber() {
		synchronized (this) {
			while (counter < max) {
				while (counter % 2 != 0) {
					try {
						wait();
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
				System.out.println(Thread.currentThread().getName() + "\t" + counter);
				counter++;
				notify();
			}
		}
	}
}