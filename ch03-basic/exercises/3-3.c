//============================================================================
// FileName: 3-3.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include <stdio.h>

typedef struct Node *List;
typedef struct TwoEndsNode *TwoEndsList;

struct Node {
    int Data;
    struct Node *Next;
};

struct TwoEndsNode {
    int Data;
    struct TwoEndsNode *Prev;
    struct TwoEndsNode *Next;
};

// swap P and AfterP
// Acutally we just need to change the node data, dont we
void SwapTwoNodes(List BeforeP) {
    List P, AfterP;

    P = BeforeP->Next;
    AfterP = P->Next;

    BeforeP->Next = AfterP;
    P->Next = AfterP->Next;
    AfterP->Next = P;
}

// swap P and AfterP
void SwapTwoNodes2(TwoEndsList P) {
    TwoEndsList BeforeP, AfterP;

    BeforeP = P->Prev;
    AfterP = P->Next;

    BeforeP->Next = AfterP;
    P->Next = AfterP->Next;
    AfterP->Next = P;
}
