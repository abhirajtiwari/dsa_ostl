#include <stdio.h>
#include <stdlib.h>

void print_mat(int** m, int r, int c) {
	int i = 0;
	int j = 0;
	for(i=0; i<r; ++i) {
		for(j=0; j<c; ++j) {
			printf("%d ", *(*(m+i)+j));
		}
		printf("\n");
	}
}

int main() {
	//get the dimensions
	printf("Enter size of first matrix: ");
	int ia, ja;
	scanf("%d %d", &ia, &ja);

	printf("Enter size of second matrix: ");
	int ib, jb;
	scanf("%d %d", &ib, &jb);

	//allocate the memory to the 2d arrays
	int** a;
	a = (int **)calloc(ia, ia*sizeof(int *));
	for (int i = 0; i < ia; ++i) *(a+i) = (int *)calloc(ja, sizeof(int));
	int** b;	
	b = (int **)calloc(ib, ib*sizeof(int *));
	for (int i = 0; i < ib; ++i) *(b+i) = (int *)calloc(jb, sizeof(int));

	//get input
	for(int i = 0; i < ia; ++i) {
		for(int j = 0; j < ja; ++j) {
			scanf("%d", *(a+i)+j);
		}
	}
	for(int i = 0; i < ib; ++i) {
		for(int j = 0; j < jb; ++j) {
			scanf("%d", *(b+i)+j);
		}
	}

	//allocate memory to store the product
	int** p;
	p = (int **)calloc(ia, sizeof(int *));
	for(int i = 0; i<ia; ++i) *(p+i) = (int *)calloc(jb, sizeof(int));

	//product
	int temp_sum = 0;
	for(int i = 0; i<ia; ++i) {
		for(int k = 0; k<jb; ++k) {
			for(int l = 0; l<ib; ++l){
				temp_sum += (*(*(a+i)+l))*(*(*(b+l)+k));
			}
			*(*(p+i)+k) = temp_sum;
			temp_sum = 0;
		}
	}
	print_mat(p, ia, jb);
	free(a);
	free(b);
}