#include "tree.h"

#pragma once

struct nodeptrQ {
	int front;
	int rear;
	nodeptr arr[50];
};

struct nodeptrQ Q;

void initQ() {
	Q.front = -1;
	Q.rear = -1;
}

void enq(nodeptr data) {
	Q.arr[++Q.rear] = data;
}

nodeptr dq() {
	return Q.arr[++Q.front];
}

int isEmpty() {
	if (Q.front != -1 && Q.front==Q.rear) return 1;
	return 0;
}

void levelorderR(nodeptr root) {
	fflush(stdout);
	printf("%d ", root->data);
	if (root->lst!=NULL) enq(root->lst);
	if (root->rst!=NULL) enq(root->rst);
	if (!isEmpty()) levelorderR(dq());
	else return;
}
