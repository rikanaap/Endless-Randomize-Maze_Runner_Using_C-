#include "package/package.hpp"
#include "main/utils.hpp"

void keyboard()
{

    clearScreen();
    cout << "       👇 Coba Lihat Keyboard Anda 👇" << endl
         << endl;
    wait(500);
    cout << "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛" << endl;
    string keys = "⬛\t  Q  W  E  R  T  Y  U  I  O  P \t⬛\n⬛\t   A  S  D  F  G  H  J  K  L \t⬛\n⬛\t    Z  X  C  V  B  N  M\t\t⬛";
    for (char c : keys)
    {
        if (c == 'W' || c == 'A' || c == 'D' || c == 'I' || c == 'J' || c == 'L')
            std::cout << "\033[32m" << c << "\033[0m"; // Green
        else
            std::cout << c;
    }
    cout << endl;
    cout << "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛" << endl
         << endl;
    cout << "Tekan 'SPACE' untuk melanjutkan." << endl
         << endl;
    char input;
    input = getChar();

    clearScreen();
    cout << "1. Simpan jari manis kiri pada huruf A 🤚" << endl << endl;
    cout << "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛" << endl;
    keys = "⬛\t  Q  W  E  R  T  Y  U  I  O  P \t⬛\n⬛\t   A  S  D  F  G  H  J  K  L \t⬛\n⬛\t    Z  X  C  V  B  N  M\t\t⬛";
    for (char c : keys)
    {
        if (c == 'A')
            std::cout << "\033[32m" << c << "\033[0m"; // Green
        else
            std::cout << c;
    }
    cout << endl;
    cout << "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛" << endl
         << endl;
    cout << "Tekan 'SPACE' untuk melanjutkan." << endl
         << endl;
    input = getChar();
    
    clearScreen();
    cout << "2. Simpan jari tengah kiri pada huruf W 🤚" << endl << endl;
    cout << "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛" << endl;
    keys = "⬛\t  Q  W  E  R  T  Y  U  I  O  P \t⬛\n⬛\t   A  S  D  F  G  H  J  K  L \t⬛\n⬛\t    Z  X  C  V  B  N  M\t\t⬛";
    for (char c : keys)
    {
        if (c == 'W' || c == 'A')
            std::cout << "\033[32m" << c << "\033[0m"; // Green
        else
            std::cout << c;
    }
    cout << endl;
    cout << "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛" << endl
         << endl;
    cout << "Tekan 'SPACE' untuk melanjutkan." << endl
         << endl;
    input = getChar();
    
    clearScreen();
    cout << "3. Simpan jari telunjuk kiri pada huruf D 🤚" << endl << endl;
    cout << "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛" << endl;
    keys = "⬛\t  Q  W  E  R  T  Y  U  I  O  P \t⬛\n⬛\t   A  S  D  F  G  H  J  K  L \t⬛\n⬛\t    Z  X  C  V  B  N  M\t\t⬛";
    for (char c : keys)
    {
        if (c == 'D' || c == 'W' || c == 'A')
            std::cout << "\033[32m" << c << "\033[0m"; // Green
        else
            std::cout << c;
    }
    cout << endl;
    cout << "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛" << endl
         << endl;
    cout << "Tekan 'SPACE' untuk melanjutkan." << endl
         << endl;
    input = getChar();
    
    clearScreen();
    cout << "4. Simpan jari telunjuk kanan pada huruf J ✋" << endl << endl;
    cout << "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛" << endl ;
    keys = "⬛\t  Q  W  E  R  T  Y  U  I  O  P \t⬛\n⬛\t   A  S  D  F  G  H  J  K  L \t⬛\n⬛\t    Z  X  C  V  B  N  M\t\t⬛";
    for (char c : keys)
    {
        if (c == 'J' || c == 'D' || c == 'W' || c == 'A')
            std::cout << "\033[32m" << c << "\033[0m"; // Green
        else
            std::cout << c;
    }
    cout << endl;
    cout << "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛" << endl
         << endl;
    cout << "Tekan 'SPACE' untuk melanjutkan." << endl
         << endl;
    input = getChar();

    clearScreen();
    cout << "5. Simpan jari tengah kanan pada huruf I ✋" << endl << endl;
    cout << "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛" << endl ;
    keys = "⬛\t  Q  W  E  R  T  Y  U  I  O  P \t⬛\n⬛\t   A  S  D  F  G  H  J  K  L \t⬛\n⬛\t    Z  X  C  V  B  N  M\t\t⬛";
    for (char c : keys)
    {
        if (c == 'I' || c == 'J' || c == 'D' || c == 'W' || c == 'A')
            std::cout << "\033[32m" << c << "\033[0m"; // Green
        else
            std::cout << c;
    }
    cout << endl;
    cout << "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛" << endl
         << endl;
    cout << "Tekan 'SPACE' untuk melanjutkan." << endl
         << endl;
    input = getChar();

    clearScreen();
    cout << "6. Simpan jari manis kanan pada huruf L ✋" << endl << endl;
    cout << "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛" << endl ;
    keys = "⬛\t  Q  W  E  R  T  Y  U  I  O  P \t⬛\n⬛\t   A  S  D  F  G  H  J  K  L \t⬛\n⬛\t    Z  X  C  V  B  N  M\t\t⬛";
    for (char c : keys)
    {
        if (c == 'L' || c == 'I' || c == 'J' || c == 'D' || c == 'W' || c == 'A')
            std::cout << "\033[32m" << c << "\033[0m"; // Green
        else
            std::cout << c;
    }
    cout << endl;
    cout << "⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛⬛" << endl
         << endl;
    cout << "❗ Pertahankan posisi jari Anda pada keyboard untuk memainkan game sampai selesai ❗" << endl
         << endl;
    cout << "Tekan 'SPACE' untuk melanjutkan." << endl
         << endl;
    input = getChar();

    input = getChar();
}
