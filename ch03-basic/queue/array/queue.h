//============================================================================
// FileName: queue.h
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#ifndef _QUEUE_H_
#define _QUEUE_H_

#define MaxElements 10

typedef struct QueueRecord *Queue;
typedef int ElementType;

struct QueueRecord {
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue();
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);

#endif /* !QUEUE_H */
