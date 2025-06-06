#ifndef MOVE_HPP
#define MOVE_HPP

#include "package.hpp"

const int max_size = 15;
struct Queue
{
    int top = 0;
    char isi[max_size];
};
extern Queue enemyMovement;
void insert(char data);
void remove();
char takeFirst();

#endif