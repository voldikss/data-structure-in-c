//============================================================================
// FileName: huffman_tree.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================


#include "huffman_tree.h"
#include "min_heap.h"
#include <stdlib.h>

HuffmanTree Huffman(MinHeap H) {
    int i;
    HuffmanTree T;
    BuildMinHeap(H);
    for (i = 1; i < H->Size; i++) {
        T = malloc(sizeof(struct TreeNode));
        T->Left = DeleteMin(H);
        T->Right = DeleteMin(H);
        T->Weight = T->Left->Weight + T->Right->Weight;
        Insert(H, T);
    }
    T = DeleteMin(H);
    return T;
}
