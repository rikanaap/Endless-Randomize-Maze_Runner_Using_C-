#include "package\package.hpp"
#include "main\design.hpp"
#include "main\utils.hpp"

void menuLevel(GameConfig config)
{
    while (true)
    {
        cout << "◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽" << endl;
        cout << "                          " << endl;
        cout << "                          🏃 PILIH LEVEL 🏃" << endl;
        cout << "                          " << endl;
        cout << "◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽" << endl;
        cout << endl;
        cout << "   E | Level 1️⃣" << endl;
        cout << "   R | Level 2️⃣" << endl;
        cout << "   T | Level 3️⃣" << endl;
        cout << "   Y | Level 4️⃣" << endl;
        cout << "   U | Level 5️⃣" << endl;
        cout << endl;
        cout << "   Backspace | Kembali ke Menu Utama ◀️" << endl;
        cout << endl;
        cout << "◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽" << endl;
        cout << "Tentukan pilihan level: ";
        int choice;
        choice = getChar();
        choice = tolower(choice);

        cout << endl;

        switch (choice)
        {
        case 'e':
            clearScreen();
            // keyboard();
            config.defaultPoint = 1;
            runMap(3, 3, config);
            break;
        case 'r':
            clearScreen();
            // keyboard();
            config.defaultPoint = 2;
            runMap(6, 6, config);
            break;
        case 't':
            clearScreen();
            // keyboard();
            config.defaultPoint = 3;
            runMap(9, 9, config);
            break;
        case 'y':
            clearScreen();
            // keyboard();
            config.defaultPoint = 4;
            runMap(12, 12, config);
            break;
        case 'u':
            clearScreen();
            // keyboard();
            config.defaultPoint = 5;
            runMap(15, 15, config);
            break;
        case 8:
            clearScreen();
            return;
        default:
            cout << "\nPilihan tidak valid. 😡 Silakan coba lagi.";
            wait(1000); clearScreen();
            break;
        }
        clearScreen();
    }
}