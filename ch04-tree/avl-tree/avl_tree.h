//============================================================================
// FileName: avl_tree.h
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_

typedef int ElementType;
struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

AvlTree MakeEmpty(AvlTree T);
Position Find(ElementType X, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ElementType X, AvlTree T);
AvlTree Delete(ElementType X, AvlTree T);
ElementType Retrieve(Position P);
static int Height(AvlTree T);
static AvlTree SingleRotateWithLeft(AvlTree T);
static AvlTree DoubleRotateWithLeft(AvlTree T);
static AvlTree SingleRotateWithRight(AvlTree T);
static AvlTree DoubleRotateWithRight(AvlTree T);

#endif /* !AVL_TREE_H */
