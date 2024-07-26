
#include "node.h"
void node_init(struct Node* n){

    n->rock = 0;
    n->edge = 0; // points to nothing (null pointer) for safety
}