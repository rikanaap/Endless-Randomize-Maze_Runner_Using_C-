#ifndef MAP_HPP
#define MAP_HPP

#include "package.hpp"
#include "utils.hpp"

pair<int, int> parseCord(const string& str);
vector<vector<char>> createMaze(const string& key);

void printMaze(const vector<vector<char>>& maze);

#endif