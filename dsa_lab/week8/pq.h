#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct {
    int ele;
    int priority;
} pqele;

typedef struct {
	int rear, front;
	int capacity;
	int size;
	pqele* queue;
} PQ;

int isEmpty(PQ* q) {
	if (q->size == 0) return 1;
	return 0;
}

int isFull(PQ* q) {
	if (q->front == q->capacity-1) return 1;
	return 0;
}

PQ * createQueue(int cap) {
	PQ* q = (PQ *)malloc(sizeof(PQ));
	q->queue = (pqele *)malloc(sizeof(pqele)*cap);
	q->capacity = cap;
	q->rear = -1;
	q->front = -1;
	q->size = 0;
	return q;
}

void destroyQueue(PQ* q) {
	free(q->queue);
	free(q);
	printf("Destroyed queue\n");
}

void printQueue(PQ* q) {
	for (int i = 0; i < q->capacity; ++i) {
		printf("%d ", (q->queue + i)->ele);
	}
	printf("\n");
}

void printQueueP(PQ* q) {
    for (int i = 0; i < q->capacity; ++i) {
	    printf("%d ", (q->queue + i)->ele);
    }
    printf("\n");
    for (int i = 0; i < q->capacity; ++i) {
	    printf("%d ", (q->queue + i)->priority);
    }
    printf("\n");
}

void enqueue(PQ* q, pqele ele) {
	if (isFull(q)) printf("Queue full");
	else {
		q->front++;
		q->size++; 
		*(q->queue+q->front) = ele;
	}
}

void dequeue(PQ* q) {
	if(isEmpty(q)) printf("\nQueue is empty");
	else {
	   int min_priority = INT_MAX;
	   int min_priority_index;
	   for (int i = 0; i < q->capacity; ++i) {
	       if ((q->queue+i)->priority < min_priority) {
		   min_priority_index = i;
		   min_priority = (q->queue+i)->priority;
	       }
	   }
	   pqele empty = {0, INT_MAX};
	   *(q->queue+min_priority_index) = empty;
	   q->size--;
	}
}

pqele peekFront(PQ* q) {
	if(isEmpty(q)) printf("Queue is empty");
	else {
		return *(q->queue+q->front);
	}
}

pqele peekBack(PQ* q) {
	if (isEmpty(q)) printf("Queue is empty");
	else {
		return *(q->queue+q->rear+1);
	}
}
