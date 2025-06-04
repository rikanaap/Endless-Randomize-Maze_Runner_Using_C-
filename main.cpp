#include "package.hpp"
#include "utils.hpp"
#include "design.hpp"
#include "env.hpp"

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    clearScreen();
    menuUtama();
}
