//============================================================================
// FileName: binary_heap.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include "binary_heap.h"
#include <stdio.h>
#include <stdlib.h>

BinaryHeap Initialize(int MaxElements) {
    BinaryHeap H;

    H = malloc(sizeof(struct HeapStruct));
    if (H == NULL) {
        printf("Error");
        return NULL;
    }
    H->Elements = malloc((MaxElements + 1) * sizeof(ElementType));
    if (H->Elements == NULL) {
        printf("Error");
        return NULL;
    }
    H->Capacity = MaxElements;
    H->Size = 0;

    return H;
}

void Insert(ElementType X, BinaryHeap H) {
    if (IsFull(H)) {
        printf("Heap is full");
        return;
    }
    H->Elements[H->Size] = X;
    ++H->Size;

    int i = H->Size;
    while (i != 0 && H->Elements[i / 2]) {
        H->Elements[i] = H->Elements[i / 2];
        i /= 2;
    }
    H->Elements[i] = X;
}

ElementType DeleteMin(BinaryHeap H) {
    int i, Child;

    ElementType MinElement, LastElement;
    if (IsEmpty(H)) {
        printf("Heap is empty");
        return H->Elements[0];
    }

    MinElement = H->Elements[1];
    LastElement = H->Elements[H->Size--];

    for (i = 1; i * 2 < H->Size; i = Child) {
        Child = i * 2;
        if (Child != H->Size && H->Elements[Child + 1] < H->Elements[Child])
            H->Elements[i] = H->Elements[Child];
        else
            H->Elements[i + 1] = H->Elements[Child];
    }
    H->Elements[i] = LastElement;
    return MinElement;
}

int IsEmpty(BinaryHeap H) {
    return H->Size == 0;
}

int IsFull(BinaryHeap H) {
    return H->Size == H->Capacity;
}

ElementType FindMin(BinaryHeap H) {
    if (H == NULL) {
        printf("Error, H is NULL");
        return NULL;
    }

    return H->Elements[1];
}
