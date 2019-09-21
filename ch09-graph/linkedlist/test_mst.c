//============================================================================
// FileName: test_mst.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Graph G;
  G = BuildGraph();
  PrintGraph(G);
  printf("使用 Prim 算法找出最小生成树");
  Prim(G);
  printf("使用 Kruskal 算法找出最小生成树");
  Kruskal(G);
}
