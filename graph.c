#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

void graph_init(struct Graph* g, int width, int height, int edge_array_size) {
    printf("_________width %d, height %d", width, height);

    // Set the number of nodes for the graph
    g->width = width;
    g->height = height;
    
    // Allocate enough space for a 2-D array (size of array: width * height)of pointers to node pointer
    struct Node*** nodes = (struct Node ***) malloc (width * sizeof (struct Node**));
    // Set the adress of the nodes pointer to point to the newly created array.
    int count = 0;
    for(int w=0; w<width; w++){
        // Allocate enough space for an array of node pointers (a row)
        struct Node** row = (struct Node**)malloc(height * sizeof(struct Node*));
        nodes[w] = row;
        printf("hhhhhhhhhhhhhhhhh\n");

        for(int h=0; h<height; h++){
        
                // For each node pointer in the row:
	            // Allocate a node to point to & return its address to the variable "node"
	            struct Node* node = (struct Node*) malloc ( sizeof (struct Node));
	            // Set the value of num for the newly created node to be equal to the array index
                    count = h*width + w;
	            node -> num = count;
                    node -> x = w;
                    node -> y = h;
                    //	            count++;
                printf("hhhhhdhdhdhhdhddhdhhdhdhddhdhdh %d \n ",count);
                // Store the address of the new node in the array of pointers to node
	            nodes[w][h] = node;



            }
    }

    // Save the new array of node pointers
    g->nodes = nodes;
    // Save the number of edges.
    g->edge_array_size = edge_array_size;
    // Allocate enough memory for a 1-D array of edges, size  edge_array_size
    struct Edge** edges = (struct Edge **) malloc (edge_array_size * sizeof (struct Edge*));
    // Save the address of the edges array in the graph structure
    g->edges = edges; // g points to the nodes, from graph.h


    // Initialize the edge array to contain a bunch of null pointers.
    // The edges will be created inidividually in add_edge (see below).
    for(int i=0; i<edge_array_size; i++){
        edges[i] = 0;
    }
    g->num_edge = 0;  // We haven't created any edges yet, just set the pointers to null

}

// Add an edge to the graph.  Every edge connects to two existing nodes.
// x1, y1, x2, and y2 are the array indices of the nodes in the graph.
//
// Return values:
//    0 for success
//    -1 if the edge already exists.
//
int add_edge(struct Graph* g,int x1, int y1, int x2, int y2){
    int already_exists;
    //    if (edge_exists(g, x1, y1, x2, y2)) {
    already_exists = edge_exists(g, x1, y1, x2, y2);
    if (already_exists) {
      return -1; // Edge already exists
    }

    struct Node* node1 = g->nodes[x1][y1];
    struct Node* node2 = g->nodes[x2][y2];
    struct Edge* edge = create_edge(node1, node2);
    
    int num_of_edges = g->num_edge;

    g->edges[num_of_edges] = edge;
    g->num_edge++;

    for (int i=0; i<g->num_edge; i++) {
      edge = g->edges[i];
    }
    return 0;
}


/*
Returns 1 if an edge exists that connects nodes with X,Y locations (x1,y1) and (x2, y2)
Returns 0 otherwise.
*/
int edge_exists (struct Graph* g, int x1, int y1, int x2, int y2) {
  // Iterate through all of the existing edges
  for(int e = 0; e < g->num_edge; e++){
    // Get the (x,y) locations of the two nodes attached to the edge
    int xtmp1 = g->edges[e]->node1->x;
    int ytmp1 = g->edges[e]->node1->y;
    int xtmp2 = g->edges[e]->node2->x;
    int ytmp2 = g->edges[e]->node2->y;

    // If the (x,y) locations match the ones from the parameter list,
    // return immediately.
    if ((xtmp1==x1) && (ytmp1==y1) &&
        (xtmp2==x2) && (ytmp1==y2)) return 1;
    
    if ((xtmp2==x1) && (ytmp2==y1) &&
        (xtmp1==x2) && (ytmp1==y2)) return 1;
  }

  // No nodes were found that match the two (x,y) coordinates.
  return 0;
}
