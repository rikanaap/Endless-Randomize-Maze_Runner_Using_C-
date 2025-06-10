#include "package\package.hpp"
#include "main\game.hpp"
#include "main\player.hpp"
#include "main\enemy.hpp"
#include "main\utils.hpp"

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
            if (c == '\r')
                break;  // Enter key
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
    cout << "Ketik kata ini: " << "\033[32m" << target << "\033[0m" << endl;;
    string userInput = getInputWithTimeout(second);

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
    moveEnemy(enemyMove);

    if(point > 0) cout << "🪙  Kamu mendapatkan " << point << " poin🍻🍻" << endl;
    if(enemyMove > 0) cout << "😈  Kesalahanmu adalah jalan ku, musuh mendekat " << enemyMove << " langkah🚶‍♂️🚶‍♂️";

    wait(3000);
}
