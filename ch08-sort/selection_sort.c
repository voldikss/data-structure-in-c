//============================================================================
// FileName: selection_sort.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

void Swap(ElementType A[], int i, int k) {
    ElementType tmp;
    tmp = A[i];
    A[i] = A[k];
    A[k] = tmp;
}

void SelectionSort(ElementType A[], int N) {
    ElementType MinVal;
    int MinPos;
    int i;
    int k;
    for (i = 0; i < N; ++i) {
        MinVal = A[i];
        MinPos = i;
        for (k = i; k < N; ++k)
            if (A[k] < MinVal) MinPos = k;
        Swap(A, i, MinPos);
    }
}

int main() {
    ElementType a[] = {5, 4, 3, 2, 1};
    SelectionSort(a, 5);
    for (int i = 0; i < 5; ++i) {
        printf("%d\n", a[i]);
    }
}
