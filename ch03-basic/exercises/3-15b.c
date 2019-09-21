//============================================================================
// FileName: 3-15b.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include <stdio.h>
#include <stdlib.h>

typedef struct Node *List;
typedef int ElementType;
typedef List Position;

struct Node {
    ElementType Data;
    List Next;
};

Position Find(ElementType X, const List L) {
    Position P;
    List TmpCell;

    P = L;

    while (P->Next != NULL) {
        TmpCell = P->Next;
        if (TmpCell->Data == X) {
            P->Next = TmpCell->Next;

            TmpCell->Next = L->Next;
            L->Next = TmpCell->Next;
            return L;
        }
    }
    return NULL;
}
