#ifndef EDGE
#define EDGE

#include "node.h"


struct Edge
{
    struct node* node2; // makes the node 
    struct node* node1; // makes the node 
};


void edge_init(struct Edge* n);

#endif 