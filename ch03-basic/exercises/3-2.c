//============================================================================
// FileName: 3-2.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include <stdio.h>

typedef struct Node *List;

struct Node {
    int Data;
    struct Node *Next;
};
void PrintLots(List L, List P) {
    int pos = 1;
    while (L != NULL && P != NULL) {
        if (pos == P->Data) {
            printf("%d\n", L->Data);
            P = P->Next;
        }
        L = L->Next;
        ++pos;
    }
}
