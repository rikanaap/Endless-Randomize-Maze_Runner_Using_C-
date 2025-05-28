#ifndef MAP_HPP
#define MAP_HPP
#include "package.hpp"
#include "struct.hpp"

void menuUtama();

vector<Dir> directions = {
    {-1, 0, "up"},
    {1, 0, "down"},
    {0, -1, "left"},
    {0, 1, "right"}};

pair<int, int> currentPos;

//?FUNCTION
vector<vector<Vertex *>> initializeVertexMap(int rows, int cols);
void addNoise(vector<vector<Vertex *>> &map, int rows, int cols, int noiseCount);
void createPath(Vertex *current, Vertex *end, vector<vector<Vertex *>> &map, int rows, int cols);
void markConnected(Vertex *start);
void connectUnreachableVertices(vector<vector<Vertex *>> &map, int rows, int cols);
void updateWeightsByCoordinates(vector<vector<Vertex *>> &map, int rows, int cols);
void printMap(const vector<vector<Vertex *>> &map, pair<int, int> currentPos, Vertex *start, Vertex *end);
void printAllVertexConnections(const vector<vector<Vertex *>> &map);
pair<Vertex *, Vertex *> getRandomStartAndEnd(const vector<vector<Vertex *>> &map, int rows, int cols);

#endif