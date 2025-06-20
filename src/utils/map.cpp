#include "main\map.hpp"
#include "main\player.hpp"
#include "main\utils.hpp"
#include "main\enemy.hpp"
#include "var\global.hpp"

vector<vector<Vertex *>> initializeVertexMap(int rows, int cols)
{
    vector<vector<Vertex *>> map(rows, vector<Vertex *>(cols)); //? Looping row sama cols, ya intinya ngebuat array 2d yang tiap isinya struct Vertex
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
        {
            map[i][j] = new Vertex();
            map[i][j]->x = i;
            map[i][j]->y = j;
        }
    return map;
}

// void addNoise(int rows, int cols, int noiseCount)
// {
//     for (int n = 0; n < noiseCount; ++n)
//     {
//         int i = randomInt(0, rows - 1);
//         int j = randomInt(0, cols - 1);
//         Vertex *v = runningMap[i][j];

//         vector<Dir> possibleDirs;
//         for (auto &d : directions)
//         {
//             int ni = i + d.dx;
//             int nj = j + d.dy;
//             if (ni >= 0 && ni < rows && nj >= 0 && nj < cols)
//             {
//                 Vertex *neighbor = runningMap[ni][nj];
//                 bool connected = false;
//                 if (d.name == "up" && v->up == neighbor) connected = true;
//                 else if (d.name == "down" && v->down == neighbor) connected = true;
//                 else if (d.name == "left" && v->left == neighbor) connected = true;
//                 else if (d.name == "right" && v->right == neighbor) connected = true;

//                 if (!connected) possibleDirs.push_back(d);
//             }
//         }

//         if (!possibleDirs.empty())
//         {
//             Dir d = possibleDirs[randomInt(0, possibleDirs.size() - 1)];
//             Vertex *neighbor = runningMap[i + d.dx][j + d.dy];
//             int weight = 1;

//             if (d.name == "up")
//             {
//                 v->up = neighbor;
//                 v->weightUp = weight;
//                 neighbor->down = v;
//                 neighbor->weightDown = weight;
//             }
//             else if (d.name == "down")
//             {
//                 v->down = neighbor;
//                 v->weightDown = weight;
//                 neighbor->up = v;
//                 neighbor->weightUp = weight;
//             }
//             else if (d.name == "left")
//             {
//                 v->left = neighbor;
//                 v->weightLeft = weight;
//                 neighbor->right = v;
//                 neighbor->weightRight = weight;
//             }
//             else if (d.name == "right")
//             {
//                 v->right = neighbor;
//                 v->weightRight = weight;
//                 neighbor->left = v;
//                 neighbor->weightLeft = weight;
//             }
//         }
//     }
// }

void createPath(Vertex *current, Vertex *end, int rows, int cols)
{
    current->visited = true;
    if (current == end)
        return;

    vector<Dir> dirShuffled = directions;
    random_shuffle(dirShuffled.begin(), dirShuffled.end());

    for (auto &d : dirShuffled)
    {
        int nx = current->x + d.dx;
        int ny = current->y + d.dy;

        if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && !runningMap[nx][ny]->visited)
        {
            Vertex *neighbor = runningMap[nx][ny];
            int weight = 1;

            if (d.name == "up")
            {
                current->up = neighbor;
                current->weightUp = weight;
                neighbor->down = current;
                neighbor->weightDown = weight;
            }
            else if (d.name == "down")
            {
                current->down = neighbor;
                current->weightDown = weight;
                neighbor->up = current;
                neighbor->weightUp = weight;
            }
            else if (d.name == "left")
            {
                current->left = neighbor;
                current->weightLeft = weight;
                neighbor->right = current;
                neighbor->weightRight = weight;
            }
            else if (d.name == "right")
            {
                current->right = neighbor;
                current->weightRight = weight;
                neighbor->left = current;
                neighbor->weightLeft = weight;
            }

            createPath(neighbor, end, rows, cols);
            return;
        }
    }
}

void markConnected(Vertex *start)
{
    queue<Vertex *> q;
    q.push(start);
    start->connected = true;

    while (!q.empty())
    {
        Vertex *v = q.front();
        q.pop();

        vector<pair<Vertex *, int>> neighbors = {
            {v->up, v->weightUp},
            {v->down, v->weightDown},
            {v->left, v->weightLeft},
            {v->right, v->weightRight}};

        for (auto &[nbr, w] : neighbors)
        {
            if (nbr && w > 0 && !nbr->connected)
            {
                nbr->connected = true;
                q.push(nbr);
            }
        }
    }
}

