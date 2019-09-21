//============================================================================
// FileName: mst.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//============================================================================

#include "graph.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

Vertex Path[MaxVertexNum];
int Dist[MaxVertexNum];
int Known[MaxVertexNum];

void PrintTree(Graph G) {
  for (Vertex V = 0; V < G->Nv; ++V) {
    printf("(%d, %d) ", V + 1, Path[V] + 1);
  }
}

/* 只在距离更新上和 Dijkstr 算法有点区别 */
void Prim(Graph G) {
  Vertex V, W, MinV;
  Vertex Start = 0; // 选择从0节点开始
  int MinDist;
  int i;

  /* 初始化 */
  for (V = 0; V < G->Nv; ++V) {
    Path[V] = -1;
    Known[V] = 0;
    if (V == Start) {
      Dist[V] = 0;
    } else {
      Dist[V] = INT_MAX;
    }
  }

  /* 如果图是稠密的就基本上最优 */
  while (1) {
    /* 找到未知的具有最小路径的点 TODO: 使用最小堆实现 */
    MinDist = INT_MAX;
    MinV = -1;
    for (V = 0; V < G->Nv; ++V)
      if (!Known[V]) {
        if (Dist[V] < MinDist) {
          MinV = V;
          MinDist = Dist[V];
        }
      }
    if (MinV == -1) break;

    Known[MinV] = 1;
    PtrToAdjVNode P = G->List[MinV].FirstEdge;
    while (P) {
      W = P->AdjV;
      if (!Known[W]) {
        if (P->Weight < Dist[W]) {
          Dist[W] = P->Weight;
          Path[W] = MinV;
        }
      }
      P = P->Next;
    }
  }

  for (int i=0; i < G->Nv; ++i){
    if (!Known[i]){
      printf("生成树不存在，即图不连通！");
      exit(1);
    }
  }

  /* 打印出树 */
  printf("生成树为：");
  PrintTree(G);
  printf("\n");

  /* 打印出总距离 */
  int TotalDist = 0;
  for (int i = 0; i < G->Nv; ++i) {
    TotalDist += Dist[i];
  }
  printf("生成树的总值为：%d\n", TotalDist);
}

/* 对于稀疏图，较 Prim 算法好一些 */
void Kruskal(Graph G){
  // TODO
}
