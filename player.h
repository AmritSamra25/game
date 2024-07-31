#ifndef PLAYER
#define PLAYER

#include "rocks.h"

struct Player


{
    char* name; // the charcter name (gets name of charcter)
    struct rocks* rock; // makes the rock 
};

//void player init 
void player_init(struct Player* p,char* pname);
#endif