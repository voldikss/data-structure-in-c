/*
 * hash_quad.h
 * Copyright (C) 2019 voldikss <dyzplus@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef _HASH_QUAD_H_
#define _HASH_QUAD_H_

typedef int ElementType;

typedef unsigned int Index;
typedef Index Position;

struct HashEntry;
typedef struct HashEntry Cell;

struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType X, HashTable H);
void Insert(ElementType Key, HashTable H);
ElementType Retrieve(Position P, HashTable H);
HashTable Rehash(HashTable H);

unsigned NextPrime(unsigned Num);
unsigned Hash(ElementType Key);

#endif /* !HASH_QUAD_H */
