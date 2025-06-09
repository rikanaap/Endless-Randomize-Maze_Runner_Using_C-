#include "map.hpp" 
#include "move.hpp"
#include "player.hpp"
#include "utils.hpp"
#include "enemy.hpp"

void runMap(int rows, int cols)
{
    auto map = generateMap(rows, cols, 17);
    char input;
    searchUser(map);
    while (true)
    {
        cout << "\nMove with \n[w: up, s: down, a: left, d: right] \n\nShoot with \n[i: up, k: down, j: left, l: right]\n\n[q: quit]";
        input = getChar();
        input = tolower(input);
        if(input == 'q') {
            clearScreen();
            return;
        }

        controlPlayer(map, input);
    }
}