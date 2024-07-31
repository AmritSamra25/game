#ifndef GRAPH
#define GRAPH

#include "node.h"

// graph 
struct Graph
{
    struct Node** nodes;  //Points to an array of nodes (NOTE: this declaration could also apply to a linked list)
    int num_node;
    struct Edge** edges;//Points to an array of edges (NOTE: this declaration could also apply to a linked list)
    int num_edge;
};

//void graph init
void graph_init(struct Graph* g, int num_nodes, int num_edge);

void create_edge(struct Graph* g, struct Node* node1, struct Node* node2);


#endif 