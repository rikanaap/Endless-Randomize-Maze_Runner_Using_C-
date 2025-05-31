#include "package.hpp"
#include "design.hpp"
#include "utils.hpp"

void menuLevel()
{
    cout << "====================" << endl;
    cout << "    Pilih Level   " << endl;
    cout << "====================" << endl;
    cout << "1. Level 1" << endl;
    cout << "2. Level 2" << endl;
    cout << "3. Level 3" << endl;
    cout << "4. Level 4" << endl;
    cout << "5. Level 5" << endl;
    cout << "6. Back to Main Menu" << endl;

    int choice ; cout << "Tentukan pilihan level (1-6): ";
    cin >> choice;
    if (choice < 1 || choice > 6) {
        cout << "Maaf level yang dipilih tidak tersedia. Pilih ulang level" << endl;
        return;
    }
    clearScreen();
    switch (choice) {
        case 1:
            runMap(3,3); // Adjusting rows and cols based on level
            break;
        case 2:
            runMap(6,6);
            break;
        case 3:
            runMap(9,9);
            break;
        case 4:
            runMap(12,12);
            break;
        case 5:
            runMap(15,15);
            break;
        case 6:
            runMap(18,18);
            return; // Exit to main menu
    }
}