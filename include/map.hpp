#ifndef MAP_HPP
#define MAP_HPP
#include "package.hpp"
#include "struct.hpp"
#include "global.hpp"

//?FUNCTION
void printMap(const vector<vector<Vertex *>> &map);
void printAllVertexConnections(const vector<vector<Vertex *>> &map);
vector<vector<Vertex *>> generateMap(int rows, int cols, int noise);

#endif