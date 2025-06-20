#include "var\global.hpp"
#include "package\package.hpp"

Vertex *start_v = NULL;
Vertex *end_v = NULL;
vector<vector<Vertex*>> runningMap;

pair<int, int> currentPos = {0, 0};
pair<int, int> enemyPos = {0, 0};
vector<Dir> directions = {
    {-1, 0, "up"},
    {1, 0, "down"},
    {0, -1, "left"},
    {0, 1, "right"}};
enemyQueue enemyMovement;
letterQueue word;

bool playerWin = false;
bool enemyWin = false;

string currentUsername = "";