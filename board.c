#include <stdlib.h>
#include "board.h"


/* 
 * Initialize the board.
 * Parameters:
 *     b - a pointer to the board to initialize.
 *     width - the new board width (number of nodes)
 *     height - the new board height (number of nodes)
 *
 * Returns:
 *     0 if the initialization went OK
 *    -1 if b is 0.
 *    -2 if width or height is <= 0.
 *
 * Notes:
 *     If b is uninitialized, the results are undefined.
 *     width and height must be positive integers.
 */
int board_init(struct Board* b, int width, int height) {
    if (b == 0) return -1;
    if ((width<0) || (height<0)) return -2;

    b->width = width;
    b->height = height;

    return 0;
}
