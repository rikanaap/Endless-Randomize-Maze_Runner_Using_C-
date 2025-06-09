#include "package.hpp"
#include "design.hpp"
#include "utils.hpp"

void menuLevel()
{
    while (true)
    {
        cout << "◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽" << endl;
        cout << "                          " << endl;
        cout << "                          🏃 PILIH LEVEL 🏃" << endl;
        cout << "◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽" << endl;
        cout << "   1. Level 1️⃣" << endl;
        cout << "   2. Level 2️⃣" << endl;
        cout << "   3. Level 3️⃣" << endl;
        cout << "   4. Level 4️⃣" << endl;
        cout << "   5. Level 5️⃣" << endl;
        cout << "   6. ◀️ | Kembali ke Menu Utama" << endl;

        int choice;
        cout << "Tentukan pilihan level (1-6): ";
        choice = getChar();
        cout << endl; clearScreen();
        switch (choice)
        {
        case '1':
            runMap(3, 3); // Adjusting rows and cols based on level
            break;
        case '2':
            runMap(6, 6);
            break;
        case '3':
            runMap(9, 9);
            break;
        case '4':
            runMap(12, 12);
            break;
        case '5':
            runMap(15, 15);
            break;
        case '6': return; // Exit to main menu
        default:
            cout << "Tidak ada pilihan, mohon coba lagi!!";
            wait(1);
            break;
        }
        clearScreen();
    }
}