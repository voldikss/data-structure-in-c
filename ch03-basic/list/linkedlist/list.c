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
    L->Next = NULL;
    return L;
}

int IsEmpty(List L) {
    return L->Next == NULL;
}

int IsLast(Position P, List L) {
    return P->Next == NULL;
}

// not sure
// void DeleteList(List L) {
//     if (L == NULL) {
//         return;
//     } else {
//         DeleteList(L->Next);
//         free(L);
//     }
// }

void DeleteList(List L) {
    Position P, TmpCell;
    P = L->Next;
    L->Next = NULL;
    while (P != NULL) {
        TmpCell = P->Next;
        free(P);
        P = TmpCell;
    }
}

Position Header(List L) {
    return L;
}

Position First(List L) {
    return L->Next;
}

Position Advance(Position P) {
    return P->Next;
}

ElementType Retrieve(Position P, List L) {
    return P->Element;
}

Position Find(ElementType X, List L) {
    Position P;
    P = L->Next;
    while (P != NULL && P->Element != X) {
        P = P->Next;
    }
    return P;
}

void Delete(ElementType X, List L) {
    Position P;
    List TmpCell;
    P = FindPrev(X, L);
    if (!IsLast(P, L)) { // 重要：即 FindPrev 返回的是 最后一个节点（没找到）
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}

Position FindPrev(ElementType X, List L) {
    Position P;
    P = L;
    while (P->Next != NULL && P->Next->Element != X) {
        P = P->Next;
    }
    return P; // 没找到则返回最后一个节点
}

void Insert(ElementType X, List L, Position P) {
    Position TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    if (TmpCell == NULL) {
        printf("Error");
        exit(1);
    }
    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}
