#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node{
    int val;
    Node* next;
};


typedef Node* nodeptr;

nodeptr initLL (int val) {
	nodeptr first = (nodeptr) malloc(sizeof(Node));
	first->next = NULL;
	first->val = val;
	return first;
}

int insertLast (nodeptr ll, int val) {
	nodeptr newnode = (nodeptr) malloc(sizeof(Node));
	newnode->val = val;
	newnode->next = NULL;
	nodeptr add;
	for (nodeptr curr = ll; curr->next!=NULL; curr = curr->next) add = curr->next;
	add->next = newnode;
	if (newnode!=NULL) return 1;
	else return 0;
}

int insertFirst ();

int deleteLast ();

int deleteFirst ();

void printLL(nodeptr ll) {
    nodeptr iterator = ll;
    int first_time = 1;
    while (iterator->next != NULL || first_time) {
	first_time = 0;
	printf("%d ", iterator->val);
	iterator = iterator->next;
    }
}

