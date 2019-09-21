/*
 * hash_quad.c
 * Copyright (C) 2019 voldikss <dyzplus@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include "hash_quad.h"
#include <stdio.h>
#include <stdlib.h>

enum KindOfEntry { Legitimate, Empty, Deleted };

struct HashEntry {
  ElementType Element;
  enum KindOfEntry Info;
};

struct HashTbl {
  int TableSize;
  Cell *TheCells;
};

HashTable InitializeTable(int TableSize) {
  HashTable H;
  int i;

  // allocate table
  H = malloc(sizeof(struct HashTbl));
  if (H == NULL) {
    printf("Error, out of space");
    return NULL;
  }

  H->TableSize = NextPrime(TableSize);

  // allocate array of cells
  H->TheCells = malloc(sizeof(Cell) * H->TableSize);
  if (H->TheCells == NULL) {
    printf("Error, out of space");
    return NULL;
  }

  // initialize cells info
  for (i = 0; i < H->TableSize; ++i)
    H->TheCells[i].Info = Empty;

  return H;
}

Position Find(ElementType Key, HashTable H) {
  Position CurrentPos;
  int CollisionNum;

  CollisionNum = 0;
  CurrentPos = Hash(Key);

  while (H->TheCells[CurrentPos].Info != Empty &&
         H->TheCells[CurrentPos].Element != Key) {

    // 此处根据书中原说明，本来应该是
    // CurrentPos = i^2
    // 但是这样的话就必须设置一个变量i，每次查找都加一，很麻烦
    // 下面的代码巧妙地研究了 F(i) 和 F(i-1) 的关系
    // F(i) = i^2, F(i-1) = (i-1)^2，两者作差可得 F(i) = F(i-1) + 2i -1
    // 于是可以用递推来完成 CurrentPos 的改变
    // 突然发现我之前可能写了不少垃圾代码。。。
    CurrentPos += 2 * ++CollisionNum - 1;
    if (CurrentPos >= H->TableSize)
      CurrentPos -= H->TableSize;
  }

  return CurrentPos;
}

void Insert(ElementType Key, HashTable H) {
  Position Pos;

  Pos = Find(Key, H);

  if (H->TheCells[Pos].Info != Legitimate) {
    H->TheCells[Pos].Info = Legitimate;
    H->TheCells[Pos].Element = Key;
  }
}

HashTable Rehash(HashTable H) {
  int i, OldSize;
  Cell *OldCells;

  OldCells = H->TheCells;
  OldSize = H->TableSize;

  H = InitializeTable(2 * OldSize);

  for (i = 0; i < OldSize; ++i)
    if (OldCells[i].Info == Legitimate)
      Insert(OldCells[i].Element, H);

  free(OldCells);

  return H;
}
