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
        cout << "   Backspace | Kembali ke Menu Utama ◀️" << endl;
        cout << endl;
        cout << "◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽" << endl;
        cout << "Tentukan pilihan level: ";
        int choice;
        choice = getChar();
        choice = tolower(choice);

        cout << endl;
        clearScreen();
        switch (choice)
        {
        case 'e':
            // keyboard();
            config.defaultPoint = 1;
            runMap(3, 3, config);
            break;
        case 'r':
            // keyboard();
            config.defaultPoint = 2;
            runMap(6, 6, config);
            break;
        case 't':
            // keyboard();
            config.defaultPoint = 3;
            runMap(9, 9, config);
            break;
        case 'y':
            // keyboard();
            config.defaultPoint = 4;
            runMap(12, 12, config);
            break;
        case 'u':
            // keyboard();
            config.defaultPoint = 5;
            runMap(15, 15, config);
            break;
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