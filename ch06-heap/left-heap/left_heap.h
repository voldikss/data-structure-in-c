//============================================================================
// FileName: left_heap.h
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#ifndef _LEFT_HEAP_H_
#define _LEFT_HEAP_H_

typedef int ElementType;

typedef struct TreeNode *LeftHeap;
struct TreeNode {
    ElementType Element;
    LeftHeap Left;
    LeftHeap Right;
    int Npl;
};

LeftHeap Initialize(void);

ElementType FindMin(LeftHeap H);

int IsEmpty(LeftHeap H);

LeftHeap Merge(LeftHeap H1, LeftHeap H2);

#define Insert(X, H) (H = Insert1((X), H))
#define DeleteMin(H) (H = DeleteMin1(H))

LeftHeap Insert1(ElementType X, LeftHeap H);

LeftHeap DeleteMin1(LeftHeap H);

#endif /* !LEFT_HEAP_H */
