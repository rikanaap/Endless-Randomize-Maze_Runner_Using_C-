#ifndef MAP_HPP
#define MAP_HPP
#include "package\package.hpp"
#include "var\struct.hpp"
#include "var\global.hpp"

//?FUNCTION
void printMap();
void printAllVertexConnections();
vector<vector<Vertex *>> generateMap(int rows, int cols, int noise);

#endif