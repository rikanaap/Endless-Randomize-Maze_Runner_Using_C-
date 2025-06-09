#include <iostream>
#include "main\design.hpp"
#include "main\utils.hpp"
using namespace std;

void menuUtama()
{
    char pilihan;

    while (true)
    {
        while(true){
            cout << "◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽" << endl;
            cout << "                  " << endl;
            cout << "                  🏃 MAZE RUNNER - MENU UTAMA 🏃" << endl;
            cout << "                  " << endl;
            cout << "◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽" << endl;
            cout << endl;
            cout << "   1. 🎮 | Mulai Permainan" << endl;
            cout << "   2. ⛔ | Keluar" << endl;
            cout << endl;
            cout << "◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽" << endl;
            cout << "Silakan pilih menu (1-2): ";
            cin.clear();
            pilihan = getChar();

            switch (pilihan)
            {
            case '1':
                cout << "\n⏩ Memulai permainan...\n";
                clearScreen();
                menuLevel();
                break;
            case '2':
                cout << "\nTerima kasih telah bermain. Sampai jumpa!😎👋\n";
                wait(1); exit(0);
                break;
            default:
                cout << "\nPilihan tidak valid.😡 Silakan pilih antara 1 dan 2.\n";
                wait(1); clearScreen();
                break;
            }
            
            cout << endl;
        }
    }
}
