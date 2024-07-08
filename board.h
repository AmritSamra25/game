#ifndef BOARD
#define BOARD
struct Board {
    int width;
    int height;
};
void board_init(struct Board* b, int width, int height);

#endif