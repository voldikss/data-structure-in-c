//////////////////////////////////////////////////////////////////////////////
// FileName: main.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//////////////////////////////////////////////////////////////////////////////

#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Graph G;
  G = BuildGraph();
  PrintGraph(G);
}
