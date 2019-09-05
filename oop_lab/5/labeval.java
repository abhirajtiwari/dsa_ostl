import java.util.Scanner;

class Distance {
	private int feet;
	private float inches;
	Distance(int ft, float in) {
		this.feet = ft;
		this.inches = in;
		this.adjust();
	}
	Distance add(Distance a) {
		Distance total = new Distance(this.feet + a.getFeet(), this.inches + a.getIn());
		return total;
	}
	Distance add(Distance a, Distance b) {
		Distance total = new Distance(this.feet + a.getFeet() + b.getFeet(), this.inches + a.getIn() + b.getIn());
		return total;
	}
	void adjust() {
		this.feet += this.inches/12;
		this.inches = this.inches%12;
	}
	int getFeet() {
		return this.feet;
	}
	float getIn() {
		return this.inches;
	}
	void disp() {
		System.out.println(this.feet + "ft " + this.inches + "in ");
	}
}

class TestDistance {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter 3 distances: ");
		Distance a = new Distance(sc.nextInt(), sc.nextFloat());
		Distance b = new Distance(sc.nextInt(), sc.nextFloat());
		Distance c = new Distance(sc.nextInt(), sc.nextFloat());
		System.out.println("The 3 entered values are: ");
		a.disp();
		b.disp();
		c.disp();
		Distance tot2 = a.add(b);
		Distance tot3 = a.add(b, c);
		System.out.println("Sum of a and b is: ");
		tot2.disp();
		System.out.println("Sum of a, b and c is: ");
		tot3.disp();
	}
}