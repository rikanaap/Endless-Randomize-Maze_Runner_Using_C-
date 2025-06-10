#include "package\package.hpp"
#include "main\utils.hpp"

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

void wait(int seconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(seconds));
}

void counting123(){
    cout << "1"; wait(100); cout << "."; wait(100); cout << "."; wait(100); cout << ". " ;
    cout << "2"; wait(100); cout << "."; wait(100); cout << "."; wait(100); cout << ". " ;
    cout << "3"; wait(100); cout << "."; wait(100); cout << "."; wait(100); cout << ". " ;
}