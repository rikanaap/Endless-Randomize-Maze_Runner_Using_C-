#include <iostream>
#include "global.hpp"
#include "map.hpp"
#include "move.hpp"
#include "utils.hpp"

using namespace std;

void moveEnemyUp(vector<vector<Vertex *>> &map, pair<int, int> &enemyPos)
{
    Vertex *v = map[enemyPos.first][enemyPos.second];
    if (v->up && v->weightUp > 0)
    {
        enemyPos.first -= 1;
    }
}

void moveEnemyDown(vector<vector<Vertex *>> &map, pair<int, int> &enemyPos)
{
    Vertex *v = map[enemyPos.first][enemyPos.second];
    if (v->down && v->weightDown > 0)
    {
        enemyPos.first += 1;
    }
}

void moveEnemyLeft(vector<vector<Vertex *>> &map, pair<int, int> &enemyPos)
{
    Vertex *v = map[enemyPos.first][enemyPos.second];
    if (v->left && v->weightLeft > 0)
    {
        enemyPos.second -= 1;
    }
}

void moveEnemyRight(vector<vector<Vertex *>> &map, pair<int, int> &enemyPos)
{
    Vertex *v = map[enemyPos.first][enemyPos.second];
    if (v->right && v->weightRight > 0)
    {
        enemyPos.second += 1;
    }
}

void moveEnemy(vector<vector<Vertex *>> &map)
{
    // srand(time(0));
    // int direction = rand() % 4;
    
    char direction = takeFirst();

    switch (direction)
    {
    case 'u':
        moveEnemyUp(map, enemyPos);
        remove();
        break;
    case 'd':
        moveEnemyDown(map, enemyPos);
        remove();
        break;
    case 'l':
        moveEnemyLeft(map, enemyPos);
        remove();
        break;
    case 'r':
        moveEnemyRight(map, enemyPos);
        remove();
        break;
    }
}