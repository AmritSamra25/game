#ifndef BOARD
#define BOARD
/*
 * Insert comments here about what the Board structure is
 * used for, and any other general notes about usage or intent
 */
struct Board {
    int width;     // The width of the board (number of nodes)
    int height;    // The height of the board (number of nodes)
};
/* 
 * board_init is used to  (insert details here)
 * Parameters:
 *    b - a pointer to the board struct to initialize.
 *    width - the new board width.
 *    height - the new board height:
 * Returns:
 *    0 if everything is OK
 *   -1 if b==0
 *   -2 if width or height is negative.
 */
int board_init(struct Board* b, int width, int height);

#endif
