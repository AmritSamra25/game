#include "graph.h"

void graph_init(struct Graph* g, int num_nodes, int num_edge){

    
    g->num_node = num_nodes;
    struct Node** nodes = (struct Node *) malloc (num_nodes * sizeof (struct Node*)); //this allocates memory for num_nodes nodes
    g->nodes = nodes; // g points to the nodes, from graph.h

    int i=0;
    for(i=0; i<num_nodes; i++){
        nodes[i]->num = i;
    }

    g->num_edge = num_edge;
    struct Edge** edges = (struct Edge *) malloc (num_edge * sizeof (struct Edge*)); //this allocates memory for num_nodes nodes
    g->edges = edges; // g points to the nodes, from graph.h

    int i=0;
    for(i=0; i<num_edge; i++){
        edges[i] = 0;
    }

}

void create_edge(struct Graph* g,struct Node* node1, struct Node* node2) {

    struct Edge * edge = (struct Edge *) malloc (sizeof (struct Edge));
    edge-> node1 = node1;
    edge-> node2 = node2;

}