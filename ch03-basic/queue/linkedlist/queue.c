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
    return Q->front == NULL;
}

Queue CreateQueue() {
    Queue Q;
    Q = malloc(sizeof(struct Node));
    if (Q == NULL) {
        printf("Error");
        return NULL;
    }
    Q->front = NULL;
    Q->rear = NULL;

    return Q;
}

ElementType Front(Queue Q) {
    return Q->front->Data;
}

void Dequeue(Queue Q) {
    struct Node *FrontCell;
    ElementType FrontElem;

    if (IsEmpty(Q)) {
        printf("Queue is empty");
        exit(1);
    }

    FrontCell = Q->front;
    if (Q->front == Q->rear) { // 原本只有一个元素的情形
        Q->front = Q->rear = NULL;
    } else {
        Q->front = Q->front->Next;
    }
    FrontElem = FrontCell->Data;
    free(FrontCell);
}

void Enqueue(ElementType X, Queue Q) {
    struct Node *TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    if (TmpCell == NULL) {
        printf("Error");
        return;
    }
    TmpCell->Data = X;
    TmpCell->Next = NULL;
    // NOTE 对应队列为空的情况
    if (Q->front == NULL && Q->rear == NULL) {
        Q->front = Q->rear = TmpCell;
    } else {
        Q->rear->Next = TmpCell;
        Q->rear = TmpCell;
    }
}

void PrintQueue(Queue Q) {
    if (IsEmpty(Q)) {
        printf("Queue is empty");
        return;
    }

    PtrToNode P = Q->front;
    while (P) {
        printf("%d\n", P->Data);
        P = P->Next;
    }
    printf("\n");
}

void MakeEmpty(Queue Q) {
    while (!IsEmpty(Q)) {
        Dequeue(Q);
    }
}

void DisposeQueue(Queue Q) {
    MakeEmpty(Q);
    free(Q);
}
