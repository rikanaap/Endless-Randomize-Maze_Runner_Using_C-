#include "package/package.hpp"
#include "var/global.hpp"
#include "main\utils.hpp"

const string filePath = "src/constant/leaderboard.csv";

void insertLeaderboard(float point) {
    ofstream file(filePath, ios::app);
    if (!file.is_open()) {
        cerr << "Error opening file for writing.\n";
        return;
    }

    file << currentUsername << "," << point << "\n";
    file.close();
    cout << "Data inserted successfully.\n";
}

void readLeaderboard() {
    clearScreen();
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error opening file for reading.\n";
        return;
    }

    string line;
    int rank = 1;

    // Header
    cout << left << setw(5) << "No"
         << setw(30) << "Nama"
         << "Skor" << endl;
    cout << string(45, '-') << endl;

    while (getline(file, line)) {
        stringstream ss(line);
        string name, point;

        getline(ss, name, ',');
        getline(ss, point, ',');

        cout << left << setw(5) << rank++
             << setw(30) << name << " | "<< point << endl;
    }

    file.close();
    getChar();
    clearScreen();
}