void connectUnreachableVertices(int rows, int cols)
{
    bool progress = true;

    while (progress)
    {
        progress = false;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                Vertex *v = runningMap[i][j];
                if (v->connected)
                    continue;

                vector<Dir> neighborDirs;
                for (auto &d : directions)
                {
                    int ni = i + d.dx;
                    int nj = j + d.dy;
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && runningMap[ni][nj]->connected)
                        neighborDirs.push_back(d);
                }

                if (!neighborDirs.empty())
                {
                    Dir d = neighborDirs[randomInt(0, neighborDirs.size() - 1)];
                    Vertex *neighbor = runningMap[i + d.dx][j + d.dy];
                    int weight = 1;

                    if (d.name == "up")
                    {
                        v->up = neighbor;
                        v->weightUp = weight;
                        neighbor->down = v;
                        neighbor->weightDown = weight;
                    }
                    else if (d.name == "down")
                    {
                        v->down = neighbor;
                        v->weightDown = weight;
                        neighbor->up = v;
                        neighbor->weightUp = weight;
                    }
                    else if (d.name == "left")
                    {
                        v->left = neighbor;
                        v->weightLeft = weight;
                        neighbor->right = v;
                        neighbor->weightRight = weight;
                    }
                    else if (d.name == "right")
                    {
                        v->right = neighbor;
                        v->weightRight = weight;
                        neighbor->left = v;
                        neighbor->weightLeft = weight;
                    }

                    v->connected = true;
                    progress = true;
                }
            }
        }
    }
}

void filterUnreachableTiles(int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
        {
            Vertex *v = runningMap[i][j];
            if (!v->connected)
            {
                delete v;
                runningMap[i][j] = nullptr;
            }
        }
}

void updateWeightsByCoordinates(int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            Vertex *v = runningMap[i][j];
            if (!v)
                continue;

            if (v->up)
            {
                v->weightUp = (v->x - v->up->x) * 2;
                v->up->weightDown = v->weightUp;
            }
            if (v->down)
            {
                v->weightDown = (v->down->x - v->x) * 2;
                v->down->weightUp = v->weightDown;
            }
            if (v->left)
            {
                v->weightLeft = (v->y - v->left->y) * 4;
                v->left->weightRight = v->weightLeft;
            }
            if (v->right)
            {
                v->weightRight = (v->right->y - v->y) * 4;
                v->right->weightLeft = v->weightRight;
            }
        }
    }
}

void printMap()
{
    const vector<vector<Vertex *>> &map = runningMap;
    int rows = map.size();
    int cols = map[0].size();

    int visRows = rows * 2 - 1;
    int visCols = cols * 4 - 1;
    vector<vector<string>> visual(visRows, vector<string>(visCols, "⬛"));

    bool enemyValid = enemyPos.first >= 0 && enemyPos.second >= 0;

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
        {
            Vertex *v = map[i][j];
            if (!v)
                continue;

            int vi = i * 2;
            int vj = j * 4;

            visual[vi][vj] = "⬜";

            if (i == start_v->x && j == start_v->y)
                visual[vi][vj] = "🚪";

            if (i == end_v->x && j == end_v->y)
                visual[vi][vj] = "🏁";

            if (i == currentPos.first && j == currentPos.second)
                visual[vi][vj] = "😯";

            if (enemyValid && i == enemyPos.first && j == enemyPos.second)
                visual[vi][vj] = "😈";

            if (v->weightRight > 0)
                for (int w = 0; w < v->weightRight; ++w)
                    if (vj + w + 1 < visCols)
                        visual[vi][vj + w + 1] = "⬜";

            if (v->weightDown > 0)
                for (int w = 0; w < v->weightDown; ++w)
                    if (vi + w + 1 < visRows)
                        visual[vi + w + 1][vj] = "⬜";

            if (v->shoot == true)
                visual[vi][vj] = "🟥";
        }

    for (auto &row : visual)
    {
        for (auto &cell : row)
            cout << cell;
        cout << "\n";
    }
}

pair<Vertex *, Vertex *> getRandomStartAndEnd(int rows, int cols)
{
    do
    {
        int sx = randomInt(0, rows - 1);
        int sy = randomInt(0, cols - 1);
        int ex = randomInt(0, rows - 1);
        int ey = randomInt(0, cols - 1);

        if ((sx != ex || sy != ey) && runningMap[sx][sy] && runningMap[ex][ey])
        {
            start_v = runningMap[sx][sy];
            end_v = runningMap[ex][ey];
            runningMap[ex][ey]->endVertex = true;
        }
    } while (start_v == nullptr || end_v == nullptr);
    return {start_v, end_v};
}

vector<vector<Vertex *>> generateMap(int rows, int cols, int noise)
{
    srand(time(0));
    auto map = initializeVertexMap(rows, cols);
    runningMap = map;
    // addNoise(rows, cols, noise);

    auto [start, end] = getRandomStartAndEnd(rows, cols);
    currentPos = {start->x, start->y};
    enemyPos = randomizePosition(rows, cols);

    createPath(start, end, rows, cols);
    markConnected(start);
    connectUnreachableVertices(rows, cols);
    markConnected(start);
    filterUnreachableTiles(rows, cols);
    updateWeightsByCoordinates(rows, cols);
    printMap();

    return map;
}
