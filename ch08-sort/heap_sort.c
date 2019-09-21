//============================================================================
// FileName: heap_sort.c
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

void PercDown(ElementType A[], int i, int N) {
    ElementType tmp = A[i];
    for (int k = 2 * i + 1; k < N; k = 2 * k + 1) {
        if (A[k] < A[k + 1] && k + 1 < N) k++;
        if (A[k] > tmp) {
            A[i] = A[k];
            i = k;
        } else {
            break;
        }
    }
    A[i] = tmp;
}

void HeapSort(ElementType A[], int N) {
    int i;
    for (i = N / 2; i >= 0; --i) {
        PercDown(A, i, N);
    }
    for (i = N - 1; i > 0; --i) {
        Swap(&A[0], &A[i]);
        PercDown(A, 0, i);
    }
}

int main() {
    ElementType a[] = {5, 4, 3, 2, 1};
    HeapSort(a, 5);
    for (int i = 0; i < 5; ++i) {
        printf("%d\n", a[i]);
    }
}
