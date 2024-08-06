#include "edge.h"

//void edge init
void edge_init(struct Edge* e, struct Node* node1, struct Node* node2){
    int i = 0;
    e->node1 = node1;
    e->node2 = node2;
}