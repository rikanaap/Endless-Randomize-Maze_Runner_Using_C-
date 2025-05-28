#include "package.hpp"
#include "utils.hpp"

std::vector<std::string> split(const std::string &s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream ss(s);
    while (getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

void clearScreen()
{
    // ANSI escape code to clear screen and move cursor to top-left
    std::cout << "\033[2J\033[1;1H";
}

char getChar()
{
    return _getch(); // instantly reads keypress without Enter
}

int randomInt(int min, int max)
{
    return rand() % (max - min + 1) + min;
}