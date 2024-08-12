#include <stdio.h>
#include <stdlib.h>

#include "board.h"
#include "display.h"
#include "graph.h"

//main 
int main(int argc, char **argv) {
    int width;
    int height;
    struct Board *b = (struct Board *)malloc(sizeof(struct Board));

    printf ("Initial (junk) board sizes: %d %d\n", b->width, b->height);

    printf("Enter new board width: ");
    scanf("%d" , &width);
    printf("Enter new board height: ");
    scanf ("%d" , &height);
    
    board_init(b, width, height);
    add_edge(b->graph,0,0,0,1);
    add_edge(b->graph,0,1,0,2);
    add_edge(b->graph,0,2,0,3);
    add_edge(b->graph,0,0,1,0);
    
    
    

    printf ("Updated board sizes: %d %d\n", b->width, b->height);

    display_board(b);
}
