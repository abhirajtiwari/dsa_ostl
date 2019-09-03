#include <stdio.h>

int sum_of_array(int *a, int n) {
	int sum = 0;
	int k = 0;
	for (k=0; k<n; k++){
		sum += a[k];
	}
	return sum;
}

int second_largest(int *a, int n) {
	int largest = a[0];
	int k;
	int second = a[0];
	for(k=0; k<n; k++) {
		if (a[k] > largest) {
			second = largest;
			largest = a[k];
		} 
		else if (a[k] > second) {
			second = a[k];
		}
	}
	return second;
}

void print_mat(int a[100][100], int r, int c) {
	int i = 0;
	int j = 0;
	for(i=0; i<r; ++i) {
		for(j=0; j<c; ++j) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

int p[100][100];
void product(int a[100][100], int ra, int ca, int b[100][100], int rb, int cb) {
	int i = 0, k = 0, l = 0;
	int temp_sum = 0;
	int p[ra][cb];
	for(i = 0; i<ra; ++i) {
		for(k = 0; k<cb; ++k) {
			for(l = 0; l<rb; ++l){
				temp_sum += a[i][l]*b[l][k];
			}
			printf("Tempsum %d\n", temp_sum);
			p[i][k] = temp_sum;
			temp_sum = 0;
		}
	}
}


int main() {
	int i = 0,j = 0;
	int n = 0;
	int input_arr[100];
	printf("[1] Find sum of given n numbers\n");
	printf("[2] Linear search \n");
	printf("[3] Product of 2 matrices\n");
	printf("[4] Find 2nd largest\n");

	int choice = 0;
	printf(">> ");
	scanf("%d", &choice);

	switch (choice) {
		//Sum of numbers
		case 1:
			printf("Enter number of numbers being entered: ");
			scanf("%d", &n);
			printf("Enter the numbers:\n");
			for(i=0; i<n; ++i) {
				scanf("%d", &input_arr[i]);
			}
			printf("%d\n", sum_of_array(input_arr, n));
			break;

		//Linear search
		case 2:
			printf("Enter the size of array: ");
			scanf("%d", &n);
			printf("Enter the numbers:\n");
			for(i=0; i<n; ++i) {
				scanf("%d", &input_arr[i]);
			}
			int search_query;
			printf("Enter the number to be searched: ");
			scanf("%d", &search_query);
			for (i=0; i<n; i++) {
				if (input_arr[i] == search_query) {
					printf("Element found at %d\n", i);
					break;
				}
			}
			break;

		//Product of matrices
		case 3:
			//Get first matrix
			printf("Enter the size of matrix A [i j]: ");
			int ima, jma;
			scanf("%d %d", &ima, &jma);
			int mata[100][100];
			printf("Enter the elements of the matrix:\n ");
			for(i=0; i<ima; ++i) {
				for(j=0; j<jma; ++j) {
					scanf("%d", &mata[i][j]);
				}
			}

			//Get second matrix
			printf("Enter the size of matrix B [i j]: ");
			int imb = 0, jmb = 0;
			scanf("%d %d", &imb, &jmb);
			int matb[100][100];
			printf("Enter the elements of the matrix:\n ");
			for(i=0; i<imb; ++i) {
				for(j=0; j<jmb; ++j) {
					scanf("%d",&matb[i][j]);
				}
			}

			//Product
			int prodmat[100][100];
			product(mata, ima, jma, matb, imb, jmb);
			print_mat(p, ima, jmb);
			break;

		//2nd largest
		case 4:
			printf("Enter the size of array: ");
			scanf("%d", &n);
			printf("Enter the numbers:\n");
			for(i=0; i<n; ++i) {
				scanf("%d", &input_arr[i]);
			}
			printf("The second largest element is %d\n", second_largest(input_arr, n));
			break;

	}

	return 0;
}