#ifndef GRAPH
#define GRAPH

#include "node.h"


struct Graph
{
    struct node* nodes;  //Points to an array of nodes (NOTE: this declaration could also apply to a linked list)
};


void graph_init(struct Graph* g);

#endif 