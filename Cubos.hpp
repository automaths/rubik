#ifndef CUBE_HPP
#define CUBE_HPP

# include <map>
# include <string>
# include <vector>

using namespace std;

class Corner {
public:
    string name;
    int orientation;

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
    
    Edge(string str)
    {
        name = str;
        orientation = 0;
    }
    Edge& operator=(Edge const &other)
    {
        name = other.name;
        return *this;
    }
};


class Cube
{
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
    void rotate(char faceid, int direction);
    void apply_move(string move);
    vector<int> get_face(char faiceid);
};

#endif