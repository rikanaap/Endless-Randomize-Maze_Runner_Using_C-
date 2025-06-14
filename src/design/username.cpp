#include "package\package.hpp"
#include "main\utils.hpp"
#include "var\global.hpp"
#include "main\design.hpp"

void isiUsername(){
    clearScreen();
    char input;
    while(true){
        cout << "◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽" << endl;
        cout << "                          " << endl;
        cout << "               ⚡ FAST TYPING MODE ⚡" << endl;
        cout << "                          " << endl;
        cout << "◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽" << endl;
        cout << endl;
        cout << "                 😈 TULISKAN NAMA MU 😯" << endl;
        cout << endl;
        cout << "                 ▶️   " << currentUsername << "   " << endl; 
        cout << endl;
        cout << "◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽◾◽" << endl;
        cout << endl;
        cout << "📝 Tekan huruf keyboard untuk mengetik username" << endl;
        cout << "🏁 Tekan tombol enter untuk mulai...";
        input = getChar();
        if(input == '\r') break;
        if(input == 8){
            if (!currentUsername.empty())
                {
                    currentUsername.pop_back();
                    cout << "\b \b";
                }
        }else {
            currentUsername += ChartoFont(input);
        }
        clearScreen();
    }

}