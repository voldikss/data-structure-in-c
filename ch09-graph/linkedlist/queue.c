//////////////////////////////////////////////////////////////////////////////
// FileName: queue.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//////////////////////////////////////////////////////////////////////////////

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

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

int IsEmpty(Queue Q) {
  return Q->front == NULL;
}

ElementType Dequeue(Queue Q) {
  struct Node *FrontCell;
  ElementType FrontElem;

  if (IsEmpty(Q)) {
    printf("Queue is empty");
    exit(EXIT_FAILURE);
  }

  FrontCell = Q->front;
  if (Q->front == Q->rear) { // 原本只有一个元素的情形
    Q->front = Q->rear = NULL;
  } else {
    Q->front = Q->front->Next;
  }
  FrontElem = FrontCell->Data;
  free(FrontCell);
  return FrontElem;
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

/* for testing */
// int main() {
//   Queue Q = CreateQueue();
//   Enqueue(3, Q);
//   Enqueue(4, Q);
//   Enqueue(5, Q);
//   Enqueue(6, Q);
//   PrintQueue(Q);
//   Dequeue(Q);
//   PrintQueue(Q);
// }
