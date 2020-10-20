#include "../include/maze.h"
#include <algorithm>
#include <fstream>

// fake direction for initial binding
direction dummy;

void create_directions(std::array<direction, MAX_DIR>& directions) {
    // creating incomplete directions
    directions[0] = direction(1, 0, -1); // NORTH
    directions[1] = direction(2, 0, 1); // SOUTH
    directions[2] = direction(4, 1, 0); // EAST
    directions[3] = direction(8, -1, 0); // WEST

    // setting opposites
    directions[0].opposite(directions[1]);
    directions[1].opposite(directions[0]);
    directions[2].opposite(directions[3]);
    directions[3].opposite(directions[2]);
}

/**
 * Maze class definition
 */
maze::maze(int x, int y) : x(x), y(y), maze_data(new int*[x]) {

    // maze memory allocation - pass 2
    for (int i = 0; i < x; i++)
        maze_data[i] = new int[y];

    create_directions(directions);
    generate_maze(0, 0);
}

maze::~maze() {
    for (int i = 0; i < x; i++)
        delete[] maze_data[i];
    delete maze_data;
}

void maze::generate_maze(int cx, int cy) {
    // randomizing directions
    std::random_shuffle(directions.begin(), directions.end());

    for (direction d : directions) {
        int nx = cx + d.dx();
        int ny = cy + d.dy();

        if (between(nx, x) && between(ny, y) && maze_data[nx][ny] == 0) {
            maze_data[cx][cy] |= d.bit();
            maze_data[nx][ny] |= d.opposite().bit();
            generate_maze(nx, ny);
        }
    }
}

void maze::write_maze() {
    std::fstream output("maze.txt", std::ios::out);

    for (int i = 0; i < y; i++) {
        // drawing northern edge
        for (int j = 0; j < x; j++)
            output << ((maze_data[j][i] & 1) == 0 ? "+---" : "+   ");
        output << "+\n";
        // drawing western edge
        for (int j = 0; j < x; j++)
            output << ((maze_data[j][i] & 8) == 0 ? "|   " : "    ");
        output << "|\n";
    }
    // drawing southern edge
    for (int j = 0; j < x; j++)
        output << "+---";
    output << "+\n";

    output.close();
}

bool maze::between(int v, int upper) { return (v >= 0) && (v < upper); }
