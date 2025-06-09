#include <iostream>
#include "global.hpp"
#include "map.hpp"
#include "move.hpp"
#include "utils.hpp"

using namespace std;

//? Move Function
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

unordered_map<Vertex*, pair<Vertex*, char>> parent;

bool isConnected(Vertex* from, Vertex* to, const string& direction) {
    if (direction == "up") return from->up == to && from->weightUp != -1;
    if (direction == "down") return from->down == to && from->weightDown != -1;
    if (direction == "left") return from->left == to && from->weightLeft != -1;
    if (direction == "right") return from->right == to && from->weightRight != -1;
    return false;
}

bool bfs(Vertex* start, Vertex* target, vector<vector<bool>>& visited, vector<vector<Vertex *>> &map) {
    int rows = visited.size();
    int cols = visited[0].size();

    queue<Vertex*> q;
    q.push(start);
    visited[start->x][start->y] = true;
    parent.clear();

    while (!q.empty()) {
        Vertex* current = q.front();
        q.pop();

        if (current == target) return true;

        for (const Dir& dir : directions) {
            int nx = current->x + dir.dx;
            int ny = current->y + dir.dy;

            if (nx < 0 || ny < 0 || nx >= rows || ny >= cols) continue;
            Vertex* neighbor = map[nx][ny];

            if (!neighbor || visited[nx][ny]) continue;
            if (!isConnected(current, neighbor, dir.name)) continue;

            visited[nx][ny] = true;
            char moveChar = ' ';
            if (dir.name == "up") moveChar = 'U';
            else if (dir.name == "down") moveChar = 'D';
            else if (dir.name == "left") moveChar = 'L';
            else if (dir.name == "right") moveChar = 'R';

            parent[neighbor] = {current, moveChar};
            q.push(neighbor);
        }
    }

    return false;
}

void searchUser(vector<vector<Vertex *>> &map){
    Vertex* enemy = map[enemyPos.first][enemyPos.second];
    Vertex* player = map[currentPos.first][currentPos.second];

    int rows = map.size();
    int cols = map[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    // Clear previous moves
    enemyMovement.top = 0;

    if (bfs(enemy, player, visited, map)) {
        cout << "Shortest path found using BFS!" << endl;
        vector<char> path;
        for (Vertex* v = player; v != enemy; v = parent[v].first) {
            path.push_back(parent[v].second);
        }
        reverse(path.begin(), path.end());
        for (char move : path) insertMove(move);

        cout << "Moves: ";
        for (int i = 0; i < enemyMovement.top; ++i)
            cout << enemyMovement.isi[i] << ' ';
        cout << endl;
    } else {
        cout << "No path found!" << endl;
    }
}


void moveEnemy(vector<vector<Vertex *>> &map, int loopFor = 1)
{
    for (int i = 0; i < loopFor; ++i)
    {
        if (isMoveEmpty()) { searchUser(map); }

        char direction = firstMove();
        cout << "Move: " << direction;
        switch (direction)
        {
        case 'U':
            moveEnemyUp(map, enemyPos);
            break;
            case 'D':
            moveEnemyDown(map, enemyPos);
            break;
        case 'L':
            moveEnemyLeft(map, enemyPos);
            break;
        case 'R':
            moveEnemyRight(map, enemyPos);
            break;
        default:
            return;
        }
        removeMove();
    }
}