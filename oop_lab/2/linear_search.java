import java.util.Scanner;

class LinearSearch {
	public static int linearSearch(int[] a, int query) {
		int n = a.length;
		for (int i = 0; i < n; ++i) {
			if (a[i] == query) return i;
		}
		return -1;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the size array: ");
		int n = sc.nextInt();
		int arr[] = new int[n]; 
		System.out.println("Enter the array: ");
		for (int i = 0; i<n; ++i) arr[i] = sc.nextInt();

		System.out.println("Enter the number to search: ");
		int q = sc.nextInt();

		int pos = linearSearch(arr, q);
		if (pos==-1) System.out.println("The given element does not exist in this array.");
		else System.out.println("The given element was found at " + pos + ".");
	}
}