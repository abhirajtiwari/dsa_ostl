#include <stdio.h>
#include <stdlib.h>
#include "stringcq.h"

int main() {
	Q* cq = createQueue(5);
	char text[] = "abhiraj", text2[] = "hello", text3[] = "test";
	enqueue(cq, text3);
	// printQueue(cq);
	enqueue(cq, text2);
	printf("%s\t%s\n", peekBack(cq), peekFront(cq));
	printQueue(cq);
	dequeue(cq);
	printQueue(cq);
}