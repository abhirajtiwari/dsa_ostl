import java.util.*;

class SwitchArray<T> {
	T[] array;
	int n;

	SwitchArray(T[] input, int l) {
		array = input;
		n = l;
	}

	public void switchEle(int i, int j) {
		T temp;
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}

	public void printSA() {
		for (int i = 0; i < n; ++i) {
			System.out.print(array[i].toString());
			System.out.print(' ');
		}
		System.out.println();
	}
}

class SATester {
	public static void main(String[] args) {
		Integer[] a = new Integer[] {0, 1, 2, 3, 4};
		SwitchArray<Integer> sa = new SwitchArray<Integer>(a, 5);
		sa.printSA();
		sa.switchEle(2, 3);
		sa.printSA();
	}
}