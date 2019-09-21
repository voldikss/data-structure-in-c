//============================================================================
// FileName: 3-5.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *List;
typedef List Position;

struct Node {
    int Data;
    struct Node *Next;
};

List Union(List L1, List L2) {
    List L;
    Position LPos, L1Pos, L2Pos;
    ElementType Data;

    L = malloc(sizeof(struct Node));
    L->Next = NULL;
    LPos = L;
    L1Pos = L1;
    L2Pos = L2;

    while (L1 != NULL && L2 != NULL) {
        if (L1->Data < L2->Data) {
            Data = L1Pos->Data;
            L1Pos = L1Pos->Next;
        } else if (L1->Data > L2->Data) {
            Data = L2->Data;
            L2Pos = L2Pos->Next;
        } else {
            Data = L1->Data;
            L1Pos = L1Pos->Next;
            L2Pos = L2Pos->Next;
        }
        List TmpCell = malloc(sizeof(struct Node));
        TmpCell->Data = Data;
        TmpCell->Next = LPos->Next;
        LPos->Next = TmpCell;
    }

    LPos = LPos->Next;
    return L;
}
