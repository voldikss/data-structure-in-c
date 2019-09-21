//============================================================================
// FileName: binomial_queue.h
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#ifndef _BINOMIAL_QUEUE_H_
#define _BINOMIAL_QUEUE_H_

#define _BINOMIAL_QUEUE_H_

typedef int ElementType;

typedef struct BinNode *BinTree;
typedef BinTree Position;
struct BinNode {
    ElementType Element;
    Position LeftChild;
    Position NextSibliing;
};

typedef struct Collection *BinQueue;
struct Collection {
    int CurrentSize;
    BinTree TheTrees;
};

#endif /* !BINOMIAL_QUEUE_H */
