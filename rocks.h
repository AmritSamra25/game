#ifndef ROCKS
#define ROCKS

#define WHITE 1
#define BLACK 2
#define GRAY 3
#define RED 4
#define PURPLE 5
/*
 * 
 * 
 */


struct Rocks

{
    int color;   
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
// rock init 
int rocks_init(struct Rocks* b, int color);

char get_rock_color(struct Rocks* r);

#endif
