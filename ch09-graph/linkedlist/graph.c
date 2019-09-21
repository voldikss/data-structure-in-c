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

    for (V = 0; V < G->Nv; ++V) {
        G->List[V].FirstEdge = NULL;
    }
    return G;
}

/* 无向图插入边 */
void InsertEdge(Graph G, Edge E) {
    PtrToAdjVNode NewNode;

    NewNode = malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V2;
    NewNode->Weight = E->Weight;

    NewNode->Next = G->List[E->V1].FirstEdge;
    G->List[E->V1].FirstEdge = NewNode;
    //
    NewNode = malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V1;
    NewNode->Weight = E->Weight;

    NewNode->Next = G->List[E->V2].FirstEdge;
    G->List[E->V2].FirstEdge = NewNode;
}

// 有向图插入边
void InsertDiedge(Graph G, Edge E) {
    PtrToAdjVNode NewNode;

    NewNode = malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V2;
    NewNode->Weight = E->Weight;

    NewNode->Next = G->List[E->V1].FirstEdge;
    G->List[E->V1].FirstEdge = NewNode;
}

void PrintGraph(Graph G) {
    Vertex V;
    PtrToAdjVNode P;

    printf("Number of vertex: %d\n", G->Nv);
    printf("Nearby of edge: %d\n", G->Ne);

    printf("邻接表表示的图打印如下（括号内为权重）：\n");
    for (V = 0; V < G->Nv; ++V) {
        printf("%d-->", V);
        P = G->List[V].FirstEdge;
        while (P) {
            printf("%d(%d)->", P->AdjV, P->Weight);
            P = P->Next;
        }
        printf("NULL");
        printf("\n");
    }
}
