/*
 * hash_sep.h
 * Copyright (C) 2019 voldikss <dyzplus@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef _HASH_SEP_H_
#define _HASH_SEP_H_

typedef int ElementType;

struct ListNode;
typedef struct ListNode *List;
typedef List Position;

struct HashTbl;
typedef struct HashTbl *HashTable;

unsigned Hash(const ElementType Key, int TableSize);

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable *H);
Position Find(ElementType X, HashTable H);
void Insert(ElementType X, HashTable T);
ElementType Retrieve(Position P);
void Delete(ElementType X, HashTable H);
HashTable MakeEmpty(HashTable H);

#endif /* !HASH_SEP_H */
