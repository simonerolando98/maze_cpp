#ifndef MAZE_H
#define MAZE_H

#include <array>

const int MAX_DIR = 4;

class direction {
private:
    int bit_;
    int dx_;
    int dy_;

    direction* opposite_;

public:
    direction(int bit, int dx, int dy);
    direction() = default;

    int bit();
    int dx();
    int dy();
    direction opposite();

    void bit(int bit);
    void dx(int dx);
    void dy(int dy);
    void opposite(direction& opposite);
};

class maze {
private:
    const int x;
    const int y;
    int** maze_data;
    std::array<direction, MAX_DIR> directions;

private:
    bool between(int v, int upper);
    void generate_maze(int cx, int cy);

public:
    maze(int x, int y);
    ~maze();
    void write_maze();
};

#endif