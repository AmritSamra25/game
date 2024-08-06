#include <stdio.h>
#include <stdlib.h>

#include "board.h"
#include "display.h"

//main 
int main(int argc, char **argv) {
    struct Board b;
    struct Board *b2 = (struct Board *)malloc(sizeof(struct Board));

    printf ("Initial board sizes: %d %d %d %d\n", b.width, b.height, b2->width,b2->height);

    printf("Enter new board width: ");
    scanf("%d" , &b.width);
    printf("Enter new board height: ");
    scanf ("%d" , &b.height);

    board_init(b2, 4, 3);

    display_board(b2);

    printf("board sizes: %d, %d, %d, %d\n", b.width, b.height, b2->width, b2-> height);
}