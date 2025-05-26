#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm> // for std::shuffle
#include <map>
#include <random>    // for std::default_random_engine
using namespace std;

struct Vertex
{
    pair<int, int> coord;
    Vertex *p_left = nullptr;
    Vertex *p_right = nullptr;
    Vertex *p_up = nullptr;
    Vertex *p_down = nullptr;
    int w_left = 0, w_right = 0, w_up = 0, w_down = 0;

    Vertex(int x, int y)
    {
        coord = {x, y};
    }
};

// Peta 2D menggunakan map dari koordinat ke simbol
map<pair<int, int>, string> grid;
map<pair<int, int>, Vertex *> all_vertices;


// Fungsi pembantu untuk membuat bobot acak
int random_weight()
{
    return rand() % 3 + 1; // 1 hingga 3
}

// Fungsi pembantu untuk membuat arah acak
vector<string> random_directions()
{
     vector<string> dirs = {"left", "right", "up", "down"};
    static random_device rd;
    static default_random_engine rng(rd());
    shuffle(dirs.begin(), dirs.end(), rng);
    int count = rand() % 3 + 1; // Minimal 1, maksimal 4 arah
    return vector<string>(dirs.begin(), dirs.begin() + count);
}

// Menambahkan tetangga secara acak
void add_neighbors(Vertex *v)
{
    vector<string> directions = {"left", "right", "up", "down"};
    static random_device rd;
    static default_random_engine rng(rd());

    int connected = 0;
    int attempts = 0;

    // Coba sampai berhasil menambahkan minimal 2 arah atau telah mencoba terlalu banyak
    while (connected < 2 && attempts < 10)
    {
        vector<string> dirs = directions;
        shuffle(dirs.begin(), dirs.end(), rng);
        for (string dir : dirs)
        {
            int dx = 0, dy = 0, weight = random_weight();

            if (dir == "left" && v->coord.first - weight >= 0)
                dx = -weight;
            else if (dir == "right")
                dx = weight;
            else if (dir == "up" && v->coord.second - weight >= 0)
                dy = -weight;
            else if (dir == "down")
                dy = weight;
            else
                continue;

            pair<int, int> new_coord = {v->coord.first + dx, v->coord.second + dy};

            // Cegah koneksi ganda
            if (all_vertices.count(new_coord))
            {
                Vertex* neighbor = all_vertices[new_coord];
                // Jika sudah terhubung ke vertex ini dari arah ini, lewati
                if ((dir == "left" && v->p_left) || (dir == "right" && v->p_right) ||
                    (dir == "up" && v->p_up) || (dir == "down" && v->p_down))
                    continue;

                // Buat koneksi dua arah
                if (dir == "left")
                {
                    v->p_left = neighbor;
                    v->w_left = abs(dx);
                    neighbor->p_right = v;
                    neighbor->w_right = abs(dx);
                }
                else if (dir == "right")
                {
                    v->p_right = neighbor;
                    v->w_right = abs(dx);
                    neighbor->p_left = v;
                    neighbor->w_left = abs(dx);
                }
                else if (dir == "up")
                {
                    v->p_up = neighbor;
                    v->w_up = abs(dy);
                    neighbor->p_down = v;
                    neighbor->w_down = abs(dy);
                }
                else if (dir == "down")
                {
                    v->p_down = neighbor;
                    v->w_down = abs(dy);
                    neighbor->p_up = v;
                    neighbor->w_up = abs(dy);
                }

                connected++;
            }
            else
            {
                Vertex* neighbor = new Vertex(new_coord.first, new_coord.second);
                all_vertices[new_coord] = neighbor;

                if (dir == "left")
                {
                    v->p_left = neighbor;
                    v->w_left = abs(dx);
                    neighbor->p_right = v;
                    neighbor->w_right = abs(dx);
                }
                else if (dir == "right")
                {
                    v->p_right = neighbor;
                    v->w_right = abs(dx);
                    neighbor->p_left = v;
                    neighbor->w_left = abs(dx);
                }
                else if (dir == "up")
                {
                    v->p_up = neighbor;
                    v->w_up = abs(dy);
                    neighbor->p_down = v;
                    neighbor->w_down = abs(dy);
                }
                else if (dir == "down")
                {
                    v->p_down = neighbor;
                    v->w_down = abs(dy);
                    neighbor->p_up = v;
                    neighbor->w_up = abs(dy);
                }

                connected++;
            }

            if (connected >= 2)
                break;
        }
        attempts++;
    }
}


// Mengisi grid dengan simbol jalur
void fill_path(Vertex *from, Vertex *to)
{
    int x1 = from->coord.first;
    int y1 = from->coord.second;
    int x2 = to->coord.first;
    int y2 = to->coord.second;

    int dx = (x2 > x1) ? 1 : ((x2 < x1) ? -1 : 0);
    int dy = (y2 > y1) ? 1 : ((y2 < y1) ? -1 : 0);

    int x = x1, y = y1;
    while (x != x2 || y != y2)
    {
        if (!(x == x1 && y == y1))
        {
            if (grid[{x, y}] == "")
            {
                grid[{x, y}] = "⬜";
            }
            else
            {
                grid[{x, y}] = "🟩";
            }
        }
        if (x != x2)
            x += dx;
        else if (y != y2)
            y += dy;
    }
}

// Menelusuri vertex dan membuat jalur
void traverse_and_draw(Vertex *v)
{
    grid[v->coord] = "⬛";

    if (v->p_right)
    {
        fill_path(v, v->p_right);
        grid[v->p_right->coord] = "⬜";
    }
    if (v->p_down)
    {
        fill_path(v, v->p_down);
        grid[v->p_down->coord] = "⬜";
    }
    if (v->p_left)
    {
        fill_path(v, v->p_left);
        grid[v->p_left->coord] = "⬜";
    }
    if (v->p_up)
    {
        fill_path(v, v->p_up);
        grid[v->p_up->coord] = "⬜";
    }
}

// Menampilkan grid
void print_grid(int width, int height)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            pair<int, int> pos = {x, y};
            if (grid.count(pos))
            {
                cout << grid[pos];
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

int main()
{
    srand(time(0));
    Vertex *start = new Vertex(0, 0);
    all_vertices[{0, 0}] = start;

    add_neighbors(start);
    traverse_and_draw(start);

    for (auto &[coord, v] : all_vertices)
    {
        if (v != start)
        {
            add_neighbors(v);
            traverse_and_draw(v);
        }
    }

    print_grid(20, 20); // Ukuran grid bisa diubah

    return 0;
}
