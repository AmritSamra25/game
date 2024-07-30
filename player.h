#ifndef PLAYER
#define PLAYER

#include "rocks.h"


struct player
{
    char* name;
    struct rocks* rock; // makes the rock 
};


void player_init(struct player* p,char* pname);
#endif