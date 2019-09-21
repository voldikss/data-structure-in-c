//============================================================================
// FileName: 4-28.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include "../binary-search-tree/binary_search_tree.h"
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    ElementType Element;
    BinarySearchTree Left;
    BinarySearchTree Right;
};

int CountNodes(BinarySearchTree T) {
    if (T == NULL) return 0;
    return CountNodes(T->Left) + CountNodes(T->Right) + 1;
}

int CountLeaves(BinarySearchTree T) {
    if (T == NULL) return 0;
    if (T->Left == NULL && T->Right == NULL) return 1;
    return CountLeaves(T->Left) + CountLeaves(T->Right);
}

int CountFullNodes(BinarySearchTree T) {
    if (T == NULL) return 0;

    return CountFullNodes(T->Left) + CountFullNodes(T->Right) +
           (T->Left != NULL && T->Right != NULL);
}
