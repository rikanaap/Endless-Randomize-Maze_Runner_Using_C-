#include "global.hpp"

Vertex *start_v = NULL;
Vertex *end_v = NULL;
pair<int, int> currentPos = {0, 0};
pair<int, int> enemyPos = {0, 0};
vector<Dir> directions = {
    {-1, 0, "up"},
    {1, 0, "down"},
    {0, -1, "left"},
    {0, 1, "right"}};
Queue enemyMovement;

bool playerWin = false;
bool enemyWin = false;