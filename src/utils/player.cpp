#include "player.hpp"
#include "map.hpp"
#include "utils.hpp"
#include "env.hpp"
#include "global.hpp"

int playerPoint = 0;

void movePlayerUp(vector<vector<Vertex *>> &map, pair<int, int> &currentPos)
{
    Vertex *v = map[currentPos.first][currentPos.second];
    if (v->up && v->weightUp > 0)
    {
        if (v->up->endVertex)
            gameFinished = true;
        currentPos.first -= 1;
    }
}

void movePlayerDown(vector<vector<Vertex *>> &map, pair<int, int> &currentPos)
{
    Vertex *v = map[currentPos.first][currentPos.second];
    if (v->down && v->weightDown > 0)
    {
        if (v->down->endVertex)
            gameFinished = true;
        currentPos.first += 1;
    }
}

void movePlayerLeft(vector<vector<Vertex *>> &map, pair<int, int> &currentPos)
{
    Vertex *v = map[currentPos.first][currentPos.second];
    if (v->left && v->weightLeft > 0)
    {
        if (v->left->endVertex)
            gameFinished = true;
        currentPos.second -= 1;
    }
}

void movePlayerRight(vector<vector<Vertex *>> &map, pair<int, int> &currentPos)
{
    Vertex *v = map[currentPos.first][currentPos.second];
    if (v->right && v->weightRight > 0)
    {
        if (v->right->endVertex)
            gameFinished = true;
        currentPos.second += 1;
    }
}

void shootPlayerUp(vector<vector<Vertex *>> &map, pair<int, int> position, bool first = true)
{
    Vertex *v = map[position.first][position.second];
    if (!first) v->shoot = true;
    printMap(map);
    clearScreen();
    v->shoot = false;
    if (v->up && v->weightUp > 0)
    {
        shootPlayerUp(map, {v->up->x, v->up->y}, false);
    }
}

void shootPlayerDown(vector<vector<Vertex *>> &map, pair<int, int> &position, bool first = true)
{
    Vertex *v = map[position.first][position.second];
    if (!first) v->shoot = true;
    printMap(map);
    clearScreen();
    v->shoot = false;
    if (v->up && v->weightDown > 0)
    {
        shootPlayerUp(map, {v->up->x, v->up->y}, false);
    }
}

void shootPlayerLeft(vector<vector<Vertex *>> &map, pair<int, int> &position, bool first = true)
{
    Vertex *v = map[position.first][position.second];
    if (!first) v->shoot = true;
    printMap(map);
    clearScreen();
    v->shoot = false;
    if (v->up && v->weightLeft > 0)
    {
        shootPlayerUp(map, {v->up->x, v->up->y}, false);
    }
}

void shootPlayerRight(vector<vector<Vertex *>> &map, pair<int, int> &position, bool first = true)
{
    Vertex *v = map[position.first][position.second];
    if (!first) v->shoot = true;
    printMap(map);
    clearScreen();
    if (v->up && v->weightRight > 0)
    {
        shootPlayerUp(map, {v->up->x, v->up->y}, false);
    }
}

int countRapidSpacePresses() {
    int count = 0;
    auto lastTime = high_resolution_clock::now();

    cout << "Press SPACE rapidly (max " << MAX_SPACE_PRESSES << " times)..." << endl;

    while (count < MAX_SPACE_PRESSES) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == ' ') {
                auto now = high_resolution_clock::now();
                auto duration = duration_cast<milliseconds>(now - lastTime);

                if (duration.count() > TIME_THRESHOLD_MS) {
                    cout << "Too slow! Restarting count." << endl;
                    count = 0; // Reset if too slow
                } else {
                    ++count;
                    cout << "SPACE pressed! Count = " << count << endl;
                }

                lastTime = now;
            }
        }
    }

    return count;
}

void rollDice(int times) {
    srand(time(0));
    cout << "\nRolling dice " << times << " times:" << endl;

    for (int i = 0; i < times; ++i) {
        int roll = rand() % 6 + 1; // 1 to 6
        cout << "Roll " << (i + 1) << ": " << roll << endl;
    }
}

void controlPlayer(vector<vector<Vertex *>> &map, char input)
{
    switch (input)
    {
    case 'w':
        movePlayerUp(map, currentPos);
        break;
    case 's':
        movePlayerDown(map, currentPos);
        break;
    case 'a':
        movePlayerLeft(map, currentPos);
        break;
    case 'd':
        movePlayerRight(map, currentPos);
        break;
    case 'i':
        shootPlayerUp(map, currentPos);
        break;
    case 'k':
        shootPlayerDown(map, currentPos);
        break;
    case 'j':
        shootPlayerLeft(map, currentPos);
        break;
    case 'l':
        shootPlayerRight(map, currentPos);
        break;
    }

    clearScreen();
    printMap(map);
}