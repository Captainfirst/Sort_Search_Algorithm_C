#include "TopologicalSort.h"

bool TopologicalSort(GraphAdjList *GL)
{
    EdgeNode *e;
    int i, gettop, k;
    int top = 0;
    int count = 0;
    int *stack;
    stack = (int *)malloc(GL->numVertexes * sizeof(int));
    for (i = 0; i < GL->numVertexes; i++)
    {
        if (GL->adjList[i].in == 0)
            stack[++top] = i;
    }
    while (top!=0)
    {
        gettop = stack[top--];
        printf("%d -> ", GL->adjList[gettop].data);
        count++;
        for (e=GL->adjList[gettop].firstedge; e; e=e->next)
        {
            k = e->adjvex;
            if (!(--GL->adjList[k].in))
                stack[++top] = k;
        }
    }
    if (count < GL->numVertexes)
        return false;
    else
        return true;
}
