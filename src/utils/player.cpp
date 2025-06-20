#include "main\player.hpp"
#include "main\map.hpp"
#include "main\utils.hpp"
#include "var\env.hpp"
#include "var\global.hpp"
#include "main\enemy.hpp"
#include "main\game.hpp"
#include "main\leaderboard.hpp"

int playerPoint = 0;
int leaderboardPoint = 1000;

void addPlayerPoint(int point)
{
    int temp = playerPoint;
    temp += point;
    cout << "Point: " << point;
    if (temp > 10)
        playerPoint = 10;
    else
        playerPoint = temp;
}
void addLeaderboardPoint(int point) { leaderboardPoint += point; }
void removeLeaderboardPoint(int point) { 
    leaderboardPoint -= point;
    if(leaderboardPoint < 0) leaderboardPoint = 0;
  }
bool removePlayerPoint(int point)
{
    if (playerPoint < point)
        return false;
    int temp = playerPoint;
    temp -= point;
    if (temp < 0)
        return false;
    playerPoint -= point;
    return true;
}

void removeEnemy(Vertex *v)
{
    if (v->x == enemyPos.first && v->y == enemyPos.second){
        enemyPos = {-1, -1};
        addLeaderboardPoint(100);
    }
}

void isPlayerWin(Vertex *nextVertex)
{
    if (nextVertex->endVertex){
        playerWin = true;
        insertLeaderboard(leaderboardPoint);
    } 
}

//? MOVE FUNCTION
void movePlayerUp(pair<int, int> &currentPos)
{
    Vertex *v = runningMap[currentPos.first][currentPos.second];
    if (v->up && v->weightUp > 0)
    {
        isPlayerWin(v->up);
        currentPos.first -= 1;
    }
    removeLeaderboardPoint(10);
}

void movePlayerDown(pair<int, int> &currentPos)
{
    Vertex *v = runningMap[currentPos.first][currentPos.second];
    if (v->down && v->weightDown > 0)
    {
        isPlayerWin(v->down);
        currentPos.first += 1;
    }
    removeLeaderboardPoint(10);
}

void movePlayerLeft(pair<int, int> &currentPos)
{
    Vertex *v = runningMap[currentPos.first][currentPos.second];
    if (v->left && v->weightLeft > 0)
    {
        isPlayerWin(v->left);
        currentPos.second -= 1;
    }
    removeLeaderboardPoint(10);
}

void movePlayerRight(pair<int, int> &currentPos)
{
    Vertex *v = runningMap[currentPos.first][currentPos.second];
    if (v->right && v->weightRight > 0)
    {
        isPlayerWin(v->right);
        currentPos.second += 1;
    }
    removeLeaderboardPoint(10);
}

//?SHOOT FUNCTION
void shootPlayerUp(pair<int, int> position, bool first = true)
{
    Vertex *v = runningMap[position.first][position.second];
    if (!first)
        v->shoot = true;
    removeEnemy(v);
    cout << endl;
    printMap();
    wait(200);
    clearScreen();
    v->shoot = false;
    if (v->up && v->weightUp > 0)
    {
        shootPlayerUp({v->up->x, v->up->y}, false);
    }
}

void shootPlayerDown(pair<int, int> position, bool first = true)
{
    Vertex *v = runningMap[position.first][position.second];
    if (!first)
    v->shoot = true;
    removeEnemy(v);
    cout << endl;
    printMap();
    wait(500);
    clearScreen();
    v->shoot = false;
    if (v->down && v->weightDown > 0)
    {
        shootPlayerDown({v->down->x, v->down->y}, false);
    }
}

void shootPlayerLeft(pair<int, int> position, bool first = true)
{
    Vertex *v = runningMap[position.first][position.second];
    if (!first)
    v->shoot = true;
    removeEnemy(v);
    cout << endl;
    printMap();
    wait(500);
    clearScreen();
    v->shoot = false;
    if (v->left && v->weightLeft > 0)
    {
        shootPlayerLeft({v->left->x, v->left->y}, false);
    }
}

void shootPlayerRight(pair<int, int> position, bool first = true)
{
    Vertex *v = runningMap[position.first][position.second];
    if (!first)
    v->shoot = true;
    removeEnemy(v);
    cout << endl;
    printMap();
    wait(500);
    clearScreen();
    v->shoot = false;
    if (v->right && v->weightRight > 0)
    {
        shootPlayerRight({v->right->x, v->right->y}, false);
    }
}

