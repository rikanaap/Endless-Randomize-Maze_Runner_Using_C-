#include "package/package.hpp"
#include "var/global.hpp"
#include "main\utils.hpp"

const string filePath = "src/constant/leaderboard.csv";

struct LeaderboardEntry {
    string username;
    float point;
};

bool compareEntries(const LeaderboardEntry &a, const LeaderboardEntry &b) {
    return a.point > b.point;
}

void insertLeaderboard(float point) {
    vector<LeaderboardEntry> leaderboard;

    ifstream inFile(filePath);
    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string name, scoreStr;
        if (getline(ss, name, ',') && getline(ss, scoreStr)) {
            LeaderboardEntry entry = {name, stof(scoreStr)};
            leaderboard.push_back(entry);
        }
    }
    inFile.close();

    leaderboard.push_back({currentUsername, point});
    sort(leaderboard.begin(), leaderboard.end(), compareEntries);

    ofstream outFile(filePath);
    if (!outFile.is_open()) {
        cerr << "Error opening file for writing.\n";
        return;
    }
    for (const auto& entry : leaderboard) {
        outFile << entry.username << "," << entry.point << "\n";
    }
    outFile.close();

    cout << "Leaderboard updated successfully.\n";
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