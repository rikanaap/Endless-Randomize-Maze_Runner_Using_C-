#ifndef STRUCT_HPP
#define STRUCT_HPP
#include "package\package.hpp"
#include "var\env.hpp"

struct Vertex
{
    int x, y;
    Vertex *up = nullptr;
    Vertex *down = nullptr;
    Vertex *left = nullptr;
    Vertex *right = nullptr;

    int weightUp = -1;
    int weightDown = -1;
    int weightLeft = -1;
    int weightRight = -1;

    bool visited = false; //TODO: CEK VISITED
    bool connected = false; //TODO: CEK VISITED
    
    bool endVertex = false; //? Ngejelasin kalau vertex yang sekarang itu adalah vertex terakhir
    bool shoot = false; 
};

struct GameConfig {
    bool fastTyping = false;
    bool acurracyTyping = false;
    int defaultPoint = 0;
};

struct Dir
{
    int dx, dy;
    string name;
};

struct enemyQueue
{
    int top = 0;
    char isi[15];
};

struct letterQueue {
    int top;
    char letters[MAX_CHAR_LENGTH];
};

#endif