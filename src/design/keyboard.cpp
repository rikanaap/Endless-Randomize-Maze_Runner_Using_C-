#include <iostream>

// int main() {
void keyboard() {
    std::cout << "SIMPAN TANGAN ANDA DI POSISI KEYBOARD BERWARNA HIJAU!!" << std::endl;
    std::string keys = " q w e r t y u i o p \n  a s d f g  h j k l\n   z x c v b n m";
    for (char c : keys) {
        if (c == 'w' || c == 'a' || c == 'd' || c == 'i' || c == 'j'  || c == 'l')
            std::cout << "\033[32m" << c << "\033[0m"; // Green
        else
            std::cout << c;
    }
    std::cout << "\n";
    
    // return 0;
}
