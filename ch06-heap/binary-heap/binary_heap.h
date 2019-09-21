//============================================================================
// FileName: binary_heap.h
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#ifndef _BINARY_HEAP_H_
#define _BINARY_HEAP_H_

typedef int ElementType;

typedef struct HeapStruct *BinaryHeap;
struct HeapStruct {
    int Capacity;
    int Size;
    ElementType *Elements;
};

BinaryHeap Initialize(int MaxElements);

void Destroy(BinaryHeap H);

void MakeEmpty(BinaryHeap H);

void Insert(ElementType X, BinaryHeap H);

ElementType DeleteMin(BinaryHeap H);

ElementType FindMin(BinaryHeap H);

int IsEmpty(BinaryHeap H);

int IsFull(BinaryHeap H);

#endif /* !BINARY_HEAP_H */
