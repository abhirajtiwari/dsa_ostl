#include "dll.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	nodeptr start = getNode(3);
	printDLL(start);
	insertEnd(start, getNode(4));
	printDLL(start);
	insertFront(&start, getNode(5));
	printDLL(start);
	deleteEnd(start);
	printDLL(start);
	deleteFront(&start);
	printDLL(start);
}
