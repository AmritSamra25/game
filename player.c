#include "player.h"
#include <string.h>

//void player init 
void player_init(struct player* p,char* pname) {

    strcpy(p->name, pname); // copies the pointer, NOT the name
    p->rock = 0;      // copies the pointer, NOT the rock

}

//void player to add rock
void player_add_rock(struct player* p, struct rocks* r){

    
    p->rock = r; //p points to rock

}