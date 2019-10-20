#include "sll.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	nodeptr start = getNode(1);
	printLL(start);
	insertEnd(start, getNode(2));
	insertEnd(start, getNode(4));
	insertEnd(start, getNode(3));
	printLL(start);
	insertFront(&start, getNode(5));
	printLL(start);
	deleteEnd(start);
	printLL(start);
	deleteFront(&start);
	printLL(start);
}
