#include "package\package.hpp"
#include "main\utils.hpp"
#include "main\design.hpp"
#include "var\env.hpp"
#include "main\leaderboard.hpp"

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    keyboard();
    isiUsername();
    clearScreen();
    menuUtama();
}
