#include "map.hpp"
using namespace std;

pair<int, int> parseCoord(const string& str) {
    if (str.size() != 2) throw invalid_argument("Invalid coord: " + str);
    return {str[0] - '0', str[1] - '0'};
}

vector<vector<char>> createMaze(const string& key) {
    auto parts = split(key, '|');
    if (parts.size() != 3) throw invalid_argument("Key must have 3 parts separated by '|'");

    // Part 0: Maze layout
    vector<string> mazeRows = split(parts[0], '_');
    int rows = mazeRows.size();
    int cols = mazeRows[0].size();
    vector<vector<char>> maze(rows, vector<char>(cols));

    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x) {
            maze[y][x] = (mazeRows[y][x] == '1') ? '#' : ' ';
        }
    }

    // Part 1: Start and End
    auto positions = split(parts[1], '_');
    if (positions.size() != 2) throw invalid_argument("Start/End must have 2 positions");

    auto [sy, sx] = parseCoord(positions[0]);
    auto [ey, ex] = parseCoord(positions[1]);

    maze[sy][sx] = 'A'; // Start
    maze[ey][ex] = 'E'; // End

    // Part 2: Enemy
    auto [eym, exm] = parseCoord(parts[2]);
    if (maze[eym][exm] == 'A' || maze[eym][exm] == 'B') maze[eym][exm] = 'S';
    else maze[eym][exm] = 'S';

    return maze;
}

void printMaze(const vector<vector<char>>& maze) {
    for (const auto& row : maze) {
        for (char cell : row) cout << cell << ' ';
        cout << endl;
    }
}
