#include <stdio.h>
#include <stdlib.h>

#include "board.h"
#include "display.h"
#include "graph.h"


int PLAYER_1 = RED; //player x
int PLAYER_2 = BLACK; // player 0
void move(struct Board* b,int start_x, int start_y, int end_x, int end_y){

  struct Node* n = b->graph->nodes[start_x][start_y];

  struct Node* end_n = b->graph->nodes[end_x][end_y];

  end_n -> rock = n->rock;
  n -> rock = 0;
  

}


// Example function to determine if the move is legal
// This is a placeholder; implement the actual game-specific logic
int is_legal_move(int start_x, int start_y, int end_x, int end_y, int player_turn) {
    // Assuming pieces can only move one step in any direction (e.g., like a king in chess)
    int dx = abs(end_x - start_x);
    int dy = abs(end_y - start_y);
    
    // Check if the move is exactly one space in any direction
    return (dx <= 1 && dy <= 1 && (dx != 0 || dy != 0));
}


int check_move(struct Board* b, int x, int y, int xx, int yy, int player_turn){
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

  //this part checks to see if their is a piece thier or not before moving it:
  
  /*------------------------------------------------------ FROM GREG
    There are a couple of problems with the expression:
       if (!b->graph[x][y].has_piece)
       
    (1) b->graph points to a graph data structure, which is
        defined in graph.h.  graph is not an array, so you can't use the [][] to access its members.
        
    (2) The graph data structure doesn't contain a has_piece element, so ".has_piece" won't work.

    If you want to determine whether a graph node has a piece, you'll need to get that information
    from the node itself.

    To access a node by x & y coordinate in the graph, you would use an expression like:
       b->graph->nodes[x]y]

    If a node's "rock" pointer is equal to zero, it doesn't contain a rock (piece).

    So, to check to see if a node contains a piece (rock), you could use code like this:
       Node* node_ptr = b->graph->nodes[x][y];
       if (node_ptr->rock != 0) ...

    Or, alternatively,
       Node* node_ptr = b->graph->nodes[x][y];
       if (!node_ptr->rock) ...

    If you want to do everything on one line, you can do this:
       if (b->graph->nodes[x][y]->rock != 0)
           OR
       if (!b->graph->nodes[x][y]->rock)

    I changed your first "if" statement below.  You can change the second.
    
    ------------------------------------------------------- FROM GREG */

  //  if (!b->graph[x][y].has_piece) {
  printf("did we even get this afar zzzzzzzzzz");
  if (!b->graph->nodes[x][y]->rock) { // No rock at the start position
    printf("we got heheheehehheheheheheehehehehe");
    return -3;
  } else {
    if(b->graph->nodes[x][y]->rock->color != player_turn){  // Current rock is the player's rock
      printf("did we get here????????????? ");

       return -3;  // There is a rock at the start position, but it's not the player's turn
      }
    }

  // Check if there is a piece at the destination position
  if (b->graph->nodes[xx][yy]->rock) {
      return -4;  // Destination already occupied
  }

  //this part checks to see if the move is legal and can be made (this makes sure the pieces can not
  //jump from more then 1 space)
  // Check if the move is legal (e.g., pieces can only move 1 space at a time)
// Assuming 'legal_move' is a function or condition that determines the legality of the move.
  if (!is_legal_move(x, y, xx, yy,player_turn)) {
    return -5;  // Illegal move according to the game rules
  }




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

    
    int player_turn = PLAYER_1;

    while(!game_over){
      int x, y;
      int xx, yy;

      printf(" %c, pick starting x y: ",rock_color(player_turn));
      scanf("%d %d" ,&x, &y);


      printf("Enter new location for the rock x y: ");
      scanf("%d %d" ,&xx, &yy);




      printf("_______________%d %d %d %d",x,y, xx, yy);
      int is_move_legal = check_move(b, x,y,xx,yy,player_turn);
      printf("is_move_legal: %d\n", is_move_legal);
      if(is_move_legal == -1) printf("your nums are out of range");
      else if(is_move_legal == -2) printf("your x y and new x y are the same");
      else if(is_move_legal == -3) printf("thier is no piece at the starting point");
      else if(is_move_legal == -4)printf("thier is a piece already thier");
      else if(is_move_legal == -5)printf("the move is not legal");
      else {
        
        move(b,x,y,xx,yy);
        printf("move happened");
        user_display_board(b);
        

      }


      if(player_turn == PLAYER_1){
        player_turn = PLAYER_2;
      } else{
        player_turn = PLAYER_1;
      }

      //game_over = 1;
    }
    


}

