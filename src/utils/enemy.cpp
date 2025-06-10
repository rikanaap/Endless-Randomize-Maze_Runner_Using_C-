#include <iostream>
#include "var\global.hpp"
#include "main\map.hpp"
#include "main\move.hpp"
#include "main\utils.hpp"

using namespace std;

//? Move Function
bool enemyIsInPlayer(){
    return (enemyPos.first == currentPos.first) && (enemyPos.second == currentPos.second);
}

void moveEnemyUp( pair<int, int> &enemyPos)
{
    Vertex *v = runningMap[enemyPos.first][enemyPos.second];
    if (v->up && v->weightUp > 0)
    {
        enemyPos.first -= 1;
    }
   enemyWin = enemyIsInPlayer();
}
void moveEnemyDown( pair<int, int> &enemyPos)
{
    Vertex *v = runningMap[enemyPos.first][enemyPos.second];
    if (v->down && v->weightDown > 0)
    {
        enemyPos.first += 1;
    }
    enemyWin = enemyIsInPlayer();
}
void moveEnemyLeft( pair<int, int> &enemyPos)
{
    Vertex *v = runningMap[enemyPos.first][enemyPos.second];
    if (v->left && v->weightLeft > 0)
    {
        enemyPos.second -= 1;
    }
    enemyWin = enemyIsInPlayer();
}
void moveEnemyRight( pair<int, int> &enemyPos)
{
    Vertex *v = runningMap[enemyPos.first][enemyPos.second];
    if (v->right && v->weightRight > 0)
    {
        enemyPos.second += 1;
    }
    enemyWin = enemyIsInPlayer();
}

unordered_map<Vertex *, pair<Vertex *, char>> parent;

bool isConnected(Vertex *from, Vertex *to, const string &direction)
{
    if (direction == "up")
        return from->up == to && from->weightUp != -1;
    if (direction == "down")
        return from->down == to && from->weightDown != -1;
    if (direction == "left")
        return from->left == to && from->weightLeft != -1;
    if (direction == "right")
        return from->right == to && from->weightRight != -1;
    return false;
}

bool bfs(Vertex *start, Vertex *target, vector<vector<bool>> &visited)
{
    int rows = visited.size();
    int cols = visited[0].size();

    queue<Vertex *> q;
    q.push(start);
    visited[start->x][start->y] = true;
    parent.clear();

    while (!q.empty())
    {
        Vertex *current = q.front();
        q.pop();

        if (current == target)
        return true;

        for (const Dir &dir : directions)
        {
            int nx = current->x + dir.dx;
            int ny = current->y + dir.dy;

            if (nx < 0 || ny < 0 || nx >= rows || ny >= cols)
                continue;
            Vertex *neighbor = runningMap[nx][ny];

            if (!neighbor || visited[nx][ny])
                continue;
            if (!isConnected(current, neighbor, dir.name))
                continue;

            visited[nx][ny] = true;
            char moveChar = ' ';
            if (dir.name == "up")
                moveChar = 'U';
            else if (dir.name == "down")
                moveChar = 'D';
            else if (dir.name == "left")
                moveChar = 'L';
            else if (dir.name == "right")
                moveChar = 'R';

            parent[neighbor] = {current, moveChar};
            q.push(neighbor);
        }
    }

    return false;
}

pair<int, int> randomizePosition(int rows, int cols)
{
    int sx = randomInt(0, rows - 1);
    int sy = randomInt(0, cols - 1);
    return {sx, sy };
}


void searchUser()
{
    Vertex *enemy = (enemyPos.first >= 0) ? runningMap[enemyPos.first][enemyPos.second] : NULL;
    if (enemy == NULL) return;
    Vertex *player = runningMap[currentPos.first][currentPos.second];

    int rows = runningMap.size();
    int cols = runningMap[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    enemyMovement.top = 0;

    while (true)
    {
        if (bfs(enemy, player, visited))
        {
            vector<char> path;
            for (Vertex *v = player; v != enemy; v = parent[v].first)
            {
                path.push_back(parent[v].second);
            }
            reverse(path.begin(), path.end());
            for (char move : path)
                insertMove(move);
            cout << endl;
            break;
        }
        else
        {
            enemyPos = randomizePosition(rows, cols);
            enemy =  runningMap[enemyPos.first][enemyPos.second];
        }
    }
}

void moveEnemy( int loopFor = 1)
{
    for (int i = 0; i < loopFor; ++i)
    {
        if (isMoveEmpty())
        {
            searchUser();
        }

        char direction = firstMove();
        switch (direction)
        {
        case 'U':
            moveEnemyUp(enemyPos);
            break;
        case 'D':
            moveEnemyDown(enemyPos);
            break;
        case 'L':
            moveEnemyLeft(enemyPos);
            break;
        case 'R':
            moveEnemyRight(enemyPos);
            break;
        default:
            return;
        }
        removeMove();
    }
}