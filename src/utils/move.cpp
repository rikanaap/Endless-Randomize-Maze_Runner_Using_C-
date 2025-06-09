#include "main\move.hpp"
#include "main\utils.hpp"
#include "var\global.hpp"

using namespace std;

int maxMovementSize = 15;

bool isMoveEmpty()
{
    if (enemyMovement.top == 0) return true;
    else return false;
}

bool isFull()
{
    if (enemyMovement.top >= maxMovementSize) return true;
    return false;
}

void insertMove(char data)
{
    if (isFull()) return;
    else {
        enemyMovement.isi[enemyMovement.top] = data;
        enemyMovement.top++;
    }
}

void removeMove()
{
    if (isMoveEmpty()) { 
        return; }
    else
    {
        for (int i = 1; i < enemyMovement.top; i++)
        {
            enemyMovement.isi[i-1] = enemyMovement.isi[i];
        }
        enemyMovement.top--;
    }
}

char firstMove()
{
    if (isMoveEmpty()) return ' ';
    else return enemyMovement.isi[0];
}