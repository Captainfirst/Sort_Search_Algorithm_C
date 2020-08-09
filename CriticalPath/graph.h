#ifndef _GRAPH_H
#define _GRAPH_H

#define MAXVEX 100

typedef char VertexType;
typedef int EdgeType;

typedef struct EdgeNode
{
    int adjvex;
    EdgeType weight;
    struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode
{
    VertexType data;
    EdgeType in;
    EdgeNode *firstedge;
}VertexNode,  AdjList[MAXVEX];

typedef struct
{
    AdjList adjList;
    int numVertexes, numEdges;
}GraphAdjList;

#endif
