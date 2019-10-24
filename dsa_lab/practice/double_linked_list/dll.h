#include <stdio.h>
#include <stdlib.h>

typedef struct node* nodeptr;
struct node {
	int data;
	nodeptr next;
	nodeptr prev;
};

nodeptr getNode(int val) {
	nodeptr newnode = (nodeptr) malloc(sizeof(nodeptr));
	newnode->data = val;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

void insertEnd(nodeptr start, nodeptr n) {
	nodeptr temp = start;
	while (temp->next) {
		temp = temp->next;
	}
	temp->next = n;
	n->prev = temp;
}

void insertFront(nodeptr* start, nodeptr n) {
	nodeptr temp = *start;
	n->next = temp;
	*start = n;
}

void deleteFront(nodeptr* start) {
	nodeptr temp = *start;
	*start = (*start)->next;
	free(temp);
}

void deleteEnd(nodeptr start) {
	nodeptr temp = start;
	while (temp->next) {
		temp = temp->next;
	}
	(temp->prev)->next = NULL;
	free(temp);
}

void printDLL(nodeptr start) {
	nodeptr temp = start;
	while (temp->next) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("%d ", temp->data);
	printf("\n");
}
