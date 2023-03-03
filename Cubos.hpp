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

#include <string>
#include <vector>
#include <list>
#include <map>
#include <iostream>

using namespace std;

class Cube;
int print_ascii_rubik(Cube &rk);
vector<string> astar_for_cross(Cube& cube);
bool algo_checker(std::string (Cube::*tostr)(), map<string, string> algos);
string formula_cleaner(string formula);


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
static map<char, vector<string> > face_corners;
static map<char, vector<string> > face_edges;
static map<string, string> corner_names_after_ymove;
static map<string, string> edge_names_after_ymove;
static map<string, string> algo_2FL;
static map<string, string> algo_OLL;
static map<string, string> algo_PLL;
static void init_members();
static void init_2FL();
static void init_OLL();
static void init_PLL();
static string res_moves;

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
    void apply_moves(string moves);
    void y();
    vector<int> get_face(char faceid);
    vector<int> get_facelets();

    void shuffle(int n = 100000);
    bool is_cross();
    string to_string_forcross(); // fonction pour pouvoir hasher un etat dans la recherche de la premiere step
    string to_string_2FL(); // fonction pour pouvoir hasher un etat dans la recherche de la deuxieme step
    string to_string_OLL(); // fonction pour pouvoir hasher un etat dans la recherche de la troisieme step
    string to_string_PLL(); // fonction pour pouvoir hasher un etat dans la recherche de la quatrieme step
    void one_corner_2FL();
    void solve_2FL();
    void solve_2FL_v2();
    void solve_OLL();
    void solve_PLL();
};

class SearchCube {
public:
    Cube cube;
    vector<string> moves;
    int distance;

    SearchCube(Cube& cube, vector<string> moves)
    {
        this->cube = cube;
        this->moves = moves;
        this->distance = 8;
        for (string edge : Cube::edge_names)
        {
            if (edge[0] == 'D' && cube.edges[edge].orientation == 0 && cube.edges[edge].name == edge)
                this->distance -= 2;
        }
    }

    bool operator<(const SearchCube& other) const
    {
        return distance + moves.size() > other.distance + other.moves.size();
    }

};

#endif