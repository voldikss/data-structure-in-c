//============================================================================
// FileName: list.h
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#ifndef _LIST_H_
#define _LIST_H_

#define MAXSIZE 100

typedef int ElementType;
typedef int Position;

typedef struct Node *PtrToNode;
typedef PtrToNode List;
struct Node {
    ElementType Elements[MAXSIZE];
    int Last;
};

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
void DeleteList(List L);
ElementType Retrieve(Position P, List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
Position FindPrev(ElementType X, List L);
void Insert(ElementType X, List L, Position P); // insert before the position

#endif /* !LIST_H */
