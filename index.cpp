#include "map.hpp"

int main() {
    string key = "11010_00010_11000|13_15|22";
    auto maze = createMaze(key);
    printMaze(maze);
    return 0;
}