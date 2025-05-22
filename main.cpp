#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <chrono>
#include <thread> // for sleep
#include <atomic>
#include <conio.h>

// using namespace std;

#ifdef _WIN32
#include <windows.h>
#endif

int WIDTH = 21;  // must be odd
int HEIGHT = 21; // must be odd

std::mt19937 rng(time(nullptr));
std::random_device rd;
std::vector<std::vector<char>> maze(HEIGHT, std::vector<char>(WIDTH, '#'));

struct Point
{
    int x, y;
};

Point start = {1, 1};
Point goal = {WIDTH - 2, HEIGHT - 2};

struct Direction
{
    int dx, dy;
};

const std::vector<Direction> directions = {{0, -2}, {2, 0}, {0, 2}, {-2, 0}};

int manhattanDistance(Point a, Point b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int makeOdd(int num)
{
    return (num % 2 == 0) ? num + 1 : num;
}

bool isValid(int x, int y)
{
    return x > 0 && x < WIDTH - 1 && y > 0 && y < HEIGHT - 1;
}

int rollDice()
{
    std::uniform_int_distribution<int> dist(1, 6);
    return dist(rng);
}

void rollDiceForDuration(int seconds)
{
    auto startTime = std::chrono::steady_clock::now();
    auto endTime = startTime + std::chrono::seconds(seconds);

    std::cout << "You have " << seconds << " seconds to roll the dice!\n";

    while (std::chrono::steady_clock::now() < endTime)
    {
        if (_kbhit())
        {
            char key = _getch();
            if (key == ' ')
            {
                int result = rollDice();
                std::cout << "🎲 You rolled a " << result << "!\n";
            }
        }

        // Optional: short sleep to prevent 100% CPU usage
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    std::cout << "⏰ Time's up! Dice roll window closed.\n";
}

class Enemy
{
public:
    Point position;
    std::chrono::steady_clock::time_point lastActionTime;
    std::atomic<bool> running{false};

    Enemy() {}

    Enemy(Point pos)
    {
        position = pos;
        std::chrono::steady_clock::time_point lastActionTime;
    }

    bool isFarFrom(Point a, int minDistance)
    {
        return manhattanDistance(position, a) >= minDistance;
    }

    static Enemy generate(const std::vector<std::vector<char>> &maze, Point start, Point goal, int minDistance = 10)
    {
        std::uniform_int_distribution<int> distX(1, WIDTH - 2);
        std::uniform_int_distribution<int> distY(1, HEIGHT - 2);

        while (true)
        {
            int x = distX(rng);
            int y = distY(rng);

            if (maze[y][x] == ' ')
            {
                Point candidate = {x, y};
                if (manhattanDistance(candidate, start) >= minDistance &&
                    manhattanDistance(candidate, goal) >= minDistance)
                {
                    return Enemy(candidate);
                }
            }
        }
    }

    void placeOnMaze(std::vector<std::vector<char>> &maze)
    {
        maze[position.y][position.x] = 'M';
    }

    void act()
    {
        std::cout << "Enemy at (" << position.x << "," << position.y << ") acted.\n";
        // Add logic for movement, pathfinding, etc. here.
    }

    void run()
    {
        running = true;
        lastActionTime = std::chrono::steady_clock::now();

        std::thread([this]()
                    {
            while (running)
            {
                std::this_thread::sleep_for(std::chrono::seconds(1));
                auto now = std::chrono::steady_clock::now();
                auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - lastActionTime).count();

                if (elapsed >= 5)
                {
                    act();
                    lastActionTime = now;
                }
            } })
            .detach(); // Detach allows it to run in background
    }

    void stop()
    {
        running = false;
    }
};

void dfs(int x, int y)
{
    maze[y][x] = ' ';
    std::vector<Direction> dirs = directions;
    shuffle(dirs.begin(), dirs.end(), rng);

    for (const auto &dir : dirs)
    {
        int nx = x + dir.dx;
        int ny = y + dir.dy;

        if (isValid(nx, ny) && maze[ny][nx] == '#')
        {
            maze[y + dir.dy / 2][x + dir.dx / 2] = ' ';
            dfs(nx, ny);
        }
    }
}

void addNoise(int amount)
{
    std::uniform_int_distribution<int> distX(1, WIDTH - 2);
    std::uniform_int_distribution<int> distY(1, HEIGHT - 2);
    int added = 0;

    while (added < amount)
    {
        int x = distX(rng);
        int y = distY(rng);
        if (maze[y][x] == '#')
        {
            maze[y][x] = ' ';
            ++added;
        }
    }
}

void randomizeMapSize(int &width, int &height, int minSize = 15, int maxSize = 51)
{
    std::uniform_int_distribution<int> dist(minSize, maxSize);
    width = makeOdd(dist(rng));
    height = makeOdd(dist(rng));
}

void printMaze()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    for (int y = 0; y < HEIGHT; ++y)
    {
        for (int x = 0; x < WIDTH; ++x)
        {
            char cell = maze[y][x];
            if (cell == '#')
                std::cout << "⬛"; // wall
            else if (cell == 'S')
                std::cout << "👾"; // start
            else if (cell == 'E')
                std::cout << "🏁"; // end
            else if (cell == 'M')
                std::cout << "👹"; // enemy
            else
                std::cout << "  "; // path
        }
        std::cout << '\n';
    }
}

int main()
{
    int i = 1;

    randomizeMapSize(WIDTH, HEIGHT, 10, 30);
    maze = std::vector<std::vector<char>>(HEIGHT, std::vector<char>(WIDTH, '#'));

    start = {1, 1};
    goal = {WIDTH - 2, HEIGHT - 2};

    dfs(1, 1);
    addNoise(30);
    maze[1][1] = 'S';
    maze[HEIGHT - 2][WIDTH - 2] = 'E';
    std::vector<Enemy> enemies;
    Enemy enemy = Enemy::generate(maze, start, goal, 5);
    enemy.placeOnMaze(maze);
    enemy.run(); // Start background thread    
    printMaze();
    
    rollDiceForDuration(20);
    enemy.stop();                                          // stop background thread

    i++;
    return 0;
}    
