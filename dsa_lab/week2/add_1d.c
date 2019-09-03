#include <stdio.h>
#include <stdlib.h>

int main() {
	printf ("Enter the number of elements in the array: ");
	int n;
	scanf("%d", &n);
	int *arr;
	arr = (int *)malloc(n*sizeof(int));
	int *start = arr;

	printf("Enter the elements of the array: ");
	for(int i = 0; i < n; ++i) {
		scanf("%d", arr);
		arr++;
	}
	arr=start;

	//add
	int sum = 0;
	for(int i = 0; i < n; ++i) {
		sum+=(*arr);
		arr++;
	}
	printf("sum is %d\n", sum);
	free(start); 	
}