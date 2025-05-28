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

void controlPlayerWithKeyboard(vector<vector<Vertex *>> &map, pair<int, int> &currentPos, Vertex *start, Vertex *end)
{
    char input;
    while (true)
    {
        cout << "\nMove with [i: up, k: down, j: left, l: right], [q: quit]: ";
        char input = getChar();
        input = tolower(input);

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
        case 'q':
            cout << "Exiting movement.\n";
            return;
        default:
            cout << "Invalid input.\n";
        }

        cout << currentPos.first << " | " << currentPos.second << endl;
        clearScreen();
        printMap(map, currentPos, start, end);
    }
}