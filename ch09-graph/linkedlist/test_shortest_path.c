//////////////////////////////////////////////////////////////////////////////
// FileName: test_unweighted.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//////////////////////////////////////////////////////////////////////////////

#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Graph G;
  G = BuildDigraph();
  PrintGraph(G);
  printf("单源无权最短路径：\n");
  Unweighted(G, 2);
  printf("单源赋权最短路径，使用 Dijkstra 算法的结果：\n");
  Dijkstra(G, 0);
}
