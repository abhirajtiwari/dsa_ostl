#include <stdio.h>
#include <stdlib.h>

typedef struct NODE node;
typedef node* nodeptr; 
struct NODE {
	int val;
	nodeptr prev;
	nodeptr next;
};

nodeptr initLL (int val) {
	nodeptr first = (nodeptr) malloc(sizeof(node));
	first->next = NULL;
	first->prev = NULL;
	first->val = val;
	return first;
}

int insertLast (nodeptr ll, int val) {
	nodeptr newnode = (nodeptr) malloc(sizeof(node));
	newnode->val = val;
	newnode->next = NULL;
	nodeptr curr;
	for (curr = ll; curr->next!=NULL; curr = curr->next);
	curr->next = newnode;
	newnode->prev = curr;
	if (newnode!=NULL) return 1;
	else return 0;
}

int insertFirst (nodeptr *ll, int val) {
    nodeptr newnode = (nodeptr)malloc(sizeof(node));
    newnode->val = val;
    newnode->next = *ll;
    (*ll)->prev = newnode;
    newnode->prev = NULL;
    *ll = newnode;
    if (newnode != NULL) return 1;
    return 0;
}

int deleteLast (nodeptr ll) {
    nodeptr iter;
    for (iter = ll; iter->next != NULL; iter=iter->next);
    (iter->prev)->next = NULL;
    int val = iter->val;
    free(iter);
    return val;
}

int deleteFirst (nodeptr *ll) {
    nodeptr temp = *ll;
    ((*ll)->next)->prev = NULL; 
    *ll = temp->next;
    int val = temp->val;
    free(temp);
    return val;
}

void printLL(nodeptr ll) {
    nodeptr iterator = ll;
    int first_time = 1;
    while (iterator->next != NULL || first_time) {
		first_time = 0;
		printf("%d ", iterator->val);
		iterator = iterator->next;
    }
    printf("%d ", iterator->val);
}
