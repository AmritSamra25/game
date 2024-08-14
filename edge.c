#include <stdio.h>
#include <stdlib.h>

#include "edge.h"

//void edge init
void edge_init(struct Edge* e, struct Node* node1, struct Node* node2){
    int i = 0;
    e->node1 = node1;
    e->node2 = node2;
}

//connect an edge to nodes up to 2 nodes
struct Edge * create_edge(struct Node* node1, struct Node* node2) {

    struct Edge * edge = (struct Edge *) malloc (sizeof (struct Edge));
    edge-> node1 = node1;
    edge-> node2 = node2;
    return edge;

}