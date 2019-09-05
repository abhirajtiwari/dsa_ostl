import java.util.Scanner;

class Matrix {
	public static int[][] addMat(int a[][], int b[][]) {
		int im = a.length;
		int jm = a[0].length;
		int[][] sum = new int[im][jm];
		for(int i = 0; i<im; ++i) {
			for(int j = 0; j<jm; ++j) {
				sum[i][j] = a[i][j] + b[i][j];
			}
		}
		return sum;
	}

	public static void printMat(int a[][]) {
		int im = a.length;
		int jm = a[0].length;
		for(int i = 0; i<im; i++) {
			for(int j = 0; j<jm; ++j) {
				System.out.print(a[i][j] + " ");
			}
			System.out.println();
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the dimentions of matrix A: ");
		int ia = sc.nextInt();
		int ja = sc.nextInt();

		System.out.println("Enter the dimensions of matrix B: ");
		int ib = sc.nextInt();
		int jb = sc.nextInt();

		if(ia != ib && ja != jb) {
			System.out.println("These matrices cannot be added.");
			return;
		}

		System.out.println("Enter matrix A: ");
		int[][] mata = new int[ia][ja];
		for(int i = 0; i<ia; ++i) {
			for(int j = 0; j<ja; ++j) {
				mata[i][j] = sc.nextInt();
			}
		}

		System.out.println("Enter matrix B: ");
		int[][] matb = new int[ib][jb];
		for(int i = 0; i<ib; ++i) {
			for(int j = 0; j<jb; ++j) {
				matb[i][j] = sc.nextInt();
			}
		}

		int[][] matsum = addMat(mata, matb);
		System.out.println("Sum of A and B is: ");
		printMat(matsum);
	}
}