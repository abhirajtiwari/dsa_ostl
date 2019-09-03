#include <stdio.h>
#include "stack.h"

void printBin(STACK* a) {
	while (a->top != 0) printf("%d", popStack(a));
	printf("\n");
}

int main() {
	printf("Enter a number: ");
	int input;
	scanf("%d", &input);
	STACK bin;
	bin.top=0;

	while (input > 0) {
		pushStack(&bin, input%2);
		input/=2;
	}
	printBin(&bin);
}