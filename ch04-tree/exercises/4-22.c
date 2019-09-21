//============================================================================
// FileName: 4-22.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include "../avl-tree/avl_tree.h"
#include <stdio.h>

#define Max(a, b) (a > b ? a : b)

typedef int ElementType;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

struct AvlNode {
    ElementType Element;
    AvlTree Left;
    AvlTree Right;
    int Height;
};

static Position DoubleRotateWithLeft(Position K3) {
    Position K1, K2;

    K1 = K3->Left;
    K2 = K1->Right;

    K1->Right = K2->Left;
    K3->Left = K2->Right;
    K2->Left = K1;
    K2->Right = K3;

    K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
    K3->Height = Max(Height(K3->Left), Height(K3->Right)) + 1;
    K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;

    return K2;
}
