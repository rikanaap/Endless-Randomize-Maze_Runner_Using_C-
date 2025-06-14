#include "package/package.hpp"
#include "var/global.hpp"

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
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error opening file for reading.\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string name, point;

        getline(ss, name, ',');
        getline(ss, point, ',');

        cout << "Name: " << name << ", Point: " << point;
    }

    file.close();
}