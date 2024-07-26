#ifndef GRAPH
#define GRAPH

#include "node.h"


struct Graph
{
    struct node* nodes;  //Points to an array of nodes
};


void edge_init(struct Graph* n);

#endif 