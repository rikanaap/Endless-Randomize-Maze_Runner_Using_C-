#include "package\package.hpp"
#include "main\utils.hpp"

std::vector<std::string> split(const std::string &s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream ss(s);
    while (getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

void clearScreen()
{
    // ANSI escape code to clear screen and move cursor to top-left
    std::cout << "\033[2J\033[1;1H";
}

char getChar()
{
    return _getch(); // instantly reads keypress without Enter
}

int randomInt(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void wait(int seconds) {
    this_thread::sleep_for(std::chrono::milliseconds(seconds));
}

void counting123(){
    cout << "1"; wait(100); cout << "."; wait(100); cout << "."; wait(100); cout << ". " ;
    cout << "2"; wait(100); cout << "."; wait(100); cout << "."; wait(100); cout << ". " ;
    cout << "3"; wait(100); cout << "."; wait(100); cout << "."; wait(100); cout << ". " ;
}

string ambilKataGabungan(const string& namaFile) {
    ifstream file(namaFile);
    vector<string> daftarKata;
    string kata;

    while (getline(file, kata)) {
        if (!kata.empty()) {
            daftarKata.push_back(kata);
        }
    }

    if (daftarKata.size() < 8) {
        throw runtime_error("File harus mengandung minimal 8 kata.");
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distJumlah(3, 8);
    int jumlahKata = distJumlah(gen);

    uniform_int_distribution<> distIndex(0, daftarKata.size() - 1);

    string hasil;
    for (int i = 0; i < jumlahKata; ++i) {
        int idx = distIndex(gen);               
        hasil += daftarKata[idx];  
        if (i < jumlahKata - 1) hasil += " ";
    }

    return hasil;
}