//============================================================================
// FileName: binary_search_tree.h
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#ifndef _TREE_H_
#define _TREE_H_

struct TreeNode;
typedef int ElementType;
typedef struct TreeNode *Position;
typedef struct TreeNode *BinarySearchTree;

BinarySearchTree MakeEmpty(BinarySearchTree T);
Position Find(ElementType X, BinarySearchTree T);
Position FindMin(BinarySearchTree T);
Position FindMax(BinarySearchTree T);
BinarySearchTree Insert(ElementType X, BinarySearchTree T);
BinarySearchTree Delete(ElementType X, BinarySearchTree T);
ElementType Retrieve(Position P);
void PrintTree(BinarySearchTree T);

#endif /* !TREE_H */
