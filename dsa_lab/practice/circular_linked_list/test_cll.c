#include <stdio.h>
#include <stdlib.h>
#include "cll.h"

int main() {
	nodeptr start = (nodeptr) malloc(sizeof(nodeptr));
	start->next = getNode(3);
	insertEnd(start, getNode(4));
	insertEnd(start, getNode(5));
	printCLL(start);
	insertFront(&start, getNode(7));
	printCLL(start);
	deleteEnd(start);
	printCLL(start);
	deleteFront(&start);
	printCLL(start);
}
