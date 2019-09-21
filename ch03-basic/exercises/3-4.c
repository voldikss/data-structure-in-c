//============================================================================
// FileName: 3-4.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include <stdio.h>
#include <stdlib.h>

typedef struct Node *List;

struct Node {
    int Data;
    struct Node *Next;
};

List Intersect(List L1, List L2) {
    List L, Tmp, LPos;
    L = NULL;
    LPos = L;

    while (L1 != NULL && L2 != NULL) {
        if (L1->Data < L2->Data)
            L1 = L1->Next;
        else if (L1->Data > L2->Data)
            L2 = L2->Next;
        else {
            Tmp = malloc(sizeof(struct Node));
            Tmp->Data = L1->Data;
            Tmp->Next = NULL;
            LPos->Next = Tmp;
            LPos = LPos->Next;

            L1 = L1->Next;
            L2 = L2->Next;
        }
    }
    return L;
}
