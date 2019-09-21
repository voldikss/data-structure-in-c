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
    for (P = 0; P <= L->Last; ++P) {
        printf("%d\n", L->Elements[P]);
    }
}

List BuildList() {
    List L;
    L = MakeEmpty();

    Position P = 0;
    ElementType Num;
    while ((scanf("%d", &Num) == 1)) {
        Insert(Num, L, P);
        ++P;
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
