//============================================================================
// FileName: 3-15a.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include <stdio.h>

typedef int ElementType;
typedef int Position;
typedef struct Node *List;
struct Node {
    ElementType *Data;
    int Size;
};

// *a*
Position Find(ElementType X, const List L) {
    int Pos, i;

    Pos = 0;

    for (i = 0; i < L->Size; ++i) {
        if (X == L->Data[i]) {
            Pos = i;
            break;
        }
    }

    if (Pos) {
        for (i = Pos; i > 0; --i) L->Data[i] = L->Data[i - 1];
        L->Data[0] = X;
        return 0;
    }

    return -1;
}