//?MELEE FUNCTION | BACKUP COMBAT SYSTEM
void meleeUp()
{
    int x = currentPos.first - 1;
    int y = currentPos.second;
    if (x >= 0 && runningMap[x][y] && enemyPos.first == x && enemyPos.second == y)
    {
        enemyPos = {-1, -1};
        cout << "Enemy killed with melee up!\n";
    }
}

void meleeDown()
{
    int x = currentPos.first + 1;
    int y = currentPos.second;
    if (x < runningMap.size() && runningMap[x][y] && enemyPos.first == x && enemyPos.second == y)
    {
        enemyPos = {-1, -1};
        cout << "Enemy killed with melee down!\n";
    }
}

void meleeLeft()
{
    int x = currentPos.first;
    int y = currentPos.second - 1;
    if (y >= 0 && runningMap[x][y] && enemyPos.first == x && enemyPos.second == y)
    {
        enemyPos = {-1, -1};
        cout << "Enemy killed with melee left!\n";
    }
}

void meleeRight()
{
    int x = currentPos.first;
    int y = currentPos.second + 1;
    if (y < runningMap[0].size() && runningMap[x][y] && enemyPos.first == x && enemyPos.second == y)
    {
        enemyPos = {-1, -1};
        cout << "Enemy killed with melee right!\n";
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
    cout << "1";
    wait(500);
    cout << "2";
    wait(500);
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

void printTutorial()
{
    cout << "\n🪙 Point: " << playerPoint;
    if (playerPoint < 4)
        cout << "\n\n💯 Tekan 'G' untuk memainkan game dan dapatkan poin! 💯";
    cout << "\n\n 😯 : Player \n 😈 : musuh \n 🏁 : Finish";
    cout << "\n\nMove with \n[w: up, s: down, a: left, d: right] \n\nShoot with \n[i: up, k: down, j: left, l: right]";
}

void countLeaderboardPoint(){

}

void controlPlayer(char input, GameConfig config)
{
    int choosenGame = 0;
    bool validInput = false;
    auto [randomWord, estSecond] = wordsConvert();
    char selectedWords[100];
    // printTutorial();
    switch (input)
    {
    case 'g':
        if (playerPoint > 3) { break; }
        clearScreen();
        choosenGame = config.fastTyping ? 1 : 2;
        switch (choosenGame)
        {
        case 1:
            fastTyping(randomWord, estSecond);
            break;
        case 2:
            strncpy(selectedWords, randomWord.c_str(), sizeof(selectedWords));
            selectedWords[sizeof(selectedWords) - 1] = '\0';

            runMonkeytype(selectedWords);
            break;
        }
        validInput = true;
        break;
    case 'w':
        if (removePlayerPoint(1))
        {
            movePlayerUp(currentPos);
            validInput = true;
            moveEnemy(1, false);
        }
        break;
    case 's':
        if (removePlayerPoint(1))
        {
            movePlayerDown(currentPos);
            validInput = true;
            moveEnemy(1, false);
        }
        break;
    case 'a':
        if (removePlayerPoint(1))
        {
            movePlayerLeft(currentPos);
            validInput = true;
            moveEnemy(1, false);
        }
        break;
    case 'd':
        if (removePlayerPoint(1))
        {
            movePlayerRight(currentPos);
            validInput = true;
            moveEnemy(1, false);
        }
        break;
    case 'i':
        if (removePlayerPoint(6))
        {
            shootPlayerUp(currentPos);
            // meleeUp();
            validInput = true;
            moveEnemy(3, false);
        }
        break;
    case 'k':
        if (removePlayerPoint(6))
        {
            shootPlayerDown(currentPos);
            // meleeDown();
            validInput = true;
            moveEnemy(3, false);
        }
        break;
    case 'j':
        if (removePlayerPoint(6))
        {
            shootPlayerLeft(currentPos);
            // meleeLeft();
            validInput = true;
            moveEnemy(3, false);
        }
        break;
    case 'l':
        if (removePlayerPoint(6))
        {
            shootPlayerRight(currentPos);
            // meleeRight();
            validInput = true;
            moveEnemy(3, false);
        }
        break;
    }

    if (validInput)
    {
        clearScreen();
        printMap();
        printTutorial();
    }
}