//////////////////////////////////////////////////////////////////////////////
// FileName: unweighted.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//////////////////////////////////////////////////////////////////////////////

#include "graph.h"
#include "queue.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

Vertex Path[MaxVertexNum];
int Dist[MaxVertexNum];
int Known[MaxVertexNum];

/* 递归地打印出从 Start 到 V 的路径 */
void PrintPath(Vertex V, Vertex Start) {
  if (V == Start) {
    printf("%d", Start);
    return;
  } else {
    PrintPath(Path[V], Start);
  }
  printf("->%d", V);
  return;
}

/*
   输入的图是有权图，但是此处将其视为无权图
   即不使用 Weight 属性
 */
void Unweighted(Graph G, Vertex Start) {
  Vertex V, W;
  int CurrDist;
  int i;

  /* 初始化数组 */
  for (V = 0; V < G->Nv; ++V) {
    Path[V] = -1;
    Known[V] = 0;
    if (V == Start) {
      Dist[V] = 0;
    } else {
      Dist[V] = -1;
    }
  }

  /*
     无权最短路径，这种实现方法运行时间 O(V^2)
     复杂度 O(V^2)
     */
  // for (CurrDist = 0; CurrDist < G->Nv; ++CurrDist) {
  //   for (V = 0; V < G->Nv; ++V) {
  //     if (!Known[V] && Dist[V] == CurrDist) {
  //       Known[V] = 1;
  //       PtrToAdjVNode P = G->List[V].FirstEdge;
  //       while (P) {
  //         W = P->AdjV;
  //         if (Dist[W] == -1) {
  //           Dist[W] = CurrDist + 1;
  //           Path[W] = V;
  //         }
  //         P = P->Next;
  //       }
  //     }
  //   }
  // }

  /*
     使用队列实现，其实就是广度优先搜索
     复杂度 O(V+E)
  */
  Queue Q;
  Q = CreateQueue();
  Enqueue(Start, Q);
  while (!IsEmpty(Q)) {
    V = Dequeue(Q);
    PtrToAdjVNode P = G->List[V].FirstEdge;
    while (P) {
      W = P->AdjV;
      if (Dist[W] == -1) {
        Dist[W] = Dist[V] + 1;
        Path[W] = V;
        Enqueue(W, Q);
      }
      P = P->Next;
    }
  }
  DisposeQueue(Q);

  /* 打印出各顶点的路经长 */
  for (V = 0; V < G->Nv; ++V) {
    printf("Distance from %d to %d is: %d; ", Start, V, Dist[V]);
    printf("The path is: ");
    PrintPath(V, Start);
    printf("\n");
  }
}

/* 对于有权图的排序 */
void Dijkstra(Graph G, Vertex Start) {
  Vertex V, W, MinV;
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
      if (Known[V] == 0) {
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
        if (Dist[MinV] + P->Weight < Dist[W]) {
          Dist[W] = Dist[MinV] + P->Weight;
          Path[W] = MinV;
        }
      }
      P = P->Next;
    }
  }

  /* 打印出各顶点的路经长 */
  for (V = 0; V < G->Nv; ++V) {
    printf("Distance from %d to %d is: %d; ", Start, V, Dist[V]);
    printf("The path is: ");
    PrintPath(V, Start);
    printf("\n");
  }
}
