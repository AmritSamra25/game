#include <stdlib.h>
#include <stdio.h>
#include "graph.h"


void graph_init(struct Graph* g, int width, int height, int num_edge){
    printf("_________width %d, height %d", width, height);

    // Set the number of nodes for the graph
    g->width = width;
    g->height = height;
    
    // Allocate enough space for a 2-D array (size of array: width * height)of pointers to node pointer
    struct Node*** nodes = (struct Node ***) malloc (width * sizeof (struct Node**));
    // Set the adress of the nodes pointer to point to the newly created array.
    int count = 0;
    for(int i=0; i<width; i++){
        // Allocate enough space for an array of node pointers (a row)
        struct Node** row = (struct Node**)malloc(height * sizeof(struct Node*));
	    nodes[i] = row;
	
        for(int j=0; j<height; j++){
	  // For each node pointer in the row:
	  // Allocate a node to point to & return its address to the variable "node"
	        struct Node* node = (struct Node*) malloc ( sizeof (struct Node));
	  // Set the value of num for the newly created node to be equal to the array index
	        node -> num = count;
	        count++;
	  // Store the address of the new node in the array of pointers to node
	        nodes[i][j] = node;
        }
    }

    // Save the new array of node pointers
    g->nodes = nodes;
    // Save the number of edges.
    g->num_edge = num_edge;
    // Allocate enough memory for a 1-D array of edges, size  num_edge
    struct Edge** edges = (struct Edge **) malloc (num_edge * sizeof (struct Edge*));
    // Save the address of the edges array in the graph structure
    g->edges = edges; // g points to the nodes, from graph.h
   
    for(int i=0; i<num_edge; i++){
        edges[i] = 0;
    }

}

void add_edge(struct Graph* g,int x1, int y1, int x2, int y2){
    printf("add_edge: %d %d %d %d\n", x1, y1, x2, y2);
    struct Node* node1 = g->nodes[x1][y1];
    struct Node* node2 = g->nodes[x2][y2];
    struct Edge* edge = create_edge(node1, node2);
    printf("Incrementing number of edges: %d\n", g->num_edge);
    int num_of_edges = g->num_edge;

    g->edges[num_of_edges] = edge;
    g->num_edge++;

    printf("Incrementing number of edges(2): %d\n", g->num_edge);


}



