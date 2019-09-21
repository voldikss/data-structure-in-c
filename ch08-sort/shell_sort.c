//============================================================================
// FileName: shell_sort.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

void ShellSort(ElementType A[], int N) {
    int D, P, i;
    ElementType Tmp;
    for (D = N / 2; D > 0; D /= 2) {
        for (P = D; P < N; ++P) {
            Tmp = A[P];
            for (i = P; i >= D && A[i - D] > Tmp; i -= D) {
                A[i] = A[i - D];
            }
            A[i] = Tmp;
        }
    }
}

int main() {
    ElementType a[] = {5, 4, 3, 2, 1};
    ShellSort(a, 5);
    for (int i = 0; i < 5; ++i) {
        printf("%d\n", a[i]);
    }
}
