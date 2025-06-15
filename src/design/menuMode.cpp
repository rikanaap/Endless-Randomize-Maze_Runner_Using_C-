#include "package\package.hpp"
#include "main\design.hpp"
#include "main\utils.hpp"
#include "var\global.hpp"

void infoFast()
{
    clearScreen();
    cout << "◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽" << endl;
    cout << "                          " << endl;
    cout << "               ⚡ FAST TYPING MODE ⚡" << endl;
    cout << "                          " << endl;
    cout << "◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽" << endl;
    cout << endl;
    cout << "   📜 Kamu akan diberi kumpulan kata-kata." << endl;
    cout << "   ⏳ Ketik secepat mungkin dalam waktu terbatas!" << endl;
    cout << "   ✅ Setiap kata yang tepat = +1 poin" << endl;
    cout << "   ❌ Setiap kesalahan akan mendekatkan musuh!" << endl;
    cout << "   🚶‍♂️ Musuh maju 1 langkah per kesalahan..." << endl;
    cout << endl;
    cout << "   🎯 Minimal 3 poin dibutuhkan untuk bisa bermain!" << endl;
    cout << "   🔫 Menembak musuh menghabiskan 6 poin" << endl;
    cout << "   🧍 Bergerak/menghindar membutuhkan 1 poin" << endl;
    cout << endl;
    cout << "◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽" << endl;
    cout << endl;
    cout << "Tekan tombol apa saja untuk mulai...";
    _getch();
    clearScreen();
}

void infoAccuracy()
{
    clearScreen();
    cout << "◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽" << endl;
    cout << "                          " << endl;
    cout << "              🎯 ACCURACY TYPING MODE 🎯" << endl;
    cout << "                          " << endl;
    cout << "◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽" << endl;
    cout << endl;
    cout << "   📜 Kamu harus mengetik kalimat dengan benar." << endl;
    cout << "   ⏱️ Tidak ada batas waktu ketat, tapi semakin" << endl;
    cout << "      lama dan semakin typo, poinmu berkurang!" << endl;
    cout << "   ✅ Poin maksimal berdasarkan panjang kalimat" << endl;
    cout << "   ❌ Typo dan waktu = pengurang poin dan musuh maju!" << endl;
    cout << "   🚶‍♂️ Musuh maju 0.5 langkah per typo..." << endl;
    cout << endl;
    cout << "   🎯 Minimal 3 poin dibutuhkan untuk bisa bermain!" << endl;
    cout << "   🔫 Menembak musuh menghabiskan 6 poin" << endl;
    cout << "   🧍 Bergerak/menghindar membutuhkan 1 poin" << endl;
    cout << endl;
    cout << "◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽" << endl;
    cout << endl;
    cout << "Tekan tombol apa saja untuk mulai...";
    _getch();
    clearScreen();
}

void chooseMode() {

    GameConfig config;
    config.fastTyping = false;
    config.acurracyTyping = false;

    while (true)
    {
        cout << "◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽" << endl;
        cout << "                          " << endl;
        cout << "                          🏃 PILIH GAMEMODE 🏃" << endl;
        cout << "                          " << endl;
        cout << "◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽" << endl;
        cout << endl;
        cout << "   F | Speed Type Mode ⚡" << endl;
        cout << "   H | Accuracy Type Mode 🎯" << endl;
        cout << endl;
        cout << "   Backspace | Kembali ke Menu Utama ◀️" << endl;
        cout << endl;
        cout << "◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽" << endl;
        cout << "Tentukan gamemode: ";
        int choice;
        choice = getChar();
        choice = tolower(choice);

        cout << endl;

        switch (choice)
        {
        case 'f':
            config.fastTyping = true;
            infoFast();
            menuLevel(config);
            return;
        case 'h':
            config.acurracyTyping = true;
            infoAccuracy();
            menuLevel(config);
            return;
        case 8:
            return;
        default:
            cout << "\nPilihan tidak valid. 😡 Silakan coba lagi.";
            wait(1000); clearScreen();
            break;
        }
        clearScreen();
    }
}