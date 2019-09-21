//============================================================================
// FileName: left_heap.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include "left_heap.h"
#include <lzma.h>
#include <stdio.h>
#include <stdlib.h>

void SwapChildren(LeftHeap H) {
    LeftHeap Tmp;
    Tmp = H->Left;
    H->Left = H->Right;
    H->Right = Tmp;
}

static LeftHeap Merge1(LeftHeap H1, LeftHeap H2) {
    if (H1->Left == NULL) {
        H1->Left = H2;
    } else {
        H1->Right = Merge(H1->Right, H2);
        if (H1->Left->Npl < H1->Right->Npl) SwapChildren(H1);

        H1->Npl = H1->Right->Npl + 1;
    }
    return H1;
}

LeftHeap Merge(LeftHeap H1, LeftHeap H2) {
    if (H1 == NULL) return H2;
    if (H2 == NULL) return H1;
    if (H1->Element < H2->Element)
        return Merge1(H1, H2);
    else
        return Merge1(H2, H1);
}

LeftHeap Insert1(ElementType X, LeftHeap H) {
    LeftHeap SingleNode;

    SingleNode = malloc(sizeof(struct TreeNode));
    if (SingleNode == NULL) {
        printf("Error");
        return NULL;
    } else {
        SingleNode->Element = X;
        SingleNode->Right = NULL;
        SingleNode->Left = NULL;
        SingleNode->Npl = 0;
        H = Merge(H, SingleNode);
    }
    return H;
}

LeftHeap DeleteMin1(LeftHeap H) {
    LeftHeap LeftHeap, RightHeap;

    if (IsEmpty(H)) {
        printf("Error");
        return H;
    }

    LeftHeap = H->Left;
    RightHeap = H->Right;
    free(H);
    return Merge(LeftHeap, RightHeap);
}

int IsEmpty(LeftHeap H) {
    return H->Left == NULL && H->Right == NULL;
}
