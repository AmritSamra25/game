#include <stdlib.h>
#include <stdio.h>
#include "board.h"
#include "graph.h"

/* 
 * Initialize the board.
 * Parameters:
 *     b - a pointer to the board to initialize.
 *     width - the new board width (number of nodes)
 *     height - the new board height (number of nodes)
 *
 * Returns:
 *     0 if the initialization went OK
 *    -1 if b is 0.
 *    -2 if width or height is <= 0.
 *
 * Notes:
 *     If b is uninitialized, the results are undefined.
 *     width and height must be positive integers.
 */
int board_init(struct Board* b, int width, int height) {
    if (b == NULL) return -1; // Check if the board pointer is null
    if (width <= 0 || height <= 0) return -2; // Check if width and height are positive integers

    b->width = width; // Set the width of the board
    b->height = height; // Set the height of the board

    int num_nodes = width * height;
    int num_edges = 8 * num_nodes; // This is an assumption; verify if this is correct for your graph

    printf("width: %d, height: %d, num_nodes: %d\n", width, height, num_nodes);
    
    // Allocate memory for the graph on the heap
    struct Graph* g = (struct Graph*)malloc(sizeof(struct Graph));
    if (g == NULL) {
        return -3; // Memory allocation failed
    }

    // Initialize the graph
    //we are assuming no errors will happen during graph_init
    graph_init(g, width, height, num_edges);

    // Set the board's graph pointer
    b->graph = g; // Assuming the Board struct has a pointer to a Graph

    return 0;
}
