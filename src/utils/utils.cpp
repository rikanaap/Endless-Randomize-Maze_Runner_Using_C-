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

string generateRandomWord() {
    ifstream file("src/constant/kata_baku.csv");
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

int estimatedSecond(const string& word){
    int wordCount = count(word.begin(), word.end(), ' ') + 1;
    return wordCount * 2;
}

pair<string, int> wordsConvert() {
    string selectedWords = generateRandomWord();
    int estimatedSeconds = estimatedSecond(selectedWords);
    return make_pair(selectedWords, estimatedSeconds);
}

string ChartoFont(char c) {
    switch (c) {
        case 'A': return "𝓐";
        case 'B': return "𝓑";
        case 'C': return "𝓒";
        case 'D': return "𝓓";
        case 'E': return "𝓔";
        case 'F': return "𝓕";
        case 'G': return "𝓖";
        case 'H': return "𝓗";
        case 'I': return "𝓘";
        case 'J': return "𝓙";
        case 'K': return "𝓚";
        case 'L': return "𝓛";
        case 'M': return "𝓜";
        case 'N': return "𝓝";
        case 'O': return "𝓞";
        case 'P': return "𝓟";
        case 'R': return "𝓡";
        case 'S': return "𝓢";
        case 'T': return "𝓣";
        case 'U': return "𝓤";
        case 'V': return "𝓥";
        case 'W': return "𝓦";
        case 'X': return "𝓧";
        case 'Y': return "𝓨";
        case 'Z': return "𝓩";
        default:  return string(1, c); // return the original char if not matched
    }
}
