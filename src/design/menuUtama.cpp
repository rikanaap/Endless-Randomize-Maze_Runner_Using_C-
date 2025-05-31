#include <iostream>
#include "design.hpp"
#include "utils.hpp"
using namespace std;

void menuUtama()
{
    int pilihan;

    while (true)
    {
        cout << "=========================================================" << endl;
        cout << "                 MAZE RUNNER - MENU UTAMA                " << endl;
        cout << "=========================================================" << endl;
        cout << "1. Mulai Permainan" << endl;
        cout << "2. Lihat Map History" << endl;
        cout << "3. Keluar" << endl;
        cout << "=========================================================" << endl;
        cout << "Silakan pilih menu (1-3): ";

        cin.clear();
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            cout << "\n Memulai permainan...\n";
            clearScreen();
            menuLevel();
            break;
        case 2:
            cout << "\n Menampilkan riwayat peta...\n";
            break;
        case 3:
            cout << "\n Terima kasih telah bermain. Sampai jumpa!\n";
            exit(0);
            break;
        default:
            cout << "\n Pilihan tidak valid. Silakan pilih antara 1 - 3.\n";
            break;
        }
        cout << endl;
    }
}
