#include <stdio.h>
#include <stdlib.h>

#include "board.h"

int main(int argc, char **argv) {
    struct Board b;
    struct Board *b2 = (struct Board *)malloc(sizeof(struct Board));

    printf ("Initial board sizes: %d %d %d %d\n", b.width, b.height, b2->width,b2->height);

    board_init(&b,0,0);

    printf("Enter new board width: ");
    scanf("%d" , &b.width);
    printf("Enter new board height: ");
    scanf ("%d" , &b.height);

    board_init(b2, 30, 40);

    printf("board sizes: %d, %d, %d, %d\n", b.width, b.height, b2->width, b2-> height);
}