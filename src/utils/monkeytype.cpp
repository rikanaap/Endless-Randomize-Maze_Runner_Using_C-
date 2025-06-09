#include "env.hpp"
#include "utils.hpp"
#include "global.hpp"
#include "monkeytype.hpp"

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

void runMonkeytype(char* selectedWord) {
    int totalIncorrect = 0;
    createQueue();
    resetQueue(selectedWord);

    cout << "Type the word: " << selectedWord << endl;

    while (!isCharEmpty()) {
        char expected = getFirstChar();
        char input = _getch();
        cout << input;

        if (input == expected) {
            removeChar();
        } else {
            cout << "\nSalah ketik! Ulangi dari awal.\n";
            totalIncorrect++;
            resetQueue(selectedWord);
        }
    }

    cout << "\nKata berhasil diketik dengan benar!" << endl;
    if (totalIncorrect > 0) { cout << "Total salah ketik: " << totalIncorrect << endl; }

    // return totalIncorrect; // preparasi buat sistem poin
}