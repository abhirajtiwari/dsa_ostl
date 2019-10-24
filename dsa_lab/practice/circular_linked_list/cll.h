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
	newnode->next = newnode;
	return newnode;
}

void insertEnd(nodeptr start, nodeptr n) {
	nodeptr temp = start->next->next;
	while (temp->next != start->next) {
		temp = temp->next;
	}
	temp->next = n;
	n->next = start->next;
}

void insertFront(nodeptr* start, nodeptr n) {
	nodeptr temp = (*start)->next;
	int first_time = 1;
	while (temp->next != (*start)->next || first_time) {
		first_time = 0;
		temp = temp->next;
	}
	temp->next = n;
	n->next = (*start)->next;
	(*start)->next = n;
}

void deleteEnd(nodeptr start) {
	nodeptr temp = start->next;
	nodeptr prev;
	int first_time = 1;
	while (temp->next != start->next || first_time) {
		first_time = 0;
		prev = temp;
		temp = temp->next;
	}
	prev->next = start->next;
	free(temp);
}

void deleteFront(nodeptr* start) {
	nodeptr last = (*start)->next;
	int first_time = 1;
	while (last->next != (*start)->next || first_time) {
		first_time = 0;
		last = last->next;
	}
	last->next = (*start)->next->next;
	free((*start)->next);
	(*start)->next = last->next;
}

void printCLL(nodeptr start) {
	nodeptr temp = start->next;
	int first_time = 1;
	while (temp->next != start->next || first_time) {
		first_time = 0;
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("%d\n", temp->data);
}
