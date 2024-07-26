#ifndef NODE
#define NODE

#include "rocks.h"
#include "edge.h"


struct Node
{
    struct rocks* rock;
    struct edge* edge;
};


void node_init(struct Node* n);

#endif 