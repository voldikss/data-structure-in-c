//////////////////////////////////////////////////////////////////////////////
// FileName: test_graph.c
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//////////////////////////////////////////////////////////////////////////////

#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

/* 无向图构建 */
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
}

// 有向图构建 */
Graph BuildDigraph() {
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
            InsertDiedge(G, E);
        }
    }
}

int main() {
    Graph G;
    BuildDigraph(G);
    PrintGraph(G);
}
