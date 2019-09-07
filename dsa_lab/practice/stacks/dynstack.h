#include <stdio.h>

#define MAX 10

typedef struct {
	int top;
	int* st;
} STACK;

int isEmpty(STACK* a) {
	if (a->top == -1) return 1;
	return 0;
}

int isFull(STACK* a) {
	if (a->top == MAX-1) return 1;
	return 0;
}

void push(STACK* a, int ele) {
	if (isFull(a)) printf("Overflow!!");
	else {
		a->top++;
		*(a->st + a->top) = ele;
	}
}

void pop(STACK* a) {
	if (isEmpty(a)) printf("Underflow!!");
	else {
		a->top--;
	}
}

int peek(STACK* a) {
	return *(a->st + a->top);
}
