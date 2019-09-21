//============================================================================
// FileName: test_stack.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue BuildQueue() {
    Queue Q;
    Q = CreateQueue();
    ElementType Num;
    while (scanf("%d", &Num) == 1) {
        Enqueue(Num, Q);
    }
    return Q;
}

int main() {
    Queue Q;
    Q = BuildQueue();
    while (!IsEmpty(Q)) {
        printf("%d\n", Front(Q));
        Dequeue(Q);
    }
    DisposeQueue(Q);
}
