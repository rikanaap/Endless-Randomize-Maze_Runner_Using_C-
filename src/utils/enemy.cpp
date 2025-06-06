#include <iostream>
#include "global.hpp"
#include "map.hpp"
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

void moveEnemyEveryFiveSeconds(vector<vector<Vertex *>> &map, pair<int, int> &enemyPos)
{
    srand(time(0)); // Seed for random movement

    while (!gameFinished)
    {
        // Randomly choose a direction: 0 = up, 1 = down, 2 = left, 3 = right
        int direction = rand() % 4;

        switch (direction)
        {
        case 0:
            moveEnemyUp(map, enemyPos);
            break;
        case 1:
            moveEnemyDown(map, enemyPos);
            break;
        case 2:
            moveEnemyLeft(map, enemyPos);
            break;
        case 3:
            moveEnemyRight(map, enemyPos);
            break;
        }

        cout << "\nMove with \n[w: up, s: down, a: left, d: right] \n\nShoot with \n[i: up, k: down, j: left, l: right]\n\n[q: quit]";

        // Wait for 5 seconds
        this_thread::sleep_for(chrono::seconds(5));

        clearScreen();
        printMap(map);
    }
}

void runEnemy(vector<vector<Vertex *>> &map)
{
    thread enemyThread(moveEnemyEveryFiveSeconds, ref(map), ref(enemyPos));
    enemyThread.detach();
}