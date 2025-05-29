#include "player.hpp"
#include "map.hpp"
#include "utils.hpp"

void movePlayerUp(vector<vector<Vertex *>> &map, pair<int, int> &currentPos)
{
    Vertex *v = map[currentPos.first][currentPos.second];
    if (v->up && v->weightUp > 0)
        currentPos.first -= 1;
}

void movePlayerDown(vector<vector<Vertex *>> &map, pair<int, int> &currentPos)
{
    Vertex *v = map[currentPos.first][currentPos.second];
    if (v->down && v->weightDown > 0)
        currentPos.first += 1;
}

void movePlayerLeft(vector<vector<Vertex *>> &map, pair<int, int> &currentPos)
{
    Vertex *v = map[currentPos.first][currentPos.second];
    if (v->left && v->weightLeft > 0)
        currentPos.second -= 1;
}

void movePlayerRight(vector<vector<Vertex *>> &map, pair<int, int> &currentPos)
{
    Vertex *v = map[currentPos.first][currentPos.second];
    if (v->right && v->weightRight > 0)
        currentPos.second += 1;
}

void controlPlayer(vector<vector<Vertex *>> &map, char input)
{
    switch (input)
    {
    case 'i':
        movePlayerUp(map, currentPos);
        break;
    case 'k':
        movePlayerDown(map, currentPos);
        break;
    case 'j':
        movePlayerLeft(map, currentPos);
        break;
    case 'l':
        movePlayerRight(map, currentPos);
        break;
    }
    clearScreen();
    printMap(map);
}