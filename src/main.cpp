#include "../include/maze.h"
#include <iostream>

int main(int argc, char* const argv[]) {
    int x, y;

    std::cout << "Please insert width: ";
    std::cin >> x;
    std::cout << "Please insert height: ";
    std::cin >> y;

    // generating maze
    maze nmaze(x, y);
    nmaze.write_maze();

    return 0;
}