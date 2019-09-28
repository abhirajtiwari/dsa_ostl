import java.util.*;

class Printer {
	synchronized public void printNum (int start, int end) throws InterruptedException {
		System.out.print('[');
		for (int i = start; i <= end; ++i) {
			System.out.print(i + " ");
			Thread.sleep(500);
		}
		System.out.print(']');
		System.out.println();
	}
}

class Pthread extends Thread {
	Printer p;
	int vstart, vend;
	Pthread (String name, int s, int e, Printer pin) {
		super(name);
		p = pin;
		vstart = s;
		vend = e;
		start();
	}
	public void run() {
		try {
			p.printNum(vstart, vend);
		}
		catch (InterruptedException e) {System.out.println("Program Interrupted");}
	}
}

class Driver {
	public static void main(String[] args) {
		Printer ptoin = new Printer();

		Scanner sc = new Scanner(System.in);
		System.out.println("Enter start and end for the 1st thread: ");
		int s1 = sc.nextInt(), e1 = sc.nextInt();
		System.out.println("Enter the start and end for the second thread: ");
		int s2 = sc.nextInt(), e2 = sc.nextInt();
		
		Pthread t1 = new Pthread("thread1", s1, e1, ptoin);
		Pthread t2 = new Pthread("thread2", s2, e2, ptoin);
		try {
			t1.join();
			t2.join();
		}
		catch (InterruptedException e) {System.out.println("Program Interrupted");}
	}
}