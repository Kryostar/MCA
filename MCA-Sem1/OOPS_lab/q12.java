// 12. Write a program to demonstrate abstract class and abstract methods

/**
 * The Bank class is an abstract class that defines the getRateOfInterest() method
 */
abstract class Bank {
	abstract int getRateOfInterest();
}
 
/**
 * SBI is a Bank that returns 7% interest.
 */
class SBI extends Bank {
	int getRateOfInterest() {
		return 7;
	}
}

/**
 * PNB is a Bank that has a getRateOfInterest method that returns 8
 */
class PNB extends Bank {
	int getRateOfInterest() {
		return 8;
	}
}

/**
 * The class Bank is an abstract class and it has an abstract method getRateOfInterest(). 
 * 
 * The classes SBI and PNB are the subclasses of Bank and they are overriding the method
 * getRateOfInterest(). 
 * 
 * The class q12 is creating the object of SBI and PNB classes and calling the method
 * getRateOfInterest() by the reference variable of Bank
 */
class q12 {
	public static void main(String args[]) {
		Bank b;
		b = new SBI();
		System.out.println("Rate of Interest is: " + b.getRateOfInterest() + " %");
		b = new PNB();
		System.out.println("Rate of Interest is: " + b.getRateOfInterest() + " %");
	}
}