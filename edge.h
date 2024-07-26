#ifndef EDGE
#define EDGE

#include "node.h"


struct Edge
{
    struct node* node2;
    struct node* node1;
};


void edge_init(struct Edge* n);

#endif 