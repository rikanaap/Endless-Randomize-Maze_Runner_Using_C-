#include <iostream>
#include "utils.hpp"
#include <design.hpp>
using namespace std;

void tampilanKalah()
{
    cout << "\n";
    cout << "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛\n";
    cout << "                     ";
    cout << "                     GAME OVER ☠️                     \n";
    cout << "                     ";
    cout << "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛\n";
    cout << "\n";
    cout << "[1] 🔁 Main Lagi" << endl;
    cout << "[2] 🚪 Keluar" << endl;
    cout << "Pilihanmu: ";

    char pilihan;
    pilihan = getChar();
    switch (pilihan)
    {
    case '1':
        clearScreen();
        break;
    case '2':
        cout << "\nTerima kasih telah bermain Maze Runner!\n";
        wait(2);
        exit(0);
        break;
    default:
        cout << "Pilihan tidak valid.\n";
        wait(1);
        tampilanKalah();
        break;
    }
}