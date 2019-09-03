#include <stdio.h>
#include <stdlib.h>

void reverse(int* a, int n) {
	int* start = a;
	int* current;
	current=a;
	a+=(n-1);
	int temp;
	for(int i = 0; i < n/2; ++i) {
		temp = *current;
		*current = *a;
		*a = temp;
		a--;
		current++;
	}
	for(int i = 0; i < n; ++i) {
		printf("%d ", *start);
		start++;
	}
	printf("\n");
}

int main() {
	printf("Enter the number of elements in the array: ");
	int *input_arr;
	int n;
	scanf("%d", &n);

	input_arr = (int *)malloc(n*sizeof(int));
	int *starting = input_arr;
	for(int i = 0; i < n; ++i) {
		scanf("%d", input_arr);
		input_arr++;
	}
	input_arr=starting;
	reverse(input_arr, n);
	free(starting);
}