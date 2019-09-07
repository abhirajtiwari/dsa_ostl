#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int rear, front;
	int capacity;
	int size;
	int* queue;
} Q;

int isEmpty(Q* q) {
	if (q->size == 0) return 1;
	return 0;
}

int isFull(Q* q) {
	if (q->front == q->capacity-1) return 1;
	return 0;
}

Q * createQueue(int cap) {
	Q* q = (Q *)malloc(sizeof(Q));
	q->queue = (int *)malloc(sizeof(int)*cap);
	q->capacity = cap;
	q->rear = -1;
	q->front = -1;
	q->size = 0;
	return q;
}

void destroyQueue(Q* q) {
	free(q->queue);
	free(q);
	printf("Destroyed queue\n");
}

void printQueue(Q* q) {
	for (int i = 0; i < q->capacity; ++i) {
		printf("%d ", *(q->queue + i));
	}
	printf("\n");
}

void enqueue(Q* q, int ele) {
	if (isFull(q)) printf("Queue full");
	else {
		q->front++;
		q->size++; 
		*(q->queue+q->front) = ele;
	}
}

void dequeue(Q* q) {
	if(isEmpty(q)) printf("\nQueue is empty");
	else {
		q->rear++;
		q->size--;
	}
}

int peekFront(Q* q) {
	if(isEmpty(q)) printf("Queue is empty");
	else {
		return *(q->queue+q->front);
	}
}

int peekBack(Q* q) {
	if (isEmpty(q)) printf("Queue is empty");
	else {
		return *(q->queue+q->rear+1);
	}
}
