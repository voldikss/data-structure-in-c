//============================================================================
// FileName: huffman_tree.h
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#ifndef _HUFFMAN_TREE_H_
#define _HUFFMAN_TREE_H_

#include "min_heap.h"

typedef struct TreeNode *HuffmanTree;
struct TreeNode {
    int Weight;
    HuffmanTree Left, Right;
};

HuffmanTree Huffman(MinHeap H);

#endif /* !HUFFMAN_TREE_H */
