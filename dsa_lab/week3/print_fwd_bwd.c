#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("Enter number of elements: ");
	int n;
	scanf("%d", &n);

	int* p;
	p = (int *)malloc(n*sizeof(int));
	printf("Enter elements of the array.\n");
	for(int i = 0; i <n; ++i) scanf("%d", p+i);

	printf("Printing forward...\n");
	for(int i = 0; i < n; ++i) printf("%d ", *(p+i));

	printf("\nPrinting backward...\n");
	for(int i = n-1; i>=0; --i) printf("%d ", *(p+i));
}