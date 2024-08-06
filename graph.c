#include <stdlib.h>
#include <stdio.h>
#include "graph.h"


void graph_init(struct Graph* g, int width, int height, int num_edge){

    // Set the number of nodes for the graph
    g->num_node = width*height;
    // Allocate enough space for an array (size of array: num_nodes) of pointers to node pointer
    struct Node** nodes = (struct Node **) malloc (g->num_node * sizeof (struct Node*)); //this allocates memory for num_nodes nodes
    // Set the adress of the nodes pointer to point to the newly created array.
    g->nodes = nodes; // g points to the nodes, from graph.h
    printf("_________%d", g->num_node);
    int i=0;
    int j=0;
    for(i=0; i<width; i++){
        for(j=0; j<height; j++){
        // For each node pointer in the array:
        // Allocate a node to point to & return its address to the variable "node"
        struct Node* node = (struct Node*) malloc ( sizeof (struct Node));
        // Set the value of num for the newly created node to be equal to the array index
        node -> num = i;
        // Store the address of the new node in the array of pointers to node
        nodes[i][j] = node;
        }
        
    }

    g->num_edge = num_edge;
    struct Edge** edges = (struct Edge **) malloc (num_edge * sizeof (struct Edge*)); //this allocates memory for num_nodes nodes
    // Save the address of the edges array in the graph structure
    g->edges = edges; // g points to the nodes, from graph.h

   
    for(i=0; i<num_edge; i++){
        edges[i] = 0;
    }

}

//connect an edge to nodes up to 2 nodes
void create_edge(struct Graph* g,struct Node* node1, struct Node* node2) {

    struct Edge * edge = (struct Edge *) malloc (sizeof (struct Edge));
    edge-> node1 = node1;
    edge-> node2 = node2;

}