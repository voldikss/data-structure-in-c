//////////////////////////////////////////////////////////////////////////////
// FileName: graph.h
// Descrption:
// Author: voldikss <dyzplus@gmail.com>
// GitHub: https://github.com/voldikss
//////////////////////////////////////////////////////////////////////////////

#ifndef _GRAPH_H_
#define _GRAPH_H_

#define MaxVertexNum 100

typedef int ElementType;
typedef int Vertex;
typedef int WeightType;

typedef struct GNode *PtrToGNode;
typedef PtrToGNode Graph;
struct GNode {
  int Nv;
  int Ne;
  ElementType Matrix[MaxVertexNum][MaxVertexNum];
};

typedef struct ENode *PtrToENode;
typedef PtrToENode Edge;
struct ENode {
  Vertex V1;
  Vertex V2;
  WeightType Weight;
};

Graph CreateGraph(int VertexNum);
void InsertEdge(Graph G, Edge E);
void PrintGraph(Graph G);
Graph BuildGraph();

#endif /* !GRAPH_H */
