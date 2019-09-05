import java.util.Scanner;

class LargestNumber {
	public static int largest(int a, int b, int c){
		int largest = a;
		if (b>a) {
			if (b>c) largest = b;
			else largest = c;
		}
		else if (c>a) largest = c;
		return largest;
	} 

	public static void main(String args[]) {
		System.out.println("Enter 3 numbers: ");
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		sc.nextLine();
		int b = sc.nextInt();
		sc.nextLine();
		int c = sc.nextInt();
		sc.nextLine();
		int largest = largest(a, b, c);
		System.out.println("The largest number is " + largest);
	}
}