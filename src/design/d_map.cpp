#include "map.hpp"
#include "player.hpp"
#include "utils.hpp"

void runMap(int rows, int cols)
{
    cout << "MAKAN NASI" << endl;
    auto map = generateMap(rows, cols, 17);
    char input;
    while (true)
    {
        cout << "\nMove with [i: up, k: down, j: left, l: right], [q: quit]: ";
        input = getChar();
        input = tolower(input);
        if(input == 'q') return;

        controlPlayer(map, input);
    }
    
}