import java.util.Scanner;

class Factorial {
	public static int factorial(int a) {
		if (a < 0) {
			System.out.println("Wrong input");
			return -1;
		}
		else if(a == 0) {
			return 1;
		}
		else {
			int prod = 1;
			for(int i = 1; i<=a; ++i) {
				prod *= i;
			}
			return prod;
		}
	}

	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter n: ");
		int n  = sc.nextInt();
		System.out.println("Enter r: ");
		int r = sc.nextInt();

		int ncr = factorial(n)/(factorial(r)*factorial(n-r));
		System.out.println(n+"C"+r + " = "+ncr); 	
	}
}