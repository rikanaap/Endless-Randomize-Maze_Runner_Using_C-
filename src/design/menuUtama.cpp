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
            cout << "   F | Mulai Permainan 🎮" << endl;
            cout << "   Backspace | Keluar ⛔" << endl;
            cout << endl;
            cout << "◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽" << endl;
            cout << "Silakan pilih menu: ";
            cin.clear();
            pilihan = getChar();
            pilihan = tolower(pilihan);

            switch (pilihan)
            {
            case 'f':
                cout << "\n⏩ Memulai permainan...\n";
                clearScreen();
                menuLevel();
                break;
            case 8:
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
