#include "env.hpp"
#include "utils.hpp"
#include "global.hpp"
#include "monkeytype.hpp"

void createQueue() {
    word.top = 0;
}

bool isEmpty() {
    return word.top == 0;
}

bool isFull() {
    return word.top >= MAX_CHAR_LENGTH;
}

void insertChar(char nilai) {
    if (!isFull()) {
        word.letters[word.top++] = nilai;
    }
}

void removeChar() {
    if (!isEmpty()) {
        for (int i = 1; i < word.top; i++) {
            word.letters[i - 1] = word.letters[i];
        }
        word.top--;
    }
}

char getFirstChar() {
    if (!isEmpty()) {
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

void runMonkeytype(){
    const char* target = "monkey";
    createQueue();
    resetQueue(target);

    cout << "Ketik kata ini: " << target << endl;

    while (!isEmpty()) {
        char expected = getFirstChar();
        char input = _getch();
        cout << input;

        if (input == expected) {
            removeChar();
        } else {
            cout << "\nSalah ketik! Ulangi dari awal.\n";
            resetQueue(target);
        }
    }

    cout << "\nKata berhasil diketik dengan benar!\n";
    return 0;
}