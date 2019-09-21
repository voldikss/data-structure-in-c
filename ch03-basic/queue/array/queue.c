//============================================================================
// FileName: queue.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int IsEmpty(Queue Q) {
    return Q->Size == 0;
}

int IsFull(Queue Q) {
    return Q->Size == Q->Capacity;
}

void MakeEmpty(Queue Q) {
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

void Enqueue(ElementType X, Queue Q) {
    if (IsFull(Q)) {
        printf("Full queue");
        return;
    }
    Q->Size++;
    Q->Rear = (Q->Rear + 1) % Q->Capacity;
    Q->Array[Q->Rear] = X;
}

Queue CreateQueue() {
    Queue Q;

    Q = malloc(sizeof(struct QueueRecord));
    if (Q == NULL) {
        printf("Error");
        exit(1);
    }

    Q->Array = malloc(sizeof(ElementType) * MaxElements);
    if (Q->Array == NULL) {
        printf("Error");
        exit(1);
    }
    Q->Capacity = MaxElements;
    MakeEmpty(Q);
    return Q;
}

void DisposeQueue(Queue Q) {
    if (Q != NULL) {
        free(Q->Array);
        free(Q);
    }
}

ElementType Front(Queue Q) {
    if (IsEmpty(Q)) {
        printf("Empty queue");
        exit(1);
    }
    return Q->Array[Q->Front];
}

void Dequeue(Queue Q) {
    if (IsEmpty(Q)) {
        printf("Empty queue");
        return;
    }
    Q->Size--;
    Q->Front = (Q->Front + 1) % Q->Capacity;
}

ElementType FrontAndDequeue(Queue Q) {
    ElementType Tmp;
    Tmp = Front(Q);
    Dequeue(Q);
    return Tmp;
}
