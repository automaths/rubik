#include "../Cubos.hpp"

Cube::corner_names = {"URF", "UBR", "DLF", "DFR", "ULB", "UFL", "DRB", "DBL"};
Cube::edge_names = {"UF", "UR", "UB", "UL", "DF", "DR", "DB", "DL", "FR", "BR", "BL", "FL"};
Cube::face_names = {'u', 'r', 'f', 'd', 'l', 'b'};
Cube::face_corners = {{"URF", "UBR", "ULB", "UFL"}, {"URF", "UBR", "DFR", "DRB"}, {"URF", "DLF", "DFR", "UFL"}, {"DLF", "DFR", "DRB", "DBL"}, {"DLF", "ULB", "UFL", "DBL"}, {"UBR", "ULB", "DRB", "DBL"}};
Cube::face_edges = {{"UF", "UR", "UB", "UL"}, {"UR", "DR", "FR", "BR"}, {"UF", "DF", "FR", "FL"}, {"DF", "DR", "FR", "BR"}, {"UL", "DL", "BL", "FL"}, {"UB", "DB", "BR", "BL"}}

map<char, vector<string>> rot_corner_tabs;
map<char, vector<string>> rot_edge_tabs;

void Cube::apply_move(string move)
{
    char face = move[0];
    int direction = 1;
    
    if (move.size() > 1)
    {
        if (move[1] == '\'')
            direction = 3;
        else if (move[1] == '2')
            direction = 2;
    }
    rotate(face, direction);
}

void Cube::rotate(char faceid, int direction)
{
    direction = (direction + 4) % 4;

    vector<string> &rot_corners;
    vector<string> &rot_edges;

    for (int d = 0; d < direction; d++)
    {
        Corner tmp = corners[rot_corners[0]];
        corners[rot_corners[0]] = corners[rot_corners[1]];
        corners[rot_corners[1]] = corners[rot_corners[2]];
        corners[rot_corners[2]] = tmp;
        
        Edge tmp = edges[rot_edges[0]];
        edges[rot_edges[0]] = edges[rot_edges[1]];
        edges[rot_edges[1]] = edges[rot_edges[2]];
        edges[rot_edges[2]] = tmp;        
    }
}
