//============================================================================
// FileName: 4-30.c
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

BinarySearchTree GenTree(int Height) {
    BinarySearchTree T;

    if (Height >= 0) {
        T = malloc(sizeof(*T)); // *T == struct TreeNode ? //TODO
        T->Element = 1;
        T->Left = GenTree(Height - 1);
        T->Right = GenTree(Height - 2);
        return T;
    } else
        return NULL;
}
