#include "package\package.hpp"
#include "main\design.hpp"
#include "main\utils.hpp"
#include "var\global.hpp"

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
        cout << "   Backspace | Kembali ke Menu Utama ◀️" << endl;
        cout << endl;
        cout << "◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽" << endl;
        cout << "Tentukan gamemode: ";
        int choice;
        choice = getChar();
        choice = tolower(choice);

        cout << endl;
        clearScreen();
        switch (choice)
        {
        case 'f':
            config.fastTyping = true;
            clearScreen();
            menuLevel(config);
            return;
        case 'h':
            config.acurracyTyping = true;
            clearScreen();
            menuLevel(config);
            return;
        case 8:
            return;
        default:
            cout << "Tidak ada pilihan, mohon coba lagi!!";
            wait(500);
            break;
        }
        clearScreen();
    }
}