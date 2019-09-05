import java.util.Scanner;
import java.util.GregorianCalendar;

class Student {
		private int regno;
		static int counter = 0;
		String name;
		GregorianCalendar date;
		short sem;
		float gpa;
		float cgpa;

		Student() {
			Scanner sc = new Scanner(System.in);
			System.out.println("Enter the name of student: ");
			this.name = sc.nextLine();
			System.out.println("Enter the date of joining: ");
			this.date = new GregorianCalendar(sc.nextInt(), sc.nextInt(), sc.nextInt());
			System.out.println("Enter semester number: ");
			this.sem = sc.nextShort();
			System.out.println("Enter GPA: ");
			this.gpa = sc.nextFloat();
			System.out.println("Enter CGPA: ");
			this.cgpa = sc.nextFloat();
			this.regno = Integer.parseInt("" + this.date.get(GregorianCalendar.YEAR)%100 + this.counter);
			this.counter++; 
		}

		Student(String name, GregorianCalendar date, short sem, float gpa, float cgpa) {
			this.name = name;
			this.date = date;
			this.sem = sem;
			this.gpa = gpa;
			this.cgpa = cgpa;
			this.regno = Integer.parseInt("" + (this.date.get(GregorianCalendar.YEAR)%100) + this.counter);
			this.counter++;
		}

		void display() {
			System.out.println("Registration Number: " + this.regno);
			System.out.println("Name: " + this.name);
			System.out.println("Date of joining: " + this.date.get(GregorianCalendar.DATE) + "/" + this.date.get(GregorianCalendar.MONTH) + "/" + this.date.get(GregorianCalendar.YEAR));
			System.out.println("Semester: " + this.sem);
			System.out.println("GPA: " + this.gpa);
			System.out.println("CGPA: " + this.cgpa);			
			System.out.println("-----------------------------------------");
		}

		static Student[] sortSemCG(Student a[]) {

		}

		static Student[] sortName(Student a[]) {

		}

		/*private Student[] sortField(Student a[], String field) {
			boolean swapped = true;
			for (int i = 0; swapped && i < a.length; ++i) {
				swapped = true;
				a[i].getField(field);
			}
		} */ //Can this sort of code work?? i.e. a dynamic sorter
}		

class TestStudent {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter number of students: ");
		int n = sc.nextInt();		
		Student[] arr = new Student[n];
		for (int i = 0; i < n; ++i) {
			arr[i] = new Student();
			System.out.println("");
		}
		System.out.println("");
		for (int i = 0; i < n; ++i) {
			arr[i].display();
		}
	}
}
