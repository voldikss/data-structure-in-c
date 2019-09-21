//============================================================================
// FileName: stack.h
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#ifndef _STACK_H_
#define _STACK_H_

typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
typedef int ElementType;

struct Node {
    ElementType Element;
    PtrToNode Next;
};

int IsEmpty(Stack S);
Stack CreateStack();
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);

#endif /* !STACK_H */
