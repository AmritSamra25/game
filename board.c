#include <stdlib.h>
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
    struct Graph g; 
    int num_nodes;
    int num_edge;
    if (b == 0) return -1;
    if ((width<0) || (height<0)) return -2;

    b->width = width; //b points to the width from board.h
    b->height = height; //b points to the height from board.h
    num_nodes = width * height;
    num_edge = 8*num_nodes;

    // Two ways to create a graph:
    // struct Graph g;   // Creates on the stack, pass its address via & to graph_init
    // struct Graph* g = (struct Graph*)malloc(sizeof(struct Graph));  // Creates on the heap, pass g to graph_init

   graph_init(&g, num_nodes, num_edge);

    return 0;
}
