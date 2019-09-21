//////////////////////////////////////////////////////////////////////////////
// FileName: graph.h
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//////////////////////////////////////////////////////////////////////////////

#ifndef _GRAPH_H_
#define _GRAPH_H_

#define MaxVertexNum 100

typedef int Vertex;
typedef int WeightType;

typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
    Vertex AdjV;
    WeightType Weight;
    PtrToAdjVNode Next;
};

typedef struct VNode {
    PtrToAdjVNode FirstEdge;
} AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;
typedef PtrToGNode Graph;
struct GNode {
    int Nv;
    int Ne;
    AdjList List;
};

typedef struct ENode *Edge;
struct ENode {
    Vertex V1, V2;
    WeightType Weight;
};

Graph CreateGraph(int VertexNum);
void InsertEdge(Graph G, Edge E);
void InsertDiedge(Graph G, Edge E);
Graph BuildDigraph();
Graph BuildGraph();
void PrintGraph(Graph G);

// 拓扑排序
void TopSort(Graph G);
// 无权最短路径
void Unweighted(Graph G, Vertex Start);
// 有权图最短路径
void Dijkstra(Graph G, Vertex Start);
// Prim 算法最小生成树
void Prim(Graph G);
// Kruskal 算法最小生成树
void Kruskal(Graph G);

#endif /* !GRAPH_H */
