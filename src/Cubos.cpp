#include "../Cubos.hpp"
#include "iostream"

using namespace std;

const string Cube::corner_names[8] = {"URF", "UFL", "ULB", "UBR", "DFR", "DLF", "DBL", "DRB"};
const string Cube::edge_names[12] = {"UR", "UF", "UL", "UB", "DR", "DF", "DL", "DB", "FR", "FL", "BL", "BR"};
const char Cube::face_names[6] = {'u', 'r', 'f', 'd', 'l', 'b'};

void Cube::init_members()
{

    face_corners['u'] = {"URF", "UBR",  "ULB", "UFL"}; // ccw
    // (URF-> UBR; o: 0),(UBR-> ULB; o: 0),(ULB-> UFL; o: 0),(UFL-> URF; o:0)   //U
    face_corners['d'] = {"DFR", "DLF", "DBL", "DRB"}; // ccw
    //  (DFR-> DLF; o: 0), (DLF-> DBL; o: 0), (DBL-> DRB; o: 0), (DRB-> DFR; o: 0)   //D
    face_corners['r'] = {"DFR", "DRB", "UBR", "URF"}; // ccw
    // (DFR-> DRB; o: 1),(DRB-> UBR; o: 2), (UBR-> URF; o: 1), (URF-> DFR; o: 2)   //R
    face_corners['f'] = {"URF", "UFL", "DLF", "DFR"}; // ccw
    //  (URF-> UFL; o: 1), (UFL-> DLF; o: 2), (DLF-> DFR; o: 1), (DFR-> URF; o: 2)   //F
    face_corners['l'] = {"UFL", "ULB", "DBL", "DLF"}; // ccw
    //  (UFL-> ULB; o: 1), (ULB-> DBL; o: 2), (DBL-> DLF; o: 1), (DLF-> UFL; o: 2),   //L
    face_corners['b'] = {"ULB", "UBR", "DRB", "DBL"}; // ccw
    //  ((ULB-> UBR; o: 1), (UBR-> DRB; o: 2), (DRB-> DBL; o: 1), (DBL-> ULB; o: 2)));  //B

    // corner pattern : 1 2 1 2 pour faces f, r, b, l sinon 0


    face_edges['u'] = {"UR", "UB", "UL", "UF"}; // ccw order
    // (UR->UB; o: 0), (UB->UL; o: 0), (UL->UF; o: 0), (UF->UR; o: 0), //U
    face_edges['r'] = {"UR", "FR", "DR", "BR"}; // ccw order
    // (UR->FR; o: 0), (FR->DR; o: 0), (DR->BR; o: 0), (BR->UR; o: 0), //R
    face_edges['f'] = {"UF", "FL", "DF", "FR"}; // ccw order
    // (UF->FL; o: 1), (FL->DF; o: 1), (DF->FR; o: 1), (FR->UF; o: 1), //F 
    face_edges['d'] = {"DR", "DF", "DL", "DB"}; // ccw order
    // (DR->DF; o: 0), (DF->DL; o: 0), (DL->DB; o: 0), (DB->DR; o: 0), //D
    face_edges['l'] = {"UL", "BL", "DL", "FL"}; //ccw order
    // (UL->BL; o: 0), (BL->DL; o: 0), (DL->FL; o: 0), (FL->UL; o: 0), //L 
    face_edges['b'] = {"UB", "BR", "DB", "BL"}; // ccw order
    // (UB->BR; o: 1), (BR->DB; o: 1), (DB->BL; o: 1), (BL->UB; o: 1), //B 

    // edge pattern : 1 1 1 1 pour faces f, b sinon 0

}

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

    vector<string> &rot_corners = Cube::face_corners[faceid];
    vector<string> &rot_edges = Cube::face_edges[faceid];

    bool corner_pattern = (faceid != 'u' && faceid != 'd');
    bool edge_pattern = (faceid == 'f' || faceid == 'b');

    for (int d = 0; d < direction; d++)
    {
        // Permute corners
        Corner tmpC = corners[rot_corners[0]];
        corners[rot_corners[0]] = corners[rot_corners[1]];
        corners[rot_corners[1]] = corners[rot_corners[2]];
        corners[rot_corners[2]] = corners[rot_corners[3]];
        corners[rot_corners[3]] = tmpC;
        for (int i = 0; corner_pattern && i < 4; i++) {
            corners[rot_corners[i]].orientation += 1 + i%2;
            corners[rot_corners[i]].orientation %= 3;
        }
        
        // Permute edges
        Edge tmpE = edges[rot_edges[0]];
        edges[rot_edges[0]] = edges[rot_edges[1]];
        edges[rot_edges[1]] = edges[rot_edges[2]];
        edges[rot_edges[2]] = tmpE;
        for (int i = 0; edge_pattern && i < 3; i++) {
            edges[rot_edges[i]].orientation += 1;
            edges[rot_edges[i]].orientation %= 2;
        }    
    }
}

vector<int> Cube::get_face(char faceid) // TODO
{
    vector<int> face;

    for (Corner c : face_corners[faceid])
    {
        cout << c.name << c.orientation << endl;
    }
    for (Edge e : face_edges[faceid])
    {
        cout << e.name << e.orientation << endl;
    }
    return res;
}
