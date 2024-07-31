#ifndef NODE
#define NODE

#include "rocks.h"
#include "edge.h"


struct Node
{
    struct rocks* rock; //makes the rock node
    struct edge* edge; // makes the edges 
    int num;
};

//void node 
void node_init(struct Node* n, int value);

#endif 