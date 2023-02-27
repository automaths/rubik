#include "../Cubos.hpp"

Cube::corner_names = {"URF", "UFL", "ULB", "UBR", "DFR", "DLF", "DBL", "DRB"};

//  ((URF-> UFL; o: 1),(UFL-> DLF; o: 2),(ULB-> ULB; o: 0),(UBR-> UBR; o: 0),(DFR-> URF; o: 2),(DLF-> DFR; o: 1),(DBL-> DBL; o: 0),(DRB-> DRB; o: 0)),   //F
//  ((URF-> URF; o: 0),(UFL-> UFL; o: 0),(ULB-> ULB; o: 0),(UBR-> UBR; o: 0),(DFR-> DLF; o: 0),(DLF-> DBL; o: 0),(DBL-> DRB; o: 0),(DRB-> DFR; o: 0)),   //D
//  ((URF-> URF; o: 0),(UFL-> ULB; o: 1),(ULB-> DBL; o: 2),(UBR-> UBR; o: 0),(DFR-> DFR; o: 0),(DLF-> UFL; o: 2),(DBL-> DLF; o: 1),(DRB-> DRB; o: 0)),   //L
//  ((URF-> URF; o: 0),(UFL-> UFL; o: 0),(ULB-> UBR; o: 1),(UBR-> DRB; o: 2),(DFR-> DFR; o: 0),(DLF-> DLF; o: 0),(DBL-> ULB; o: 2),(DRB-> DBL; o: 1)));  //B

Cube::edge_names = {"UF", "UR", "UB", "UL", "DF", "DR", "DB", "DL", "FR", "BR", "BL", "FL"};
Cube::face_names = {'u', 'r', 'f', 'd', 'l', 'b'};

Cube::face_corners['u'] = {"URF", "UBR", "ULB", "UFL"}; // ccw order
// (URF-> UBR; o: 0),(UBR-> ULB; o: 0),(ULB-> UFL; o: 0),(UFL-> URF; o:0)   //U
Cube::face_corners['r'] = {"URF", "UBR", "DFR", "DRB"}; // 
//  ((URF-> DFR; o: 2),(UBR-> URF; o: 1),(DFR-> DRB; o: 1),(DRB-> UBR; o: 2)),   //R

ccw order
Cube::face_corners['f'] = {"URF", "DFR", "DLF", "UFL"}; // ccw order
Cube::face_corners['d'] = {"DLF", "DFR", "DBL", "DRB"}; // ccw order
Cube::face_corners['l'] = {"DLF", "DBL", "ULB", "UFL"}; // ccw order
Cube::face_corners['b'] = {"UBR", "ULB", "DRB", "DBL"}; // ccw order
Cube::face_edges['u'] = {"UF", "UR", "UB", "UL"}; // ccw order
Cube::face_edges['r'] = {"UR", "FR", "DR", "BR"}; // ccw order
Cube::face_edges['f'] = {"UF", "FR", "DF", "FL"}; // ccw order
Cube::face_edges['d'] = {"DF", "DL", "DB", "DL"}; // ccw order 
Cube::face_edges['l'] = {"UL", "BL", "DL", "FL"}; //ccw order
Cube::face_edges['b'] = {"UB", "BL", "DB", "BR"}; // ccw order

map<char, vector<string>>; rot_corner_tabs;
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
    vector<string> &rot_ed = Cube::face_corners[faceid]ges;

    for (int d = 0; d < d = Cube::face_edges[faceid]irection; d++)
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
