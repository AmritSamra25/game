
#include "node.h"
void node_init(struct Node* n, int value){

    n->rock = 0; // points to nothing (null pointer) for safety
    n->edge = 0; // points to nothing (null pointer) for safety
    n->num = value; //points to a num value 
}