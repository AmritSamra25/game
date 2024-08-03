#ifndef DISPLAY_H
#define DISPLAY_H

#include "board.h"

/* 
 * Display the board on the console.
 * Parameters:
 *     b - a pointer to the board to display.
 *
 * Notes:
 *     The board should be initialized before calling this function.
 */
void display_board(const struct Board* b);

#endif // DISPLAY_H
