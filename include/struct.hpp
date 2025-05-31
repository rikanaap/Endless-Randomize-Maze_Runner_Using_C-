#ifndef STRUCT_HPP
#define STRUCT_HPP
#include "package.hpp"

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

    bool visited = false;
    bool connected = false; // untuk flood fill
    
    bool endVertex = false;
    bool shoot = false;
};

struct Map {
    vector<vector<Vertex*>> map;
    Vertex* start, end;
};

struct Dir
{
    int dx, dy;
    string name;
};


#endif