//============================================================================
// FileName: insertion_sort.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

void InsertionSort(ElementType A[], int N) {
    int P, i;
    ElementType Tmp;
    for (P = 1; P < N; ++P) {
        ElementType Tmp = A[P];
        for (i = P; i > 0 && A[i - 1] > Tmp; --i) {
            A[i] = A[i - 1];
        }
        A[i] = Tmp;
    }
}

int main() {
    ElementType a[] = {5, 4, 3, 2, 1};
    InsertionSort(a, 5);
    for (int i = 0; i < 5; ++i) {
        printf("%d\n", a[i]);
    }
}
