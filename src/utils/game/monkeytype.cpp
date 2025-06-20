#include "var\env.hpp"
#include "main\utils.hpp"
#include "var\global.hpp"
#include "main\game.hpp"
#include "main\player.hpp"
#include "main\enemy.hpp"
#include "main\map.hpp"
#include "main\player.hpp"

void createQueue() {
    word.top = 0;
}

bool isCharEmpty() {
    return word.top == 0;
}

bool isCharFull() {
    return word.top >= MAX_CHAR_LENGTH;
}

void insertChar(char nilai) {
    if (!isCharFull()) {
        word.letters[word.top++] = nilai;
    }
}

void removeChar() {
    if (!isCharEmpty()) {
        for (int i = 1; i < word.top; i++) {
            word.letters[i - 1] = word.letters[i];
        }
        word.top--;
    }
}

char getFirstChar() {
    if (!isCharEmpty()) {
        return word.letters[0];
    }
    return '\0';
}

void resetQueue(const char* letters) {
    createQueue();
    for (int i = 0; letters[i] != '\0'; i++) {
        insertChar(letters[i]);
    }
}


int calculatePoints(int totalIncorrect, double duration_seconds) {
    double points = 10.0 - (totalIncorrect * 2.0) - max(0.0, (duration_seconds - 15.0) * 0.2);
    
    int finalPoints = max(0, (int)round(points));
    
    return finalPoints;
}

void runMonkeytype(char* selectedWord) {
    int totalIncorrect = 0;
    int totalChars = strlen(selectedWord);

    createQueue();
    resetQueue(selectedWord);

    cout << "Ketik kalimat ini: " << "\033[32m" << selectedWord << "\033[0m" << endl;
    cout << "\nTekan Enter jika sudah selesai mengetik";
    counting123();
    cout << "\n> ";

    auto start = high_resolution_clock::now();

    while (!isCharEmpty()) {
        char expected = getFirstChar();
        char input = _getch();

        if (input == '\r') {
        cout << "\nKamu menekan Enter untuk mengakhiri lebih awal.\n";
        break;
    }

        if (input == expected) {
            cout << "\033[32m" << input << "\033[0m";
            removeChar();
        } else {
            totalIncorrect++;
        }
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    double duration_seconds = duration.count() / 1000.0;

    int charCount = 0;
    for (int i = 0; selectedWord[i] != '\0'; ++i) {
        if (selectedWord[i] != ' ') {
            charCount++;
        }
    }

    int maxPoints;
    if (charCount < 20) maxPoints = 3;
    else if (charCount < 30) maxPoints = 5;
    else if (charCount < 40) maxPoints = 7;
    else maxPoints = 10;

    double typoPenalty = totalIncorrect * 0.7;
    double timePenalty = duration_seconds / 10.0;

    int points = maxPoints - round(typoPenalty + timePenalty);
    if (points < 0) points = 0;

    float enemyMove = (float)totalIncorrect / 2.0f;

    cout << "\n\nWaktu yang dibutuhkan: " << duration_seconds << " detik" << endl;
    if (totalIncorrect > 0) {
        cout << "Total typo: " << totalIncorrect << endl;
    }

    addPlayerPoint(points);
    addLeaderboardPoint(3 * points);
    if(enemyMove >= 1) moveEnemy(enemyMove, true);

    clearScreen();
    printMap();
    printTutorial();

    if (points > 0) {
        cout << "🪙  Kamu mendapatkan " << points << " poin 🍻🍻" << endl;
    }
    if (enemyMove > 0) {
        cout << "😈  Kesalahanmu adalah jalan ku, musuh mendekat " << enemyMove << " langkah🚶‍♂️🚶‍♂️" << endl;
    }

    wait(2000);
}
