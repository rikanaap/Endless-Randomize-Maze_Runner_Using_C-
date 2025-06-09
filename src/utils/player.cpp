#include "player.hpp"
#include "map.hpp"
#include "utils.hpp"
#include "env.hpp"
#include "global.hpp"
#include "enemy.hpp"

int playerPoint = 0;

void addPlayerPoint(int point) { playerPoint += point; }
void removePlayerPoint(int point) { playerPoint -= point; }
void removeEnemy(Vertex *v)
{
    if (v->x == enemyPos.first && v->y == enemyPos.second)
        enemyPos = {-1, -1};
}

//? MOVE FUNCTION
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

//?SHOOT FUNCTION
void shootPlayerUp(vector<vector<Vertex *>> &map, pair<int, int> position, bool first = true)
{
    Vertex *v = map[position.first][position.second];
    if (!first)
        v->shoot = true;
    removeEnemy(v);
    printMap(map);
    clearScreen();
    v->shoot = false;
    if (v->up && v->weightUp > 0)
    {
        shootPlayerUp(map, {v->up->x, v->up->y}, false);
    }
}

void shootPlayerDown(vector<vector<Vertex *>> &map, pair<int, int> position, bool first = true)
{
    Vertex *v = map[position.first][position.second];
    if (!first)
        v->shoot = true;
    removeEnemy(v);
    printMap(map);
    clearScreen();
    v->shoot = false;
    if (v->down && v->weightDown > 0)
    {
        shootPlayerDown(map, {v->down->x, v->down->y}, false);
    }
}

void shootPlayerLeft(vector<vector<Vertex *>> &map, pair<int, int> position, bool first = true)
{
    Vertex *v = map[position.first][position.second];
    if (!first)
        v->shoot = true;
    removeEnemy(v);
    printMap(map);
    clearScreen();
    v->shoot = false;
    if (v->left && v->weightLeft > 0)
    {
        shootPlayerLeft(map, {v->left->x, v->left->y}, false);
    }
}

void shootPlayerRight(vector<vector<Vertex *>> &map, pair<int, int> position, bool first = true)
{
    Vertex *v = map[position.first][position.second];
    if (!first)
        v->shoot = true;
    removeEnemy(v);
    printMap(map);
    clearScreen();
    if (v->right && v->weightRight > 0)
    {
        shootPlayerRight(map, {v->right->x, v->right->y}, false);
    }
}

//?OTHER  FUNCTION
void rollDice(int times)
{
    srand(time(0));
    cout << "\nRolling dice " << times << " times:" << endl;

    for (int i = 0; i < times; ++i)
    {
        int roll = rand() % 6 + 1; // 1 to 6
        cout << "Roll " << (i + 1) << ": " << roll << endl;
    }
}
int countRapidSpacePresses()
{
    int count = 0;
    auto startTime = high_resolution_clock::now();

    cout << "Press SPACE rapidly (within " << TIME_THRESHOLD_MS << " ms)..." << endl;

    while (true)
    {
        auto now = high_resolution_clock::now();
        auto elapsed = duration_cast<milliseconds>(now - startTime);

        if (elapsed.count() >= TIME_THRESHOLD_MS)
        {
            break;
        }

        if (_kbhit())
        {
            char ch = _getch();
            if (ch == ' ')
            {
                ++count;
                cout << "SPACE pressed! Count = " << count << endl;
            }
        }
    }

    return count;
}

void controlPlayer(vector<vector<Vertex *>> &map, char input)
{
    int spacePress;
    bool validInput = false;

    switch (input)
    {
    case 'g':
        spacePress = countRapidSpacePresses();
        cout << spacePress;
        rollDice(spacePress);
        moveEnemy(map, 1);
        break;
        case 'w':
        movePlayerUp(map, currentPos);
        validInput = true;
        removePlayerPoint(1);
        moveEnemy(map, 1);
        break;
        case 's':
        movePlayerDown(map, currentPos);
        validInput = true;
        removePlayerPoint(1);
        moveEnemy(map, 1);
        break;
        case 'a':
        movePlayerLeft(map, currentPos);
        validInput = true;
        removePlayerPoint(1);
        moveEnemy(map, 1);
        break;
        case 'd':
        movePlayerRight(map, currentPos);
        validInput = true;
        removePlayerPoint(1);
        moveEnemy(map, 1);
        break;
        case 'i':
        shootPlayerUp(map, currentPos);
        validInput = true;
        removePlayerPoint(6);
        moveEnemy(map, 3);
        break;
        case 'k':
        shootPlayerDown(map, currentPos);
        validInput = true;
        removePlayerPoint(6);
        moveEnemy(map, 3);
        break;
        case 'j':
        shootPlayerLeft(map, currentPos);
        validInput = true;
        removePlayerPoint(6);
        moveEnemy(map, 3);
        break;
        case 'l':
        shootPlayerRight(map, currentPos);
        validInput = true;
        removePlayerPoint(6);
        moveEnemy(map, 3);
        break;
    }

    if (validInput)
    {
        clearScreen();
        printMap(map);
    }
}