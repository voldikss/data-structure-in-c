//============================================================================
// FileName: list.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

List MakeEmpty(List L) {
    L = malloc(sizeof(struct Node));
    if (L == NULL) {
        printf("Error");
        exit(1);
    }
    L->Last = -1;
    return L;
}

int IsEmpty(List L) {
    return L->Last == -1;
}

int IsLast(Position P, List L) {
    return P == L->Last;
}

ElementType Retrieve(Position P, List L) {
    return L->Elements[P];
}

Position Find(ElementType X, List L) {
    Position P = 0;
    while (P <= L->Last && L->Elements[P] != X) {
        ++P;
    }
    if (P > L->Last)
        return -1;
    else
        return P;
}

void Delete(ElementType X, List L) {
    Position P, Tmp;
    P = Find(X, L);
    if (P == -1) {
        printf("X doesn't exist");
        return;
    }
    for (Tmp = 0; Tmp < L->Last; ++Tmp) {
        L->Elements[Tmp] = L->Elements[Tmp + 1];
    }
}

Position FindPrev(ElementType X, List L) {
    Position P = -1;
    while (P < L->Last && L->Elements[P + 1] != X) {
        ++P;
    }
    if (P == L->Last)
        return -1;
    else
        return P;
}

void Insert(ElementType X, List L, Position P) {
    if (L->Last == MAXSIZE - 1) {
        printf("List is full");
        exit(1);
    }
    if (P < 0 || P > L->Last + 2) {
        printf("Invalid position");
        exit(1);
    }

    Position Tmp;
    for (Tmp = L->Last; Tmp >= P; --Tmp) {
        L->Elements[P + 1] = L->Elements[P];
    }
    L->Elements[P] = X;
    L->Last++;
}
