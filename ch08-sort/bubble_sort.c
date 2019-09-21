//============================================================================
// FileName: bubble_sort.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

void Swap(ElementType *a, ElementType *b) {
    ElementType tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void BubbleSort(ElementType A[], int N) {
    for (int P = N - 1; P >= 0; --P) {
        int flag = 0;
        for (int i = 0; i < P; ++i) {
            if (A[i] > A[i + 1]) {
                Swap(&A[i], &A[i + 1]);
                flag = 1;
            }
        }
        if (!flag) return;
    }
}

int main() {
    ElementType a[] = {5, 4, 3, 2, 1};
    BubbleSort(a, 5);
    for (int i = 0; i < 5; ++i) {
        printf("%d\n", a[i]);
    }
}
