import java.util.Scanner;

class Mixer{
	int arr[];

	Mixer(int[] a) {
		arr = a;
	}

	Mixer() {
		accept();
	}

	void accept() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter number of elements: ");
		arr = new int[sc.nextInt()];
		System.out.println("Enter the element of the array: ");
		for (int i = 0; i < arr.length; ++i) arr[i] = sc.nextInt();
	}

	Mixer mix(Mixer a) {
		int duplicates = 0;
		for (int i = 0; i < a.arr.length; ++i) {
			for (int j = 0; j<arr.length; ++j) {
				if (arr[j] == a.arr[i]) duplicates++;
			}
		}
		int new_arr[] = new int[a.arr.length+arr.length-duplicates];
		int aleft = 0;
		int arrleft = 0;
		System.out.println(new_arr.length + "");
		for (int i = 0; i < new_arr.length; ++i) {
			if (i!=0 && this.arr[arrleft] == new_arr[i-1]) arrleft++;
			if (i!=0 && a.arr[aleft] == new_arr[i-1]) aleft++;
			if (a.arr[aleft] >= this.arr[arrleft]) {
				new_arr[i] = this.arr[arrleft];
				arrleft++;
			}
			else {
				new_arr[i] = a.arr[aleft];
				aleft++;
			}
			if (arrleft == this.arr.length) {
				for(++i ;i<new_arr.length; ++i) {
					new_arr[i] = a.arr[aleft];
					aleft++;
				}
				break;
			}
			if (aleft == a.arr.length) {
				for(;i<new_arr.length; ++i) {
					new_arr[i] = this.arr[arrleft];
					arrleft++;
				}
				break;
			}
		}
		return new Mixer(new_arr);
	}

	void display() {
		for(int i = 0; i<arr.length; ++i) System.out.print(arr[i] + " ");
			System.out.println();
	}
}

class MixerTest {
	public static void main(String[] args) {
		Mixer m = new Mixer();
		m.display();
		Mixer m2 = new Mixer();
		m2.display();
		m.mix(m2).display();	
	}
}