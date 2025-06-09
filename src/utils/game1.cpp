#include "package\package.hpp"
#include "main\game.hpp"
#include "main\player.hpp"
#include "main\enemy.hpp"

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
    cout << "aku saya mandi atas kaki tanga hitam" << endl;
    cout << "You have " << seconds << " seconds to type:\n> ";
    DWORD start = GetTickCount();

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

    cout << "\n⏰ Time's up!\n";
    return input;
}

void fastTyping(string target)
{
    string userInput = getInputWithTimeout(4);

    vector<string> targetWords = splitWords(target);
    vector<string> userWords = splitWords(userInput);

    int playerPoint = 0;
    float enemyMove = 0;

    int len = min(targetWords.size(), userWords.size());

    for (int i = 0; i < len; ++i)
    {
        if (targetWords[i] == userWords[i])
        {
            playerPoint += 1;
        }
        else
        {
            cout << "'" + targetWords[i] + "'" << "'" + userWords[i] + "'";
            enemyMove += 1;
        }
    }

    enemyMove = enemyMove / 2;
    addPlayerPoint(playerPoint);
    // moveEnemy( )
}
