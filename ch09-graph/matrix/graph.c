//////////////////////////////////////////////////////////////////////////////
// FileName: graph.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//////////////////////////////////////////////////////////////////////////////

#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

Graph CreateGraph(int VertexNum) {
  if (VertexNum > MaxVertexNum) {
    printf("Vertex number is too large");
    exit(EXIT_FAILURE);
  }

  Vertex V, W;
  Graph G;

  G = malloc(sizeof(struct GNode));
  G->Nv = VertexNum;
  G->Ne = 0;

  for (V = 0; V < G->Nv; ++V)
    for (W = 0; W < G->Nv; ++W)
      G->Matrix[V][W] = 0;

  return G;
}

// not used
// Edge CreateEdge(Vertex V1, Vertex V2, WeightType Weight) {
//   Edge E;
//   E = malloc(sizeof(struct ENode));
//   E->V1 = V1;
//   E->V2 = V2;
//   E->Weight = Weight;
//   return E;
// }

void InsertEdge(Graph G, Edge E) {
  // 插入边 <V1, V2>
  G->Matrix[E->V1][E->V2] = E->Weight;

  // 如果是有向图
  G->Matrix[E->V2][E->V1] = E->Weight;
};

void PrintGraph(Graph G) {
  int V;
  int W;

  printf("Number of vertex: %d\n", G->Nv);
  printf("Nearby of edge: %d\n", G->Ne);

  for (V = 1; V < G->Nv; ++V) {
    for (W = 1; W < G->Nv; ++W) {
      printf(" %d", G->Matrix[V][W]);
    }
    printf("\n");
  }
}

// use redirection data from ./graph.dat
Graph BuildGraph() {
  Graph G;
  Edge E;
  int Nv;
  int i;

  scanf("%d", &Nv);
  G = CreateGraph(Nv);
  scanf("%d", &G->Ne);
  if (G->Ne != 0) {
    E = malloc(sizeof(struct ENode));
    for (i = 0; i < G->Ne; ++i) {
      scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
      InsertEdge(G, E);
    }
  }
  return G;
}
