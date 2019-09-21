//============================================================================
// FileName: stack.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack CreateStack(int MaxElements) {
    Stack S;

    if (MaxElements < MinStackSize) {
        printf("Stack size is too small");
        exit(1);
    }

    S = malloc(sizeof(struct StackRecord));
    if (S == NULL) {
        printf("Error");
        exit(1);
    }

    S->Array = malloc(sizeof(ElementType) * MaxElements);
    if (S->Array == NULL) {
        printf("Error");
        exit(1);
    }

    S->Capacity = MaxElements;
    MakeEmpty(S);
    return S;
}

void DisposeStack(Stack S) {
    if (S != NULL) {
        free(S->Array);
        free(S);
    }
}

int IsEmpty(Stack S) {
    return S->TopOfStack == EmptyTOS;
}

int IsFull(Stack S) {
    return S->TopOfStack == S->Capacity - 1;
}

void MakeEmpty(Stack S) {
    S->TopOfStack = EmptyTOS;
}

void Push(ElementType X, Stack S) {
    if (IsFull(S)) {
        printf("Full Stack");
        exit(1);
    }
    S->Array[++S->TopOfStack] = X;
}

ElementType Top(Stack S) {
    if (IsEmpty(S)) {
        printf("Empty stack");
        exit(1);
    }
    return S->Array[S->TopOfStack];
}

void Pop(Stack S) {
    if (IsEmpty(S)) {
        printf("Empty stack");
        exit(1);
    }
    S->TopOfStack--;
}

ElementType TopAndPop(Stack S) {
    if (IsEmpty(S)) {
        printf("Empty stack");
        exit(1);
    }
    return S->Array[S->TopOfStack--];
}
