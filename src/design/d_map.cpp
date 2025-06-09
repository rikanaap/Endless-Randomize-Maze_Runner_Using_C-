#include "map.hpp" 
#include "move.hpp"
#include "player.hpp"
#include "utils.hpp"
#include "enemy.hpp"
#include "design.hpp"

void runMap(int rows, int cols)
{
    auto map = generateMap(rows, cols, 17);
    char input;
    playerPoint = 6;
    playerWin = false;
    enemyWin = false;
    
    searchUser(map);
    cout << "\n🪙 Point: "<< playerPoint <<"\n\nMove with \n[w: up, s: down, a: left, d: right] \n\nShoot with \n[i: up, k: down, j: left, l: right]\n\n💯💯💯 TRY OUR GAMBLING SLOT, PRESS 'G'🤑🤑🤑🤑\n\n[q: quit]";
    while (true)
    {
        input = getChar();
        input = tolower(input);
        if(input == 'q') {
            clearScreen();
            return;
        }

        controlPlayer(map, input);
        if(enemyWin) return tampilanKalah();
        if(playerWin) return tampilanMenang();
    }
}