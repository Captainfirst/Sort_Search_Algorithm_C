#include "critical_path.h"

int *etv, *ltv;  /* Earlist time and latest time of vertex */
int *stack2;     /* Stack to save topological list */
int top2;        /* Poiter to stack2 */

bool TopologicalSort(GraphAdjList *GL)
{
    EdgeNode *e;
    int i, k, gettop;
    int top = 0;
    int count = 0;
    int *stack;
    stack = (int *)malloc(GL->numVertexes * sizeof(int));
    for (i = 0; i < GL->numVertexes; i++)
        if (0 == GL->adjList[i].in)
            stack[++top] = i;
    top2 = 0;
    etv = (int *)malloc(GL->numVertexes * sizeof(int));
    for (i = 0; i < GL->numVertexes; i++)
        etv[i] = 0;
    stack2 = (int *)malloc(GL->numVertexes * sizeof(int));

    while(top!=0)
    {
        gettop = stack[top--];
        count++;
        stack2[++top2] = gettop;

        for (e = GL->adjList[gettop].firstedge; e; e = e->next)
        {
            k = e->adjvex;
            if(!(--GL->adjList[k].in))
                stack[++top] = k;
            if((etv[gettop]+e->weight) > etv[k])
                etv[k] = etv[gettop] + e->weight;
        } 
    }
    if(count < GL->numVertexes)
        return false;
    else
        return true;
}

void CriticalPath(GraphAdjList* GL)
{
    EdgeNode *e;
    int i, gettop, k, j;
    int ete, lte;
    TopologicalSort(GL);
    ltv = (int *)malloc(GL->numVertexes * sizeof(int));
    for (i = 0; i < GL->numVertexes; i++)
        ltv[i] = etv[GL->numVertexes-1];
    while(top2!=0)
    {
        gettop = stack2[top2--];
        for (e = GL->adjList[gettop].firstedge; e; e = e->next)
        {
            k = e->adjvex;
            if(ltv[k]-e->weight < ltv[gettop])
                ltv[gettop] = ltv[k] - e->weight;
        }
    }
    for (j = 0; j < GL->numVertexes; j++)
    {
        for (e = GL->adjList[j].firstedge; e; e = e->next)
        {
            k = e->adjvex;
            ete = etv[j];
            lte = ltv[k] - e->weight;
            if(ete = lte)
            {
                printf("<v%d, v%d> length: %d, ", GL->adjList[j].data,
                       GL->adjList[k].data, e->weight);
            }
        }
    }
}