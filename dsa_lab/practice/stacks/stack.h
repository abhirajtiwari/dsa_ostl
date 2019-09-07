#include <stdio.h>

#define MAX 100

typedef struct {
	int top;
	int st[MAX];
} STACK;

int isFull(STACK* a) {
	if (a->top == (MAX-1)) return 1;
	return 0;
}

int isEmpty(STACK* a) {
	if (a->top == -1) return 1;
	return 0;
}

void push(STACK* a, int ele) {
	if (isFull(a)) printf("Overflow Error");
	else {
		a->st[++(a->top)] = ele;
	}
}

void pop(STACK* a) {
	if (isEmpty(a)) printf("Underflow error");
	else {
		(a->top)--;
	}
}

int peek(STACK* a) {
	return a->st[a->top];
}
