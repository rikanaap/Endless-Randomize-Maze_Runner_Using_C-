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
    cout << "[Backspace] 🚪 Kembali ke menu level";

    char pilihan;
    pilihan = getChar();
    switch (pilihan) {
        case 8:
            clearScreen();
            break;
        default:
            cout << "\n\nPilihan tidak valid. 😡 Silakan coba lagi.";
            wait(1000);
            tampilanMenang(); // ulang lagi
            break;
    }
}
