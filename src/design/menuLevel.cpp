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
        cout << "   ⌫ | Kembali ke Menu Utama ◀️" << endl;

        int choice;
        cout << "Tentukan pilihan level (1-6): ";
        choice = getChar();
        cout << endl; clearScreen();
        switch (choice)
        {
        case 'E':
            runMap(3, 3, {true, true}); // Adjusting rows and cols based on level
            break;
        case 'R':
            runMap(6, 6, {true, false});
            break;
        case 'T':
            runMap(9, 9, {false, true});
            break;
        case 'Y':
            runMap(12, 12, {true, true});
            break;
        case 'U':
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