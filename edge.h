#ifndef EDGE
#define EDGE

#define MAX_NUM_NODES 8
#include  <stdlib.h>

#include "node.h"


//struct edge
struct Edge
{
    struct Node* node1;
    struct Node* node2;
    
};

//void edge init
//e = (pointer to) the edge to initialize
//num_nodes = number of nodes to assign.
//node1, node2 = nodes to connect to an edge (max 2, negative node # means no noded)
void edge_init(struct Edge* e, struct Node* node1, struct Node* node2);

struct Edge * create_edge(struct Node* node1, struct Node* node2);

#endif 