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
    cout << "[Backspace] 🚪 Kembali ke menu level" << endl;
    cout << "Pilihanmu: ";

    char pilihan;
    pilihan = getChar();
    switch (pilihan) {
        case 8:
            clearScreen();
            menuLevel();
            break;
        default:
            cout << "Pilihan tidak valid.\n";
            wait(500);
            tampilanMenang(); // ulang lagi
            break;
    }
}
