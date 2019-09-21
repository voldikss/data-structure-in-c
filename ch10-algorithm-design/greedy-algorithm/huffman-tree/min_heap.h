//============================================================================
// FileName: min_heap.h
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#ifndef _MIN_HEAP_H_
#define _MIN_HEAP_H_

#include "huffman_tree.h"

typedef struct HeapNode *MinHeap;
struct HeapNode {
    int Capacity;
    int Size;
    int *Elements;
};

MinHeap BuildMinHeap(MinHeap H);

HuffmanTree DeleteMin(MinHeap H);

MinHeap Insert(MinHeap H, HuffmanTree T);

#endif /* !MIN_HEAP_H */
