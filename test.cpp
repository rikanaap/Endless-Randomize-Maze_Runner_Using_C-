// #include <iostream>
// #include <map>
// #include <string>
// #include <vector>

// using namespace std;

// struct Vertex {
//     int x, y;
//     Vertex* p_right = nullptr;
//     Vertex* p_left = nullptr;
//     Vertex* p_up = nullptr;
//     Vertex* p_down = nullptr;

//     int w_right = 0;
//     int w_left = 0;
//     int w_up = 0;
//     int w_down = 0;

//     Vertex(int x_, int y_) : x(x_), y(y_) {}
// };

// map<pair<int,int>, Vertex*> graphNodes;

// const int WIDTH = 5;
// const int HEIGHT = 5;

// vector<vector<char>> grid(HEIGHT, vector<char>(WIDTH, ' '));  // Initially empty grid

// #ifdef _WIN32
// #include <windows.h>
// #endif

// void enableUnicodeOutput() {
// #ifdef _WIN32
//     // Set output mode to handle UTF-8 encoded text
//     SetConsoleOutputCP(CP_UTF8);
//     SetConsoleCP(CP_UTF8);
//     // Optional: Enable virtual terminal processing (for ANSI escape codes)
//     HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//     DWORD dwMode = 0;
//     GetConsoleMode(hOut, &dwMode);
//     dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
//     SetConsoleMode(hOut, dwMode);
// #endif
// }

// void initGrid() {
//     for (int i = 0; i < HEIGHT; ++i)
//         for (int j = 0; j < WIDTH; ++j)
//             grid[i][j] = ' ';  // empty initially
// }

// // Print grid with player position
// void printGrid(int px, int py) {
//     for (int i = 0; i < HEIGHT; ++i) {
//         for (int j = 0; j < WIDTH; ++j) {
//             if (i == py && j == px) cout << "P ";
//             else cout << grid[i][j] << ' ';
//         }
//         cout << '\n';
//     }
// }

// // Create graph nodes at some coordinates with edges
// void createGraph() {
//     for (int i = 0; i < HEIGHT; ++i) {
//         for (int j = 0; j < WIDTH; ++j) {
//             Vertex* v = new Vertex(j, i);
//             graphNodes[{j, i}] = v;
//             grid[i][j] = "⬛"; // Mark connected node as ⬛
//         }
//     }

//     for (int i = 0; i < HEIGHT; ++i) {
//         for (int j = 0; j < WIDTH; ++j) {
//             Vertex* v = graphNodes[{j, i}];

//             if (j + 1 < WIDTH) {
//                 v->p_right = graphNodes[{j + 1, i}];
//                 v->w_right = 1;
//             }
//             if (j - 1 >= 0 && !(j == 0 && i == 0)) {
//                 v->p_left = graphNodes[{j - 1, i}];
//                 v->w_left = 1;
//             }
//             if (i - 1 >= 0 && !(j == 0 && i == 0)) {
//                 v->p_up = graphNodes[{j, i - 1}];
//                 v->w_up = 1;
//             }
//             if (i + 1 < HEIGHT) {
//                 v->p_down = graphNodes[{j, i + 1}];
//                 v->w_down = 1;
//             }
//         }
//     }
// }

// bool canMove(int x, int y) {
//     if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) return false;
//     if (grid[y][x] != '⬛') return false;  // can only step on graph nodes
//     return true;
// }

// int main() {
//     initGrid();
//     createGraph();

//     int playerX = 0;
//     int playerY = 0;

//     string cmd;

//     while (true) {
//         enableUnicodeOutput();
//         printGrid(playerX, playerY);
//         cout << "Move (up/down/left/right/exit): ";
//         cin >> cmd;
//         int newX = playerX;
//         int newY = playerY;

//         if (cmd == "exit") break;
//         else if (cmd == "up") newY -= 1;
//         else if (cmd == "down") newY += 1;
//         else if (cmd == "left") newX -= 1;
//         else if (cmd == "right") newX += 1;
//         else {
//             cout << "Invalid command\n";
//             continue;
//         }

//         if (canMove(newX, newY)) {
//             playerX = newX;
//             playerY = newY;
//             cout << "Moved to (" << playerX << "," << playerY << ")\n";
//         } else {
//             cout << "Can't move there!\n";
//         }
//     }

//     // Clean graph memory
//     for (auto& p : graphNodes) delete p.second;

//     return 0;
// }
