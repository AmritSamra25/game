#include <stdlib.h>
#include "board.h"

void board_init(struct Board* b, int width, int height) {
    b->width = width;
    b->height = height;
}