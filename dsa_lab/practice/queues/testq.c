#include <stdio.h>
#include "queue.h"

int main() {
	Q* q;
	q = createQueue(5);
	enqueue(q, 2);
	printQueue(q);
	enqueue(q, 1);
	enqueue(q, 3);
	printQueue(q);
	printf("Front: %d\n", peekFront(q));
	printf("Rear: %d\n", peekBack(q));
	dequeue(q);
	printf("Front: %d\n", peekFront(q));
	printf("Rear: %d\n", peekBack(q));
	enqueue(q, 3);
	enqueue(q, 3);
	enqueue(q, 3);
	enqueue(q, 3);
	enqueue(q, 3);
	dequeue(q);
	dequeue(q);
	dequeue(q);
	dequeue(q);
	dequeue(q);
	dequeue(q);
	dequeue(q);
	dequeue(q);
}

