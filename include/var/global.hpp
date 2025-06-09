// globals.hpp
#pragma once

#include <vector>
#include "var\struct.hpp"
#include "package\package.hpp"

extern Vertex* start_v;
extern Vertex* end_v;
extern vector<vector<Vertex*>> current_map;
extern pair<int, int> currentPos;
extern pair<int, int> enemyPos;
extern int playerPoint;
extern bool playerWin;
extern bool enemyWin;
extern vector<Dir> directions;
extern enemyQueue enemyMovement;
extern letterQueue word;
