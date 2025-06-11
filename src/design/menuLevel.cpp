#include "package\package.hpp"
#include "main\design.hpp"
#include "main\utils.hpp"

void menuLevel()
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
            keyboard();
            runMap(3, 3, {true, true, 1}); // Adjusting rows and cols based on level
            break;
        case 'r':
            keyboard();
            runMap(6, 6, {true, false, 2});
            break;
        case 't':
            keyboard();
            runMap(9, 9, {false, true, 3});
            break;
        case 'y':
            keyboard();
            runMap(12, 12, {true, true, 4});
            break;
        case 'u':
            keyboard();
            runMap(15, 15, {false, true, 5});
            break;
        case 8:
            return; // Exit to main menu
        default:
            cout << "Tidak ada pilihan, mohon coba lagi!!";
            wait(500);
            break;
        }
        clearScreen();
    }
}