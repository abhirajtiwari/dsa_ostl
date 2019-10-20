#include <stdio.h>
#include <stdlib.h>

typedef struct node* nodeptr;
struct node {
	int data;
	nodeptr next;
};

nodeptr getNode(int val) {
	nodeptr newnode = (nodeptr) malloc(sizeof(nodeptr));
	newnode->data = val;
	newnode->next = NULL;
	return newnode;
}

void insertEnd(nodeptr start, nodeptr n) {
	nodeptr temp = start;
	while (temp->next) {
		temp = temp->next;	
	}	
	temp->next = n;
	n->next = NULL;
}

void insertFront(nodeptr* start, nodeptr n) {
	nodeptr temp = *start;
	n->next = temp;
	*start = n;
}

void deleteEnd(nodeptr start) {
	nodeptr temp = start;
	nodeptr second_last = NULL;
	while (temp->next) {
		second_last = temp;
		temp = temp->next;
	}
	second_last->next = NULL;
	free(temp);
}

void deleteFront(nodeptr* start) {
	nodeptr temp = *start;
	*start = (*start)->next;
	free(temp);
}

void printLL (nodeptr start) {
	nodeptr temp = start;
	while (temp->next) {
		printf("%d ", temp->data);
		temp = temp->next;
	} 
	printf("%d ", temp->data);
	printf("\n");
}
