//============================================================================
// FileName: set_type.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include <stdio.h>
#define MaxSize 100

typedef int ElementType;

typedef struct {
    ElementType Data;
    int Parent;
} SetType;

int Find(ElementType X, SetType S[]) {
    int i = 0;
    while (i < MaxSize && S[i].Data != X) {
        i++;
    }

    if (i > MaxSize) {
        return -1;
    }

    while (S[i].Parent >= 0) {
        i = S[i].Parent;
    }

    return i;
}

void Union(ElementType X1, ElementType X2, SetType S[]) {
    int Root1, Root2;
    Root1 = Find(X1, S);
    Root2 = Find(X2, S);
    if (Root1 != Root2) {
        S[Root2].Parent = Root1;
    }
}
