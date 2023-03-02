#ifndef CUBE_HPP
#define CUBE_HPP

#include <map>
#include <string>

using namespace std;

class Corner {
public:
    int stickers[3];
    int orientation;

    Corner(int a, int b, int c)
    {
        stickers[0] = a;
        stickers[1] = b;
        stickers[2] = c;
        orientation = 0;
    }
    Corner& operator=(Corner &other)
    {
        stickers[0] = other.stickers[0];
        stickers[1] = other.stickers[1];
        stickers[2] = other.stickers[2];
    }
};

class Edge {
public:
    int stickers[2];
    int orientation;
    
    Edge(int a, int b)
    {
        stickers[0] = a;
        stickers[1] = b;
        orientation = 0;
    }
    Edge& operator=(Edge &other)
    {
        stickers[0] = other.stickers[0];
        stickers[1] = other.stickers[1];
    }
};




class Cube
{
public:
    map<string, Corner>dgescorners;

    Cube()
    {

    }
    map<string, Edge> e;
// 
    // Corner cPos[8] = {urf, ubr, dlf, dfr, ulb, ufl, drb, dbl};
    edge ePos[12] = {uf, ur, ub, ul, df, dr, db, dl, fr, br, bl, fl};
}

#endif