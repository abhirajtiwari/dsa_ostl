#include <stdio.h>
#include <stdlib.h>

int sum;

int * add(int *a, int *b) { 
	int *psum;
	psum = &sum;
	*psum = *a + *b;
	return psum;
}

int main() 
{
	printf("Enter 2 numbers: ");
	int a,b;
	int *pa, *pb;
	pa = &a;
	pb = &b;
	scanf("%d %d",pa,pb);
	printf("Sum is %d\n", *add(pa, pb));
}