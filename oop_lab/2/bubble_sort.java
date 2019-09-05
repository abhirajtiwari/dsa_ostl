import java.util.Scanner;

class ArraySort {
	public static int[] bubbleSort(int[] a, char ord) {
		int len = a.length;
		boolean swapped = true;
		while (swapped) {
			swapped = false;
			for(int i = 0; i<len-1 ; ++i) {
				if (a[i] > a[i+1] && ord == 'a') {
					int temp = a[i];
					a[i] = a[i+1];
					a[i+1] = temp;
					swapped = true;
				}
				else if (a[i] < a[i+1] && ord == 'd') {
					int temp = a[i];
					a[i] = a[i+1];
					a[i+1] = temp;
					swapped = true;
				}
			}
		}
		return a;
	}

	public static void main(String[] args) throws java.io.IOException {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the size array: ");
		int n = sc.nextInt();
		int arr[] = new int[n]; 
		System.out.println("Enter the array: ");
		for (int i = 0; i<n; ++i) arr[i] = sc.nextInt();
		System.out.println("Sort [a]scending or [d]escending: ");
		char order  = (char) System.in.read();
		arr = bubbleSort(arr, order); 
		for(int i = 0; i<n; ++i) System.out.print(arr[i] + " ");
	}              
}