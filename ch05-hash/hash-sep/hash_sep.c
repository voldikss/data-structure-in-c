/*
 * hash_sep.c
 * Copyright (C) 2019 voldikss <dyzplus@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include "hash_sep.h"
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  ElementType Element;
  Position Next;
};

struct HashTbl {
  int TableSize;
  List *TheLists;
};

HashTable InitializeTable(int TableSize) {
  HashTable H;
  int i;

  // allocate table
  H = malloc(sizeof(struct HashTbl));
  if (H == NULL) {
    printf("Error");
    return NULL;
  }

  H->TableSize = TableSize;

  // allocate array of lists
  // Note: sizeof(List)! not sizeof(struct ListNode)
  H->TheLists = malloc(sizeof(List) * TableSize);

  // allocate for list headers
  for (i = 0; i < TableSize; ++i) {
    H->TheLists[i] = malloc(sizeof(struct ListNode));
    if (H->TheLists[i])
      printf("Error");
    else
      H->TheLists[i]->Next = NULL;
  }

  return H;
}

Position Find(ElementType Key, const HashTable H) {
  Position P;
  List L;

  if (H == NULL)
    return NULL;

  L = H->TheLists[Hash(Key, H->TableSize)];
  P = L->Next;

  /* NOTE: 这简直是其丑无比的写法，看下面简洁的写法！
  while (P != NULL) {
    if (P->Element == X)
      return P;
    P = P->Next;
  }
  return NULL;
  */

  while (P != NULL && P->Element != Key)
    P = P->Next;
  return P;
}

void Insert(const ElementType Key, HashTable H) {
  List L, NewCell;
  Position P;

  L = H->TheLists[Hash(Key, H->TableSize)];
  P = L->Next;

  // do 'Find'
  while (P != NULL && P->Element != Key)
    P = P->Next;

  // not found
  if (P == NULL) {
    NewCell = malloc(sizeof(struct ListNode));
    NewCell->Element = Key;
    NewCell->Next = L->Next;
    L->Next = NewCell;
  }
}

ElementType Retrieve(Position P) {
  if (P == NULL)
    return NULL;
  else
    return P->Element;
}
