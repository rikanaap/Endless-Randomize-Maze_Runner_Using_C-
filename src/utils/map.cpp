#include "map.hpp"
#include "utils.hpp"
#include "player.hpp"

vector<vector<Vertex *>> initializeVertexMap(int rows, int cols)
{
    vector<vector<Vertex *>> map(rows, vector<Vertex *>(cols));
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
        {
            map[i][j] = new Vertex();
            map[i][j]->x = i;
            map[i][j]->y = j;
        }
    return map;
}

void addNoise(vector<vector<Vertex *>> &map, int rows, int cols, int noiseCount)
{
    for (int n = 0; n < noiseCount; ++n)
    {
        int i = randomInt(0, rows - 1);
        int j = randomInt(0, cols - 1);
        Vertex *v = map[i][j];

        vector<Dir> possibleDirs;
        for (auto &d : directions)
        {
            int ni = i + d.dx;
            int nj = j + d.dy;
            if (ni >= 0 && ni < rows && nj >= 0 && nj < cols)
            {
                Vertex *nbr = map[ni][nj];
                bool connected = false;
                if (d.name == "up" && v->up == nbr)
                    connected = true;
                else if (d.name == "down" && v->down == nbr)
                    connected = true;
                else if (d.name == "left" && v->left == nbr)
                    connected = true;
                else if (d.name == "right" && v->right == nbr)
                    connected = true;

                if (!connected)
                    possibleDirs.push_back(d);
            }
        }

        if (!possibleDirs.empty())
        {
            Dir d = possibleDirs[randomInt(0, possibleDirs.size() - 1)];
            Vertex *nbr = map[i + d.dx][j + d.dy];
            int weight = 1;

            if (d.name == "up")
            {
                v->up = nbr;
                v->weightUp = weight;
                nbr->down = v;
                nbr->weightDown = weight;
            }
            else if (d.name == "down")
            {
                v->down = nbr;
                v->weightDown = weight;
                nbr->up = v;
                nbr->weightUp = weight;
            }
            else if (d.name == "left")
            {
                v->left = nbr;
                v->weightLeft = weight;
                nbr->right = v;
                nbr->weightRight = weight;
            }
            else if (d.name == "right")
            {
                v->right = nbr;
                v->weightRight = weight;
                nbr->left = v;
                nbr->weightLeft = weight;
            }
        }
    }
}

void createPath(Vertex *current, Vertex *end, vector<vector<Vertex *>> &map, int rows, int cols)
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

        if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && !map[nx][ny]->visited)
        {
            Vertex *neighbor = map[nx][ny];
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

            createPath(neighbor, end, map, rows, cols);
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

void connectUnreachableVertices(vector<vector<Vertex *>> &map, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
        {
            Vertex *v = map[i][j];
            if (v->connected)
                continue;

            vector<Dir> neighborDirs;
            for (auto &d : directions)
            {
                int ni = i + d.dx;
                int nj = j + d.dy;
                if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && map[ni][nj]->connected)
                    neighborDirs.push_back(d);
            }

            if (!neighborDirs.empty())
            {
                Dir d = neighborDirs[randomInt(0, neighborDirs.size() - 1)];
                Vertex *neighbor = map[i + d.dx][j + d.dy];
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
            }
        }
}

void updateWeightsByCoordinates(vector<vector<Vertex *>> &map, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            Vertex *v = map[i][j];

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

void printMap(const vector<vector<Vertex *>> &map)
{
    int rows = map.size();
    int cols = map[0].size();

    int visRows = rows * 4 - 1;
    int visCols = cols * 4 - 1;
    vector<vector<string>> visual(visRows, vector<string>(visCols, "⬛"));

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
        {
            Vertex *v = map[i][j];
            int vi = i * 4;
            int vj = j * 4;

            // Default node
            visual[vi][vj] = "🟩";

            // Start & End
            if ((i == start_v->x && j == start_v->y))
                visual[vi][vj] = "🚪";
            
            if ((i == end_v->x && j == end_v->y))
                visual[vi][vj] = "🏁";

            // Player position
            if (i == currentPos.first && j == currentPos.second)
                visual[vi][vj] = "😯";
            
            // Enemy position
            if (i == enemyPos.first && j == enemyPos.second)
                visual[vi][vj] = "😈";

            if (v->weightRight > 0)
            {
                for (int w = 0; w < v->weightRight; ++w)
                {
                    int pos = vj + w + 1;
                    if (pos < visCols)
                        visual[vi][pos] = v->right ? "⬜" : "⬜";
                }
            }

            if (v->weightDown > 0)
            {
                for (int w = 0; w < v->weightDown; ++w)
                {
                    int pos = vi + w + 1;
                    if (pos < visRows)
                        visual[pos][vj] = v->down ? "⬜" : "⬜";
                }
            }
            if (v->shoot == true)
            {
                 visual[vi][vj] = " 🟥 ";
            }
            
        }

    for (auto &row : visual)
    {
        for (auto &cell : row)
            cout << cell;
        cout << "\n";
    }
}

void printAllVertexConnections(const vector<vector<Vertex *>> &map)
{
    cout << "=== Vertex Connection Details ===\n";
    for (size_t i = 0; i < map.size(); ++i)
    {
        for (size_t j = 0; j < map[0].size(); ++j)
        {
            Vertex *v = map[i][j];
            cout << "Vertex (" << v->x << ", " << v->y << "):\n";

            cout << "  Up: ";
            if (v->up)
                cout << "(" << v->up->x << ", " << v->up->y << ") with weight " << v->weightUp << "\n";
            else
                cout << "None\n";

            cout << "  Down: ";
            if (v->down)
                cout << "(" << v->down->x << ", " << v->down->y << ") with weight " << v->weightDown << "\n";
            else
                cout << "None\n";

            cout << "  Left: ";
            if (v->left)
                cout << "(" << v->left->x << ", " << v->left->y << ") with weight " << v->weightLeft << "\n";
            else
                cout << "None\n";

            cout << "  Right: ";
            if (v->right)
                cout << "(" << v->right->x << ", " << v->right->y << ") with weight " << v->weightRight << "\n";
            else
                cout << "None\n";

            cout << "-----------------------------\n";
        }
    }
}

pair<Vertex *, Vertex *> getRandomStartAndEnd(const vector<vector<Vertex *>> &map, int rows, int cols)
{
    do
    {
        int sx = randomInt(0, rows - 1);
        int sy = randomInt(0, cols - 1);
        int ex = randomInt(0, rows - 1);
        int ey = randomInt(0, cols - 1);
        if (sx != ex || sy != ey)
        {
            start_v = map[sx][sy];
            end_v = map[ex][ey];
            map[ex][ey]->endVertex = true;
        }
    } while (start_v == nullptr || end_v == nullptr);
    return {start_v, end_v};
}

vector<vector<Vertex *>> generateMap(int rows, int cols, int noise)
{
    srand(time(0));
    auto map = initializeVertexMap(rows, cols);
    addNoise(map, rows, cols, noise);

    auto [start, end] = getRandomStartAndEnd(map, rows, cols);
    currentPos = {start->x, start->y};

    createPath(start, end, map, rows, cols);
    markConnected(start);
    connectUnreachableVertices(map, rows, cols);
    updateWeightsByCoordinates(map, rows, cols);

    printMap(map);

    return map;
}