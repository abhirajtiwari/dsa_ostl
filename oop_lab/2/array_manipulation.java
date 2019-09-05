import java.util.Scanner;

class ArrayManipulation {
	public static int[] insertElement(int[] a, int e, int pos){
		int  n = a.length;
		for(int i = n-2; i >= pos; --i) {
			a[i+1] = a[i];
		}
		a[pos] = e;
		return a;
	}

	public static int[] deleteElement(int[] a, int pos) {
		int n = a.length;
		for(int i = pos; i<n-2; ++i) {
			a[i] = a[i+1];
		}
		return a;
	}

	public static void main(String[] args) throws java.io.IOException {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the size array: ");
		int n = sc.nextInt()+1; //+1 so that we can add or delete an element later
		int arr[] = new int[n]; 
		System.out.println("Enter the array: ");
		for (int i = 0; i<n-1; ++i) arr[i] = sc.nextInt();

		System.out.println("[i]nsert an element. [d]elete an element: ");
		char response = (char) System.in.read();

		System.out.println("Enter the position: ");
		int position = sc.nextInt();

		switch (response) {
			case 'i':
				int ele = sc.nextInt();
				arr = insertElement(arr, ele, position);
				n = arr.length;
				break;
			case 'd':
				arr = deleteElement(arr, position);
				n = arr.length-2;
				break;
		}
		for(int i = 0; i<n; ++i) System.out.print(arr[i] + " ");
	}
}