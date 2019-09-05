import java.util.Scanner;

class Complex {
	public double real;
	public double imaginary;

	Complex(double r, double i) {
		this.real = r;
		this.imaginary = i;
	}

	void print() {
		System.out.println(this.real + " + i" + this.imaginary);
	}

	Complex addComplex(Complex b) {
		Complex ans = new Complex(this.real+b.real, this.imaginary+b.imaginary);
		return ans;
	}

	Complex subtractComplex(Complex b) {
		Complex ans = new Complex(this.real-b.real, this.imaginary-b.imaginary);
		return ans;
	}
}

class ComplexTest {
	public static void main (String args[]) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter a complex number: ");
		double r, i;
		r = sc.nextDouble();
		i = sc.nextDouble();
		Complex a = new Complex(r, i);
		a.print();
		Complex b = a.addComplex(new Complex(2.0,2.0));
		b.print();
	} 
}
