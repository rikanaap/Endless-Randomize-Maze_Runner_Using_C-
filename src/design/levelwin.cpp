#include <iostream>
#include "main\utils.hpp"
#include "main\design.hpp"
using namespace std;

void tampilanMenang() {
    clearScreen();
    cout << "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛" << endl;
    cout << "         🏁 SELAMAT! 🏁                  " << endl;
    cout << "    KAMU KELUAR DARI MAZE RUNNER!       " << endl;
    cout << "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛" << endl;
    cout << endl;
    cout << "🧠  Langkahmu luar biasa!" << endl;
    cout << "💡  Logika dan kesabaranmu patut diacungi jempol." << endl;
    cout << endl;
    cout << "[1] 🔁 Main Lagi" << endl;
    cout << "[2] 🚪 Keluar" << endl;
    cout << "Pilihanmu: ";

    char pilihan;
    pilihan = getChar();
    switch (pilihan) {
        case '1':
            clearScreen();
            menuLevel(); // panggil ulang pemilihan level
            break;
        case '2':
            cout << "\nTerima kasih telah bermain Maze Runner!\n";
            wait(2);
            exit(0);
            break;
        default:
            cout << "Pilihan tidak valid.\n";
            wait(1);
            tampilanMenang(); // ulang lagi
            break;
    }
}
