#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 15

typedef struct {
	int rear, front;
	int capacity;
	int size;
	char** queue;
} Q;

int isFull(Q* q) {
	if (q->size == q->capacity) return 1;
	return 0;
}

int isEmpty(Q* q) {
	if (q->size == 0) return 1;
	return 0;
}

Q * createQueue(int cap) {
	Q* q = (Q *)malloc(sizeof(Q));
	q->queue = (char **)calloc(cap, sizeof(char *));
	q->capacity = cap;
	for (int i = 0; i < cap; ++i)
		*(q->queue + i) = (char *)malloc(sizeof(char)*STRING_SIZE);
	q->rear = -1;
	q->front = -1;
	q->size = 0;
	return q;
}

void destroyQueue(Q* q) {
	for (int i = 0; i < q->capacity; ++i)
		free(*(q->queue+i));
	free(q->queue);
	free(q);
	printf("Destroyed queue\n");
}

void enqueue(Q* q, char* ele) {
	if (isFull(q)) printf("Queue full");
	else {
		q->front = (q->front+1)%q->capacity;
		q->size++; 
		strcpy(*(q->queue+q->front), ele);
	}
}

void dequeue(Q* q) {
	if(isEmpty(q)) printf("\nQueue is empty");
	else {
		// *(q->queue + (q->rear+1)%q->capacity) = NULL;
		q->rear = (q->rear+1)%q->capacity;
		q->size--;
	}
}

char* peekBack(Q* q) {
	if(isEmpty(q)) printf("Queue is empty");
	else {
		return *(q->queue+q->front);
	}
}

char* peekFront(Q* q) {
	if (isEmpty(q)) printf("Queue is empty");
	else {
		return *(q->queue+(q->rear+1)%q->capacity);
	}
}

void printQueue(Q* q) {
	for (int i = 0; i < q->capacity; ++i) {
		printf("%s ", *(q->queue + i));
	}
	printf("\n");
}

