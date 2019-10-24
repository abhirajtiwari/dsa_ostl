#include "tree.h"

struct stack {
	int top;
	nodeptr arr[50];
} st;

void push(nodeptr n) {
	if (st.top == 50) printf("Overflow!!\n");
	st.arr[++st.top] = n;
}

nodeptr pop() {
	if (st.top == -1) printf("Underflow!\n");
	return st.arr[st.top--];
}

void initStack() {
	st.top = -1;
}

void inorderI(nodeptr root) {
	nodeptr temp = root;
	while (1) {
		while (temp != NULL) {
			push(temp);
			temp = temp->lst;
		}
		temp = pop();
		printf("%d ", temp->data);
		temp = temp->rst;
		if (temp == NULL && st.top == -1) break;
	}
}

void preorderI(nodeptr root) {
	nodeptr temp = root;
	while (1) {
		while (temp != NULL) {
			printf("%d ", temp->data);
			push(temp);
			temp = temp->lst;
		}
		temp = pop();
		temp = temp->rst;
		if (temp == NULL && st.top == -1) break;
	}
}

void postorderI(nodeptr root) {
	nodeptr temp = root;
	while (1) {
		while (temp != NULL) {
			push(temp);
			temp = temp->lst;
		}
		temp = pop();
		temp = temp->rst;
		if (temp == NULL && st.top != -1) {
			temp = pop();
			printf("%d ", temp->data);
		}
		if (temp == NULL && st.top == -1) break;
	}
}
