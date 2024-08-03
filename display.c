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

    // Display board dimensions
    printf("Board Dimensions: %d x %d\n", width, height);

    // Display graph (nodes and edges) - this part will depend on your graph structure
    // For simplicity, we assume a grid-like representation for demonstration purposes

    printf("Board Layout:\n");
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // Display each cell; this example assumes a simple representation
            printf("[%d,%d] ", x, y);
        }
        printf("\n");
    }

    // Here you would include code to display graph connections if needed
    // For example, if nodes have labels or specific connections to show

    // Display edges (if applicable)
    // This is a placeholder; you need to adjust based on your graph's actual representation
    printf("Graph Edges:\n");
    for (int i = 0; i < g->num_nodes; ++i) {
        // Display edges for each node
        // This will depend on how your graph stores edges
        printf("Node %d: ", i);
        // Iterate through edges connected to node i
        // Example:
        // for (each edge connected to node i) {
        //     printf(" -> %d", connected_node);
        // }
        printf("\n");
    }
}
