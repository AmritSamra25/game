#ifndef EDGE
#define EDGE

#include "node.h"

//struct edge
struct Edge
{
    struct node* node2; // makes the node 
    struct node* node1; // makes the node 
};

//void edge init
void edge_init(struct Edge* n);

#endif 