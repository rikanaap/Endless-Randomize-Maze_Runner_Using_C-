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
    playerPoint = config.defaultPoint;
    playerWin = false;
    enemyWin = false;
    
    searchUser();
    printTutorial();
    while (true)
    {
        input = getChar();
        input = tolower(input);

        controlPlayer(input, config);
        if(enemyWin) return tampilanKalah();
        if(playerWin) return tampilanMenang();
    }
}