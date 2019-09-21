//============================================================================
// FileName: hash.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include "hash.h"
#include <stdio.h>

/*
Index Hash(const char *Key, int TableSize) {
  unsigned int HashVal = 0;

  while (*Key != '\0')
    HashVal += *Key++;

  return HashVal;
}
*/

/*
Index Hash(const char *Key, int TableSize) {
  return HashVal = Key[0] + 27 * Key[1] + 729 * Key[2];
}
*/

Index Hash(const char *Key, int TableSize) {
    unsigned int HashVal = 0;

    while (*Key != '\0') HashVal = (HashVal << 5) + *Key++;

    return HashVal;
}
