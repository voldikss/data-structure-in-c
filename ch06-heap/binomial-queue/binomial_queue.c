//============================================================================
// FileName: binomial_queue.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include "binomial_queue.h"
#include <stdio.h>

BinTree CombineTrees(BinTree T1, BinTree T2) {
    // 这个漂亮的操作我一直没掌握!!!
    if (T1->Element > T2->Element) return CombineTrees(T2, T1);

    T2->NextSibliing = T1->LeftChild;
    T1->LeftChild = T2;
    return T1;
}

// TODO
BinQueue Merge(BinQueue H1, BinQueue H2) {
    /*

    */
    return H1;
}

ElementType DeleteMin(BinQueue H) {
    int MinItem;
    /*

       */
    return MinItem;
}
