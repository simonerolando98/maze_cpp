#include "../include/maze.h"

direction::direction(int bit, int dx, int dy)
    : bit_(bit), dx_(dx), dy_(dy), opposite_(nullptr) {}

int direction::bit() { return bit_; }
int direction::dx() { return dx_; }
int direction::dy() { return dy_; }
direction direction::opposite() { return (*opposite_); }

void direction::bit(int bit) { this->bit_ = bit; }
void direction::dx(int dx) { this->dx_ = dx; }
void direction::dy(int dy) { this->dy_ = dy; }
void direction::opposite(direction& opposite) { this->opposite_ = &opposite; }
