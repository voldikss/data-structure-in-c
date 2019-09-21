//============================================================================
// FileName: queue.h
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    struct Node *Next;
};

typedef struct QNode *Queue;
struct QNode {
    struct Node *rear;
    struct Node *front;
};

Queue CreateQueue();
int IsEmpty(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Dequeue(Queue Q);
void PrintQueue(Queue Q);
void DisposeQueue(Queue Q);

#endif /* !QUEUE_H */
