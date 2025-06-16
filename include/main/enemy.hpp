#ifndef ENEMY_HPP
#define ENEMY_HPP

void moveEnemy(int loopFor = 1, bool giveWait = false);
void searchUser();
pair<int, int> randomizePosition(int rows, int cols);

#endif