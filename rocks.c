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
int rocks_init(struct Rocks* r, int color) {
    //if statments to see if the rocks value is 0 or -1
    if (r == 0) return -1;
    // if the color is less then white and / or if the color is greater then purple return -2
    // the color values are in rock.h
    if (color < WHITE || color > PURPLE) return -2;

    //r points to a color
    r->color = color;

    return 0;
}
char get_rock_color(struct Rocks* r){
    char color_char = '-' ;
            
    if(r!=0){
        return rock_color(r->color);   
         
    }
    return color_char;
}

char rock_color(int color){

    char color_char = '-' ; 

    if(color == RED){
        color_char = 'x';
    }else if (color == BLACK)
    {
        color_char = 'o';
    }else{
        color_char = '-';
    } 

    return color_char;


}