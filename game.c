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
    

    board_init(b, width, height);
    display_board(b);

    printf ("========= Adding edges ============= width=%d, height=%d\n", width, height);
    
    for(int x = 0; x < width; x++){
        for(int y = 0; y < height; y++){
            // Add an edge from the current node to the one below
            if(y!=0){
              add_edge(b->graph, x, y, x, y-1);
            }

            // Add an edge from the curreent node to the one to the left
            if(x!=0){
              add_edge(b->graph, x, y, x-1, y);
            }

            // Add an edge from the current node to the one to the right
            if(x<(width-1)){
              add_edge(b->graph, x, y, x+1, y);
            }

            // Add an edge from the current node to the one above
            if(y<(height-1)){
              add_edge(b->graph, x, y, x, y+1);
            }
        }
    }

    printf ("Updated board sizes: %d %d\n", b->width, b->height);

    display_board(b);
}

