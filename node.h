#ifndef NODE
#define NODE

#include "rocks.h"
#include "edge.h"


struct Node
{
    struct Rocks* rock; //makes the rock node
    int num;
    int x;
    int y;
};

//void node 
void node_init(struct Node* n, int value, int x, int y);

#endif 
