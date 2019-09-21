//============================================================================
// FileName: 3-12.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include <stdio.h>

typedef int ElementType;
typedef struct Node *List;
typedef List Position;

struct Node {
    int Data;
    struct Node *Next;
};

// 分别移动 prev, head, next
List Reverse(List L) {
    List Prev, Head, Next;

    Prev = NULL;
    Next = NULL;
    Head = L;
    while (Head != NULL) {
        Next = Head->Next;
        Head->Next = Prev;

        Prev = Head;
        Head = Next;
    }

    return L;
}

List RecursiveReverse(List L) {
    if (L == NULL || L->Next == NULL) return L;

    List Tmp = RecursiveReverse(L->Next);
    L->Next->Next = L;
    L->Next = NULL;
    return Tmp;
}
