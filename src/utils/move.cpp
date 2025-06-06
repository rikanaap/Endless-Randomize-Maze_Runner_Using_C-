#include <iostream>
#include "move.hpp"
#include "global.hpp"
#include "map.hpp"
#include "utils.hpp"

using namespace std;

bool isEmpty()
{
    if (enemyMovement.top == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull()
{
    if (enemyMovement.top >= max_size)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void insert(char data)
{
    if (isFull())
    {
        return;
    }
    else
    {
        enemyMovement.isi[enemyMovement.top] = data;
        enemyMovement.top++;
    }
}

void remove()
{
    if (isEmpty())
    {
        return;
    }
    else
    {
        char pop = enemyMovement.isi[0];
        for (int i = 1; i < enemyMovement.top; i++)
        {
            enemyMovement.isi[i-1] = enemyMovement.isi[i];
        }
        enemyMovement.top--;
    }
}

char takeFirst()
{
    if (isEmpty())
    {
        return ' ';
    }
    else
    {
        return enemyMovement.isi[0];
    }
}