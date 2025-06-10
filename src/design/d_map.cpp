#include "main\map.hpp"
#include "main\move.hpp"
#include "main\player.hpp"
#include "main\utils.hpp"
#include "main\enemy.hpp"
#include "main\design.hpp"

void runMap(int rows, int cols, GameConfig config)
{
    auto map = generateMap(rows, cols, 17);
    char input;
    playerPoint = 6;
    playerWin = false;
    enemyWin = false;
    
    searchUser(map);
    printTutorial();
    while (true)
    {
        input = getChar();
        input = tolower(input);
        if(input == 8) {
            clearScreen();
            return;
        }

        controlPlayer(map, input, config);
        if(enemyWin) return tampilanKalah();
        if(playerWin) return tampilanMenang();
    }
}