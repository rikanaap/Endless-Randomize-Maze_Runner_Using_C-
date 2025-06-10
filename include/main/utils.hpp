#ifndef UTILS_HPP
#define UTILS_HPP

#include "package\package.hpp"

std::vector<std::string> split(const std::string &s, char delimiter);
void clearScreen();
char getChar();
int randomInt(int min, int max);
void wait(int seconds);
void counting123();

#endif