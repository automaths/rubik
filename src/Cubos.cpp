#include "../Cubos.hpp"

Cube::corner_names = {"URF", "UFL", "ULB", "UBR", "DFR", "DLF", "DBL", "DRB"};


Cube::edge_names = {"UR", "UF", "UL", "UB", "DR", "DF", "DL", "DB", "FR", "FL", "BL", "BR"};

Cube::face_names = {'u', 'r', 'f', 'd', 'l', 'b'};

// patern 0 0 0 0
Cube::face_corners['u'] = {"URF", "UBR",  "ULB", "UFL"}; // ccw
// (URF-> UBR; o: 0),(UBR-> ULB; o: 0),(ULB-> UFL; o: 0),(UFL-> URF; o:0)   //U
Cube::face_corners['d'] = {"DFR", "DLF", "DBL", "DRB"}; // ccw
//  (DFR-> DLF; o: 0), (DLF-> DBL; o: 0), (DBL-> DRB; o: 0), (DRB-> DFR; o: 0)   //D

// pattern 1 2 1 2
Cube::face_corners['r'] = {"DFR", "DRB", "UBR", "URF"}; // ccw
// (DFR-> DRB; o: 1),(DRB-> UBR; o: 2), (UBR-> URF; o: 1), (URF-> DFR; o: 2)   //R
Cube::face_corners['f'] = {"URF", "UFL", "DLF", "DFR"}; // ccw
//  (URF-> UFL; o: 1), (UFL-> DLF; o: 2), (DLF-> DFR; o: 1), (DFR-> URF; o: 2)   //F
Cube::face_corners['l'] = {"UFL", "ULB", "DBL", "DLF"}; // ccw
//  (UFL-> ULB; o: 1), (ULB-> DBL; o: 2), (DBL-> DLF; o: 1), (DLF-> UFL; o: 2),   //L
Cube::face_corners['b'] = {"ULB", "UBR", "DRB", "DBL"}; // ccw
//  ((ULB-> UBR; o: 1), (UBR-> DRB; o: 2), (DRB-> DBL; o: 1), (DBL-> ULB; o: 2)));  //B


((e:UB;o:0;oA:1),(e:UR;o:0;oA:1),(e:UF;o:0;oA:1),(e:UL;o:0;oA:1),(e:DR;o:0;oA:0),(e:DF;o:0;oA:0), //U 
(e:DL;o:0;oA:0),(e:DB;o:0;oA:0),(e:FR;o:0;oA:0),(e:FL;o:0;oA:0),(e:BL;o:0;oA:0),(e:BR;o:0;oA:0)), ((e:FR;o:0;oA:1),(e:UF;o:0;oA:0),(e:UL;o:0;oA:0),(e:UB;o:0;oA:0),(e:BR;o:0;oA:1),(e:DF;o:0;oA:0), //R 
(e:DL;o:0;oA:0),(e:DB;o:0;oA:0),(e:DR;o:0;oA:1),(e:FL;o:0;oA:0),(e:BL;o:0;oA:0),(e:UR;o:0;oA:1)), ((e:UR;o:0;oA:0),(e:FL;o:1;oA:1),(e:UL;o:0;oA:0),(e:UB;o:0;oA:0),(e:DR;o:0;oA:0),(e:FR;o:1;oA:1), //F 
(e:DL;o:0;oA:0),(e:DB;o:0;oA:0),(e:UF;o:1;oA:1),(e:DF;o:1;oA:1),(e:BL;o:0;oA:0),(e:BR;o:0;oA:0)), ((e:UR;o:0;oA:0),(e:UF;o:0;oA:0),(e:UL;o:0;oA:0),(e:UB;o:0;oA:0),(e:DF;o:0;oA:1),(e:DL;o:0;oA:1), //D 
(e:DB;o:0;oA:1),(e:DR;o:0;oA:1),(e:FR;o:0;oA:0),(e:FL;o:0;oA:0),(e:BL;o:0;oA:0),(e:BR;o:0;oA:0)), ((e:UR;o:0;oA:0),(e:UF;o:0;oA:0),(e:BL;o:0;oA:1),(e:UB;o:0;oA:0),(e:DR;o:0;oA:0),(e:DF;o:0;oA:0), //L 
(e:FL;o:0;oA:1),(e:DB;o:0;oA:0),(e:FR;o:0;oA:0),(e:UL;o:0;oA:1),(e:DL;o:0;oA:1),(e:BR;o:0;oA:0)), ((e:UR;o:0;oA:0),(e:UF;o:0;oA:0),(e:UL;o:0;oA:0),(e:BR;o:1;oA:1),(e:DR;o:0;oA:0),(e:DF;o:0;oA:0), //B 
(e:DL;o:0;oA:0),(e:BL;o:1;oA:1),(e:FR;o:0;oA:0),(e:FL;o:0;oA:0),(e:UB;o:1;oA:1),(e:DB;o:1;oA:1))

(UR->DL;o:0;),(UF->DB;o:0;),(UL->FR;o:0;),(UB->FL;o:0;),(DR->BL;o:0;),(DF->BR;o:0;), (DL->FR;o:0;),(DB->UF;o:0;),(FR->UL;o:0;),(FL->UB;o:0;),(BL->BR;o:0;),(BR->DF;o:0;), //R 

Cube::face_edges['r'] = {"BR", "DR", "FR", "UR"}; // ccw order
(UR->DL;o:0),(UF->DB;o:0),(UL->DR;o:0),(UB->FL;o:0),(DR->BL;o:0),(DF->UR;o:0), (DL->UR;o:0),(DB->FL;o:1),(FR->UL;o:0),(FL->UB;o:0),(BL->DR;o:0),(BR->FR;o:1) //F 

Cube::face_edges['f'] = {"FL", "DF", "FR", "UF"}; // ccw order
(UR->DL;o:0;),(UF->DB;o:0;),(UL->DR;o:0;),(UB->FL;o:0;),(DR->BL;o:0;),(DF->UR;o:0;), (DL->UR;o:0;),(DB->FL;o:1;),(FR->UL;o:0;),(FL->UB;o:0;),(BL->DR;o:0;),(BR->FR;o:1;), //F 

Cube::face_edges['d'] = {"DL", "DB", "DL", "DF"}; // ccw order
Cube::edge_names = {"UR", "UF", "UL", "UB", "DR", "DF", "DL", "DB", "FR", "FL", "BL", "BR"};
(DL;o:0;),(DB;o:0;),(UF;o:1;),(DF;o:1;),(BL;o:0;),(BR;o:0;), (UR;o:0;),(UF;o:0;),(UL;o:0;),(UB;o:0;),(DF;o:0;),(DL;o:0;), //D 
Cube::face_edges['l'] = {"FL", "DL", "BL", "UL"}; //ccw order
Cube::face_edges['b'] = {"BR", "DB", "BL", "UB"}; // ccw order
Cub:face_edges['u'] = {"UL", "UB", "UR", "UF"}; // ccw order

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
