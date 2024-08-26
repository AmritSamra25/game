#include <stdio.h>
#include <stdlib.h>

#include "board.h"
#include "display.h"
#include "graph.h"

int check_move(struct Board* b, int x, int y, int xx, int yy){
  if (x > b->width) return -1;
  if (y > b->height) return -1;
  if (x < 0) return -1;
  if (y < 0) return -1;

  // Another (shorter) way to do this:
  // if ((x > b->width) || (y > b->height) ...) return -1;

  if (xx > b->width) return -1;
  if (yy > b->height) return -1;
  if (xx < 0) return -1;
  if (yy < 0) return -1;

  if ((x == xx) && (y == yy)) return -2;


  return 0;
}
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
    
    struct Rocks* r;
    struct Node* n;
    for(int x = 0; x < width; x++){
      r = (struct Rocks *)malloc(sizeof(struct Rocks));
      rocks_init(r,RED);
      n = b->graph->nodes[x][0];
      n->rock = r;

      r = (struct Rocks *)malloc(sizeof(struct Rocks));
      rocks_init(r,BLACK);
      n = b->graph->nodes[x][height-1];
      n->rock = r;

    }
    printf ("Updated board sizes: %d %d\n", b->width, b->height);

    user_display_board(b);

    

    int game_over = 0;

    while(!game_over){
      int x, y;
      int xx, yy;

      printf("player 1 pick starting x y: ");
      scanf("%d %d" ,&x, &y);


      printf("Enter new location for the rock x y: ");
      scanf("%d %d" ,&xx, &yy);



      printf("_______________%d %d %d %d",x,y, xx, yy);
      if(check_move(b, x,y,xx,yy) == -1) printf("your nums are out of range");
      if(check_move(b, x,y,xx,yy) == -2) printf("your x y and new x y are the same");
      else printf("everything is good");


      game_over = 1;
    }
    


}

