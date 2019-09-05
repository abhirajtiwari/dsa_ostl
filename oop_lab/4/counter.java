class Counter {
	static int count = 0;

	Counter() {
		count++;
	}

	static int getCount() {
		return count;
	}
}

class CounterTest {
	public static void main(String args[]) {
		System.out.println(Counter.getCount());
		Counter a = new Counter();
		System.out.println(Counter.getCount());
		Counter b = new Counter();
		System.out.println(Counter.getCount());
	}
}	