#include <stdio.h>
#include <stdlib.h>

#include "board.h"
#include "display.h"
#include "graph.h"

//main 
int main(int argc, char **argv) {
    int width;
    int height;
    int num1;
    int num2;
    int xtmp1;
    int ytmp1;
    int xtmp2;
    int ytmp2;
    int found;

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
    
    
    for(int x = 0; x < width; x++){
        for(int y = 0; y < height; y++){

            //check to see if the edge already exists
            found = 0;
            for(int e = 0; e < b->graph->num_edge; e++){
                num1 = b->graph->edges[e]->node1->num;
                num2 =  b->graph->edges[e]->node2->num;
                xtmp1 = b->graph->edges[e]->node1->x;
                ytmp1 = b->graph->edges[e]->node1->y;
                xtmp2 = b->graph->edges[e]->node2->x;
                ytmp2 = b->graph->edges[e]->node2->y;
                printf ("num1, xtmp1, ytmp1: %d %d %d\n", num1, xtmp1, ytmp1);
                printf ("num1, xtmp1, ytmp1: %d %d %d\n", num1, xtmp1, ytmp1);

                if (((xtmp1==x) && (ytmp1==y) &&
                    ((xtmp2==x) && (ytmp2==y))) {
                        found=1;
                        break;
                }
                printf ("num2, xtmp, ytmp: %d %d %d\n", num2, xtmp, ytmp);

                //if(num1[][])
            }
            if(y!=0){
                add_edge(b->graph,x,y-1,x,y);
            }
            if(x!=0){
                add_edge(b->graph,x-1,y,x,y);
            }
            if(x!=width){
                add_edge(b->graph,x+1,y,x,y);
            }
            if(y!=height){
               add_edge(b->graph,x,y+1,x,y); 
            }

        }
    }

    printf ("Updated board sizes: %d %d\n", b->width, b->height);

    display_board(b);
}

/*
Returns 1 if an edge exists that connects nodes with X,Y locations (x1,y1) and (x2, y2)
Returns 0 otherwise.
*/
int edge_exists (struct Board* b, int x1, int y1, int x2, int y2) {
    int num1 = b->graph->edges[e]->node1->num;
    int num2 =  b->graph->edges[e]->node2->num;
    int xtmp1 = b->graph->edges[e]->node1->x;
    int ytmp1 = b->graph->edges[e]->node1->y;
    int xtmp2 = b->graph->edges[e]->node2->x;
    int ytmp2 = b->graph->edges[e]->node2->y;

    if ((xtmp1==xtmp2) && (ytmp1==ytmp2)) return 1;

    return 0;
}
