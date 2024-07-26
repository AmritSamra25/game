#include <stdlib.h>
#include "rocks.h"


/* 
 * Initialize the pieces.
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
int rocks_init(struct rocks* r, int color) {
    if (r == 0) return -1;
    if (color < WHITE || color > PURPLE) return -2;

    r->color = color;

    return 0;
}
