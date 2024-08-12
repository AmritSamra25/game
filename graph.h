#ifndef GRAPH
#define GRAPH

#include "node.h"

// graph 
struct Graph
{
    int width;
    int height;
    struct Node*** nodes;  //Points to a 2-D array of nodes, size width x height
    struct Edge** edges;//Points to an array of edges (NOTE: this declaration could also apply to a linked list)
    int num_edge;
};

//void graph init
//this assumes the graph structure has already been created
void graph_init(struct Graph* g, int width, int height, int num_edge);

void add_edge(struct Graph* g,int x1, int y1, int x2, int y2);


#endif