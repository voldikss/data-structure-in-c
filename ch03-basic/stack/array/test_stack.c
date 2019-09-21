//============================================================================
// FileName: test_stack.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack BuildStack() {
    Stack S;
    S = CreateStack(10);
    int Num;
    while (scanf("%d", &Num) == 1) {
        Push(Num, S);
    }
    return S;
}

int main() {
    Stack S;
    S = BuildStack();
    while (!IsEmpty(S)) {
        printf("%d\n", TopAndPop(S));
    }
    DisposeStack(S);
}
