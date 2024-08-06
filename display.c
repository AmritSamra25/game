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
}
