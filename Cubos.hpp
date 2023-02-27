#ifndef CUBE_HPP
#define CUBE_HPP

#define R1 0
#define R2 1
#define R3 2
#define R4 3
#define R5 4
#define R6 5
#define R7 6
#define R8 7
#define R9 8

#define D1 9
#define D2 10
#define D3 11
#define D4 12
#define D5 13
#define D6 14
#define D7 15
#define D8 16
#define D9 17

#define F1 18
#define F2 19
#define F3 20
#define F4 21
#define F5 22
#define F6 23
#define F7 24
#define F8 25
#define F9 26

#define U1 27
#define U2 28
#define U3 29
#define U4 30
#define U5 31
#define U6 32
#define U7 33
#define U8 34
#define U9 35

#define L1 36
#define L2 37
#define L3 38
#define L4 39
#define L5 40
#define L6 41
#define L7 42
#define L8 43
#define L9 44

#define B1 45
#define B2 46
#define B3 47
#define B4 48
#define B5 49
#define B6 50
#define B7 51
#define B8 52
#define B9 53

using namespace std;

#include <string>
#include <vector>
#include <map>
#include <iostream>

class Cube;
int print_ascii_rubik(Cube &rk);

class Corner {
public:
    string name;
    int orientation;

    Corner(){}
    Corner(string str)
    {
        name = str;
        orientation = 0;
    }
    Corner& operator=(Corner const &other)
    {
        name = other.name;
        orientation = other.orientation;
        return *this;
    }
};

class Edge {
public:
    string name;
    int orientation;
    
    Edge(){}
    Edge(string str)
    {
        name = str;
        orientation = 0;
    }
    Edge& operator=(Edge const &other)
    {
        name = other.name;
        orientation = other.orientation;
        return *this;
    }
};


class Cube
{
public:
const static string corner_names[8];
const static string edge_names[12];
const static char face_names[6];
// const static string face_corners[4][6];
// const static string face_edges[4][6];

static map<char, vector<string> > face_corners;
static map<char, vector<string> > face_edges;
static void init_members();

public:
    map<string, Corner> corners;
    map<string, Edge> edges;

    Cube()
    {
        for (int i = 0; i < 8; ++i)
            corners[corner_names[i]] = Corner(corner_names[i]);
        for (int i = 0; i < 12; ++i)
            edges[edge_names[i]] = Edge(edge_names[i]);
    }
    void rotate(char faceid, int direction = 1);
    void apply_move(string move);
    vector<int> get_face(char faceid);
    vector<int> get_facelets();

    bool is_cross();
    string to_string_forcross(); // fonction pour pouvoir hasher un etat dans la recherche de la premiere step
};

#endif