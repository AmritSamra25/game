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
    
    /*
    from my understanding after trying to figure it out is that we are adding
    edges but they are not being shown to us.... it gets through the add_edges and prints out 
    all the printf statments i put and gets throguh them but it does not show that they have been
    added, so it works but does not show anything.... unless i am thinking about it wrongly..
    */

    board_init(b, width, height);
    add_edge(b->graph,0,0,0,1);
    printf(".........it made it past add_edge");
    add_edge(b->graph,0,1,0,2);
    printf(".......made it past add_edge 2");
    add_edge(b->graph,0,2,0,3);
    add_edge(b->graph,0,0,1,0);
    
    printf("it added all the edges.................d.d......");
    
    

    printf ("Updated board sizes: %d %d\n", b->width, b->height);

    display_board(b);
}
