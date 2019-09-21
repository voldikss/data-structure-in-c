//============================================================================
// FileName: list.h
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#ifndef _LIST_H_
#define _LIST_H_

#define SpaceSize 100

typedef int ElementType;
typedef int PtrToNode;
typedef PtrToNode List;
typedef List Position;

struct Node {
    ElementType Element;
    Position Next;
};

struct Node CursorSpace[SpaceSize];

void InitializeCursorSpace(void);
List MakeEmpty(List L);
int IsEmpty(const List L);
int IsLast(const Position P, const List L);
Position Find(ElementType X, const List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, const List L);
void Insert(ElementType X, Position P, List L);
void DeleteList(List L);
Position Header(const List L);
Position First(const List L);
Position Advance(const Position P);
ElementType Retrieve(const Position P);

#endif /* !LIST_H */

