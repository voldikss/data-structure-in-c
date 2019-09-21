//============================================================================
// FileName: binary_search_tree.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include "binary_search_tree.h"
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    ElementType Element;
    BinarySearchTree Left;
    BinarySearchTree Right;
};

BinarySearchTree MakeEmpty(BinarySearchTree T) {
    if (T != NULL) {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
    }
    return T;
}

BinarySearchTree Find(ElementType X, BinarySearchTree T) {
    if (T == NULL)
        return NULL;
    else if (T->Element < X)
        return Find(X, T->Left);
    else if (T->Element > X)
        return Find(X, T->Right);
    else
        return T;
}

BinarySearchTree FindMin(BinarySearchTree T) {
    if (T == NULL)
        return NULL;
    else if (T->Left == NULL)
        return T;
    else
        return FindMin(T->Left);
}

BinarySearchTree FindMax(BinarySearchTree T) {
    if (T == NULL)
        return NULL;
    else if (T->Right == NULL)
        return T;
    else
        return FindMax(T->Right);
}

BinarySearchTree Insert(ElementType X, BinarySearchTree T) {
    if (T == NULL) {
        // 此处不再新建一个指针，直接用 T
        T = malloc(sizeof(struct TreeNode));
        T->Left = NULL;
        T->Right = NULL;
    } else {
        if (X < T->Element)
            T->Left = Insert(X, T->Left);
        else if (X > T->Element)
            T->Right = Insert(X, T->Right);
    }

    return T;
}

BinarySearchTree Delete(ElementType X, BinarySearchTree T) {
    Position TmpCell;

    if (T == NULL)
        printf("Error");
    else if (X < T->Element)
        T->Left = Delete(X, T->Left);
    else if (X > T->Element)
        T->Right = Delete(X, T->Right);
    else {
        if (T->Left != NULL && T->Right != NULL) {
            TmpCell = FindMin(T->Right);
            T->Element = TmpCell->Element;
            T->Right = Delete(X, T->Right);
        } else {
            // nice
            TmpCell = T;
            if (T->Left == NULL)
                T = T->Right;
            else if (T->Right == NULL)
                T = T->Left;
            free(TmpCell);
        }
    }
    return T;
}

void PrintTree(BinarySearchTree T) {
    if (T != NULL) {
        PrintTree(T->Left);
        printf("%d\n", T->Element);
        PrintTree(T->Right);
    }
}
