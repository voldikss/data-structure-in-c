//////////////////////////////////////////////////////////////////////////////
// FileName: topsort.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//////////////////////////////////////////////////////////////////////////////

#include "graph.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int Indegree[MaxVertexNum];
int TopNum[MaxVertexNum];

void CalcIndegree(Graph G) {
  Vertex V;

  for (Vertex V = 0; V < G->Nv; ++V) {
    Indegree[V] = 0;
  }
  for (Vertex V = 0; V < G->Nv; ++V) {
    PtrToAdjVNode P;
    P = G->List[V].FirstEdge;
    while (P) {
      Indegree[P->AdjV]++;
      P = P->Next;
    }
  }
}

void PrintIndegree(Graph G) {
  printf("各个点的入度：");
  for (Vertex V = 0; V < G->Nv; ++V) {
    printf("(%d %d)", V, Indegree[V]);
  }
  printf("\n");
}

void TopSort(Graph G) {
  int Counter = 0;
  Vertex V, W;

  CalcIndegree(G);
  /* 创建队列，保存入度为0的顶点 */
  Queue Q = CreateQueue();
  /* 打印各个顶点的入度 */
  PrintIndegree(G);

  /*
     开始拓扑排序，当数据较大时效率较低
     复杂度 O(V^2)
  */
  //   for (Counter = 0; Counter < G->Nv; ++Counter) {
  //     int found = 0;
  //     /* 找到下一个入度不为0的顶点 */
  //     for (int i = 0; i < G->Nv; ++i) {
  //       if (Indegree[i] == 0) {
  //         found = 1;
  //         printf("Indegree of vertex %d is zero\n", i);
  //         V = i;
  //         Indegree[i]--;
  //         break;
  //       }
  //     }

  //     if (!found) {
  //       printf("Graph has a cycle");
  //       exit(EXIT_FAILURE);
  //     }

  //     /* 存放拓扑编号 */
  //     TopNum[V] = Counter;

  //     /* 去掉边，即将与其相连的各顶点的入度减一 */
  //     PtrToAdjVNode P = G->List[V].FirstEdge;
  //     while (P != NULL) {
  //       W = P->AdjV;
  //       P = P->Next;
  //       Indegree[W]--;
  //     }
  //     /* 相邻顶点入度减一后再输出各个顶点的入度 */
  //     PrintIndegree(G);
  //   }

  /*
     上面方法的改进版
     使用一个队列用来存储入度为 0 的顶点
     避免了每次都去遍历 Indegree 表
     复杂度 O(V+E)
  */
  for (V = 0; V < G->Nv; ++V) {
    if (Indegree[V] == 0) {
      Enqueue(V, Q);
    }
  }

  while (!IsEmpty(Q)) {
    V = Dequeue(Q);
    TopNum[V] = Counter++;

    PtrToAdjVNode P = G->List[V].FirstEdge;
    while (P) {
      W = P->AdjV;
      if (--Indegree[W] == 0) Enqueue(W, Q);
      P = P->Next;
    }
  }

  DisposeQueue(Q);

  if (Counter != G->Nv) {
    printf("Graph has a cycle");
    exit(EXIT_FAILURE);
  }

  /*
     按照正确的顺序输出每个顶点
     这里使用的简单的桶排序
     因为 TopNum 数组保存的是每个顶点的优先级
  */
  int Bucket[G->Nv];
  for (V = 0; V < G->Nv; ++V) {
    Bucket[TopNum[V]] = V;
  }
  printf("最后的顶点排序为：");
  for (int i = 0; i < G->Nv; ++i) {
    printf("%d ", Bucket[i]);
  }
  printf("\n");
}
