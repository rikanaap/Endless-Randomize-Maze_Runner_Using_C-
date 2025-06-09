// globals.hpp
#pragma once

#include <vector>
#include "struct.hpp"
#include "package.hpp"

extern Vertex* start_v;
extern Vertex* end_v;
extern vector<vector<Vertex*>> current_map;
extern pair<int, int> currentPos;
extern pair<int, int> enemyPos;
extern int playerPoint;
extern bool gameFinished;
extern vector<Dir> directions;
extern Queue enemyMovement;

