#include <stdio.h>
#define MAXIMUM 100

typedef struct {
	int top;
	int st[MAXIMUM];
} STACK;

int isEmpty(STACK* a) {
	if ((a->top) == -1) return 1;
	return 0;
}

void printStack(STACK* a)  { 
	for (int i = (a->top); i >= 0; --i) { 
		printf("%d \n", a->st[i]); 
	} 
}

void pushStack(STACK* a, int n) {
	if (a->top == MAXIMUM-1) {
		printf("Overflow!!n");
		return;
	}
	else {
		(a->top)++;
		a->st[(a->top)]=n;
	}
}

int popStack(STACK* a) {
	if (a->top == -1) {
		printf("Underflow!!\n");
		return -1;
	}
	else {
		return a->st[(a->top)--];
	}
}

int peekStack(STACK *a) {
	if (a->top == -1) return -1;
	return a->st[a->top];
}
