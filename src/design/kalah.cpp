#include <iostream>
#include "main\utils.hpp"
#include "main\design.hpp"
using namespace std;

void tampilanKalah()
{
    clearScreen();
    cout << "\n";
    cout << "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛\n";
    cout << "                     \n";
    cout << "                     GAME OVER ☠️                     \n";
    cout << "                     \n";
    cout << "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛\n";
    cout << "\n";
    cout << "[Backspace] 🚪 Kembali ke menu level" << endl;
    cout << "Pilihanmu: ";

    char pilihan;
    pilihan = getChar();
    switch (pilihan)
    {
    case 8:
        clearScreen();
        menuLevel();
        break;
    default:
        cout << "Pilihan tidak valid.\n";
        wait(500);
        tampilanKalah();
        break;
    }
}