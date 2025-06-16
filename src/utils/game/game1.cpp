#include "package\package.hpp"
#include "main\game.hpp"
#include "main\player.hpp"
#include "main\enemy.hpp"
#include "main\utils.hpp"
#include "main\map.hpp"

using namespace std;

// Split sentence by space into words
vector<string> splitWords(const string &sentence)
{
    vector<string> words;
    stringstream ss(sentence);
    string word;
    while (ss >> word)
    {
        for (char &c : word)
        {
            c = tolower(static_cast<unsigned char>(c));
        }
        words.push_back(word);
    }
    return words;
}

// Get user input with timeout (3 seconds)
string getInputWithTimeout(int seconds)
{
    string input;
    cout << "Kamu punya " << "\033[32m" << seconds << "\033[0m" << " detik untuk mengetik:" << endl; counting123();
    DWORD start = GetTickCount();
    
    cout << "\n> ";
    while ((GetTickCount() - start) < (seconds * 1000))
    {
        if (_kbhit())
        {
            char c = _getch();
            if (c == '\r') break; 
            if (c == 8) // Backspace pressed
            {
                if (!input.empty())
                {
                    input.pop_back();
                    cout << "\b \b";
                }
            }
            else
            {
                cout << c;
                input += c;
            }
        }
    }

    cout << "\n⏰ Waktu selesai....!\n";
    return input;
}

void fastTyping(string target, int second)
{
    cout << "Ketik kata ini: " << "\033[32m" << target << "\033[0m" << endl;

    auto startTime = high_resolution_clock::now();
    string userInput = getInputWithTimeout(second);
    auto endTime = high_resolution_clock::now();

    vector<string> targetWords = splitWords(target);
    vector<string> userWords = splitWords(userInput);

    int point = 0;
    float enemyMove = 0;

    int len = min(targetWords.size(), userWords.size());

    for (int i = 0; i < len; ++i)
    {
        if (targetWords[i] == userWords[i]) point++;
        else enemyMove += 1;
    }

    enemyMove = enemyMove / 2;

    addPlayerPoint(point);
    addLeaderboardPoint(2 * point);
    if(enemyMove >= 1) moveEnemy(enemyMove, true);

    clearScreen();
    printMap();

    if(point > 0)
        cout << endl << "🪙  Kamu mendapatkan " << point << " poin🍻🍻" << endl;
    if(enemyMove > 0)
        cout << endl << "😈  Kesalahanmu adalah jalan ku, musuh mendekat " << enemyMove << " langkah🚶‍♂️🚶‍♂️";

    auto duration = duration_cast<milliseconds>(endTime - startTime);
    cout << endl << "⏱️  Waktu yang kamu butuhkan: " << (duration.count() / 1000.0) << " detik" << endl;

    DWORD start = GetTickCount();
    while ((GetTickCount() - start) < (4 * 1000))
    {
        if (_kbhit()) _getch();
    }
}
