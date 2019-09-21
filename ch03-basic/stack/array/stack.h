//============================================================================
// FileName: stack.h
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#ifndef _STACK_H_
#define _STACK_H_

#define EmptyTOS (-1)
#define MinStackSize (5)

typedef struct StackRecord *Stack;
typedef int ElementType;

struct StackRecord {
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);

#endif /* !STACK_H */
