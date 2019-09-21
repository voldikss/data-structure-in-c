//============================================================================
// FileName: 4-32.c
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

void PrintRange(BinarySearchTree T, ElementType k1, ElementType k2) {
    if (T != NULL) {
        if (T->Element < k1)
            PrintRange(T->Right, k1, k2);
        else if (T->Element > k2)
            PrintRange(T->Left, k1, k2);
        else
            printf("%d\n", T->Element);
    }
}
