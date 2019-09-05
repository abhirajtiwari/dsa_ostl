import java.util.Scanner;

class ScannerExample {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		sc.nextLine(); //To consume the \n character from the console.
		String b = sc.nextLine();
		System.out.println("Values are " + a + " and " + b);
	}
}