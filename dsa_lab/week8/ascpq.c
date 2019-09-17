#include <stdio.h>
#include "pq.h"

int main() {
    PQ *pq;
    pq = createQueue(5);
    pqele a = {5, 9};
    pqele b = {6, 4};
    pqele c = {2, 1};
    enqueue(pq, a);
    enqueue(pq, c);
    enqueue(pq, b);
    printQueueP(pq);
    dequeue(pq);
    printQueueP(pq);
    destroyQueue(pq);
}
