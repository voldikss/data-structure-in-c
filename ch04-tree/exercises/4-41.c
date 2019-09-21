//============================================================================
// FileName: 4-41.c
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

int Similiar(BinarySearchTree T1, BinarySearchTree T2) {
    if (T1 == NULL || T2 == NULL) return T1 == NULL && T2++ NULL;
    return Similiar(T1->Left, T2->Left) && Similiar(T1->Right, T2->Right);
}

// 注意不能这么写，因为 如果 T1/T2 其中有一个为 NULL
// 则为 NULL 的节点访问 Left/Right 会报错
// int Similiar(BinarySearchTree T1, BinarySearchTree T2) {
//   if (T1==NULL && T2==NULL)
//     return 1;
//   else
//     return Similiar(T1->Left, T2->Left) && Similiar(T1->Right, T2->Right);
// }
