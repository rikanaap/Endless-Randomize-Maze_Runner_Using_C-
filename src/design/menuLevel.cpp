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
        cout << "◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽" << endl;
        cout << "   E | Level 1️⃣" << endl;
        cout << "   R | Level 2️⃣" << endl;
        cout << "   T | Level 3️⃣" << endl;
        cout << "   Y | Level 4️⃣" << endl;
        cout << "   U | Level 5️⃣" << endl;
        cout << "   Backspace | Kembali ke Menu Utama ◀️" << endl;

        int choice;
        cout << "Tentukan pilihan level: ";
        choice = getChar();
        choice = tolower(choice);

        cout << endl; clearScreen();
        switch (choice)
        {
        case 'e':
            runMap(3, 3, {true, true}); // Adjusting rows and cols based on level
            break;
        case 'r':
            runMap(6, 6, {true, false});
            break;
        case 't':
            runMap(9, 9, {false, true});
            break;
        case 'y':
            runMap(12, 12, {true, true});
            break;
        case 'u':
            runMap(15, 15, {false, true});
            break;
        case 8: return; // Exit to main menu
        default:
            cout << "Tidak ada pilihan, mohon coba lagi!!";
            wait(1);
            break;
        }
        clearScreen();
    }
}