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
//this assumes the graph structure has already been created
void graph_init(struct Graph* g, int width, int height, int num_edge);

void create_edge(struct Graph* g, struct Node* node1, struct Node* node2);


#endif 