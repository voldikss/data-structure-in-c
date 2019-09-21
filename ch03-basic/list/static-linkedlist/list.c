//============================================================================
// FileName: list.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include "list.h"
#include <stdio.h>

void InitializeCursorSpace() {
    for (int i = 0; i < SpaceSize - 1; ++i) CursorSpace[i].Next = 0;
    CursorSpace[SpaceSize - 1].Next = 0;
}

List MakeEmpty(List L) {
    Position P;
    P = L;

    do {
        CursorSpace[P].Element = 0;
    } while ((P = CursorSpace[P].Next) != 0);

    return L;
}

static Position CursorAlloc() {
    Position P;

    P = CursorSpace[0].Next;
    CursorSpace[0].Next = CursorSpace[P].Next;

    return P;
}

static void CursorFree(Position P) {
    CursorSpace[P].Next = CursorSpace[0].Next;
    CursorSpace[0].Next = P;
}

int IsEmpty(const List L) {
    return CursorSpace[L].Next == 0;
}

int IsLast(const Position P, const List L) {
    return CursorSpace[P].Next == 0;
}

Position Find(ElementType X, const List L) {
    Position P;
    P = CursorSpace[L].Next;

    while (P && CursorSpace[P].Element != X) P = CursorSpace[P].Next;

    return P;
}

void Delete(ElementType X, List L) {
    Position P, Tmp;

    P = FindPrevious(X, L);

    if (!IsLast(P, L)) {
        Tmp = CursorSpace[P].Next;
        CursorSpace[P].Next = CursorSpace[Tmp].Next;
        CursorFree(Tmp);
    }
}

Position FindPrevious(ElementType X, const List L) {
    Position P;

    P = L;

    while (CursorSpace[P].Next && CursorSpace[CursorSpace[P].Next].Element != X)
        P = CursorSpace[P].Next;

    return P;
}

void Insert(ElementType X, List L, Position P) {
    Position TmpCell;

    TmpCell = CursorAlloc();

    if (TmpCell == 0) printf("Out of space!");

    CursorSpace[TmpCell].Element = X;
    CursorSpace[TmpCell].Next = CursorSpace[P].Next;
    CursorSpace[P].Next = TmpCell;
}

void DeleteList(List L) {
    Position P, Tmp;

    P = L;
    Tmp = CursorSpace[P].Next;
    while (P) {
        P = CursorSpace[P].Next;
        CursorFree(Tmp);
        Tmp = P;
    }

    CursorSpace[L].Next = 0;
}
