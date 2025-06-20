#include <iostream>
#include "main\design.hpp"
#include "main\utils.hpp"
#include "var\global.hpp"
#include "main\leaderboard.hpp"
using namespace std;

void menuUtama()
{
    clearScreen();
    char pilihan;

    while (true)
    {
        while (true)
        {
            cout << "◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽" << endl;
            cout << "                  " << endl;
            cout << "                  🏃 MAZE RUNNER - MENU UTAMA 🏃" << endl;
            cout << "                  👋 Selamat datang " << currentUsername << endl;
            cout << "                  " << endl;
            cout << "◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽" << endl;
            cout << endl;
            cout << "   F | Mulai Permainan 🎮" << endl;
            cout << "   H | Lihat Leaderboard " << endl;
            cout << endl;
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
                chooseMode();
                break;
            case 'h':
                cout << "\n⏩ Memuat Leaderboard\n";
                clearScreen();
                readLeaderboard();
                break;
            case 8:
                cout << "\nTerima kasih telah bermain. Sampai jumpa!😎👋\n";
                wait(500);
                exit(0);
                break;
            default:
                cout << "\n\nPilihan tidak valid. 😡 Silakan coba lagi.";
                wait(1000); clearScreen();
                break;
            };

            cout << endl;
        }
    }
}