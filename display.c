#include <stdio.h>
#include "display.h"
#include "board.h"
#include "graph.h"

/* 
 * Display the board on the console.
 * Parameters:
 *     b - a pointer to the board to display.
 *
 * Notes:
 *     The board should be initialized before calling this function.
 */
void display_board(const struct Board* b) {
    if (b == NULL || b->graph == NULL) {
        printf("Error: Board or graph not initialized.\n");
        return;
    }

    int width = b->width;
    int height = b->height;
    struct Graph* g = b->graph;

    printf ("------------------------");
    // Display board dimensions
    printf("Board Dimensions: %d x %d\n", width, height);

    // Display graph (nodes and edges) - this part will depend on your graph structure
    // For simplicity, we assume a grid-like representation for demonstration purposes

    printf("Board Layout:\n");
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            // Display each cell; this example assumes a simple representation
            printf("[%d,%d] ", x, y);
        }
        printf("\n");
    }

     printf("board nodes:\n");
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            printf("[%d] ", b->graph->nodes[x][y]->num);
        }
        printf("\n");
    }

    int num_edges = b->graph->num_edge;
    printf("edges connect too: num_edges=%d\n", num_edges);

    printf ("graph: 0x%.8X\n", b->graph);
    for (int x = 0; x < num_edges; ++x) {
       printf ("-------------\n");
       printf ("edge: 0x%.8X\n", b->graph->edges[x]);
       printf ("node1: 0x%.8X\n", b->graph->edges[x]->node1);
       printf ("node2: 0x%.8X\n", b->graph->edges[x]->node2);
       printf ("num1: %d\n", b->graph->edges[x]->node1->num);
       printf ("num2: %d\n", b->graph->edges[x]->node2->num);
    }
}
