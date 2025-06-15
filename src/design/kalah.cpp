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
    cout << "                 GAME OVER ☠️                     \n";
    cout << "                     \n";
    cout << "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛\n";
    cout << "\n";
    cout << "[Backspace] 🚪 Kembali ke menu level";

    char pilihan;
    pilihan = getChar();
    switch (pilihan)
    {
    case 8:
        clearScreen();
        break;
    default:
        cout << "\n\nPilihan tidak valid. 😡 Silakan coba lagi.";
        wait(1000);
        tampilanKalah();
        break;
    }
}