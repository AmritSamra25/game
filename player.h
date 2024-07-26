#include "rocks.h"


struct player
{
    char* name;
    struct rocks* rock;
};


void player_init(struct player* p,char* pname);