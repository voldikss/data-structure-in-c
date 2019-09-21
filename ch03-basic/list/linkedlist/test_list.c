//============================================================================
// FileName: test_list.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void PrintList(List L) {
    Position P;
    P = L->Next; // omit the header, dont use recursion
    while (P) {
        printf("%d\n", P->Element); // assume elementtype is int
        P = P->Next;
    }
}

List BuildList() {
    List L;
    L = MakeEmpty(L);

    Position P = L;
    ElementType Num;
    while ((scanf("%d", &Num) == 1)) {
        Insert(Num, L, P);
        P = P->Next;
    }
    return L;
}

int main() {
    List L;
    L = BuildList();

    printf("Is empty list? %d\n", IsEmpty(L));
    PrintList(L);
    return 0;
}
