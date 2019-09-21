//============================================================================
// FileName: stack.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int IsEmpty(Stack S) {
    return S->Next == NULL;
}

Stack CreateStack() {
    Stack S;

    S = malloc(sizeof(struct Node));
    if (S == NULL) {
        printf("Error");
        exit(1);
    }

    S->Next = NULL;
    return S;
}

void MakeEmpty(Stack S) {
    if (S == NULL) {
        printf("Error");
        exit(1);
    }
    while (!IsEmpty(S)) Pop(S);
}

void Push(ElementType X, Stack S) {
    Stack Tmp;

    Tmp = malloc(sizeof(struct Node));
    if (Tmp == NULL) {
        printf("Error");
        exit(1);
    }

    Tmp->Element = X;
    Tmp->Next = S->Next;
    S->Next = Tmp;
}

ElementType Top(Stack S) {
    if (!IsEmpty(S)) return S->Next->Element;
    printf("Error");
    exit(1);
}

void Pop(Stack S) {
    if (IsEmpty(S)) {
        printf("Error");
        exit(1);
    }

    Stack Tmp;
    Tmp = S->Next;
    S->Next = Tmp->Next;
    free(Tmp);
}

ElementType TopAndPop(Stack S) {
    ElementType Tmp = Top(S);
    Pop(S);
    return Tmp;
}
