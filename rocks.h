#ifndef ROCKS
#define ROCKS
/*
 * 
 * 
 */
struct rocks {
    int width;     // The width of the pieces (number of nodes)
    int height;    // The height of the pieces (number of nodes)
};
/* 
 * rocks_init is used to  (insert details here)
 * Parameters:
 *    b - a pointer to the pieces struct to initialize.
 *    width - the new pieces width.
 *    height - the new pieces height:
 * Returns:
 *    0 if everything is OK
 *   -1 if b==0
 *   -2 if width or height is negative.
 */
int rocks_init(struct rocks* b, int width, int height);

#endif
