#include "map.hpp"
#include "player.hpp"
#include "utils.hpp"
#include "enemy.hpp"
#include "move.hpp"

void runMap(int rows, int cols)
{
    insert('u'); insert('d'); insert('l'); insert('r');
    auto map = generateMap(rows, cols, 17);
    char input;
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