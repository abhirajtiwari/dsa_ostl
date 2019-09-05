import java.util.Scanner;

class QuadraticRoots {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Input a of the quadratic equation: ");
		double a = sc.nextDouble();
		System.out.println("Input b of the quadratic equation: ");
		double b = sc.nextDouble();
		System.out.println("Input c of the quadratic equation: ");
		double c = sc.nextDouble();

		double d = Math.pow(b,2) - 4*a*c;
		char roots = 'r';
		if (d>=0) roots = 'r';
		else roots = 'i';

		switch (roots) {
			case 'r':
				double root1 = (-b + Math.sqrt(d))/(2*a);
				double root2 = (-b - Math.sqrt(d))/(2*a);
				System.out.println("Roots are real.\nRoot 1: " + root1 + "\tRoot 2: " + root2);
				break;
			case 'i':		
				double r = -b/(2*a);
				double i = Math.sqrt(Math.abs(d))/(2*a);
				System.out.println("Roots are imaginary.\nRoot 1: " + r + "+i" + i + "\tRoot 2: " + r + "-i" + i);
				break;
		}
		

		
	}
}