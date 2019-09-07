#include "dynstack.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
	STACK stack;
	stack.top = -1;
	stack.st = (int *)malloc(10*sizeof(int));
	push(&stack, 1);
	push(&stack, 2);
	printf("%d", peek(&stack));
	pop(&stack);
	printf("%d", peek(&stack));
	pop(&stack);
	pop(&stack);
}
