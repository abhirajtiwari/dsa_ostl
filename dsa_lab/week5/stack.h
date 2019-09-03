#define MAXIMUM 100

typedef struct {
	int top;
	int st[MAXIMUM];
} STACK;

void printStack(STACK* a)  { 
	for (int i = (a->top)-1; i >= 0; --i) { 
		printf("%d \n", a->st[i]); 
	} 
}

void pushStack(STACK* a, int n) {
	if (a->top == MAXIMUM) {
		printf("Overflow!!n");
		return;
	}
	else {
		a->st[(a->top)]=n;
		(a->top)++;
	}
}

int popStack(STACK* a) {
	if (a->top == 0) {
		printf("Underflow!!\n");
		return -1;
	}
	else {
		(a->top)--;
		return a->st[(a->top)];
	}
}