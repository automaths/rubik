#include "../Cubos.hpp"
#include "iostream"

using namespace std;

vector<int> Cube::get_facelets()
{
    vector<int> face(54);
    string str;

    face[U5] = 'U';
    face[R5] = 'R';
    face[F5] = 'F';
    face[D5] = 'D';
    face[L5] = 'L';
    face[B5] = 'B';

    face[U9] = corners["URF"].name[(0 + corners["URF"].orientation)];
    face[R1] = corners["URF"].name[(1 + corners["URF"].orientation) % 3];
    face[F3] = corners["URF"].name[(2 + corners["URF"].orientation) % 3];

    face[U7] = corners["UFL"].name[(0 + corners["UFL"].orientation)];
    face[F1] = corners["UFL"].name[(1 + corners["UFL"].orientation) % 3];
    face[L3] = corners["UFL"].name[(2 + corners["UFL"].orientation) % 3];

    face[U1] = corners["ULB"].name[(0 + corners["ULB"].orientation)];
    face[L1] = corners["ULB"].name[(1 + corners["ULB"].orientation) % 3];
    face[B3] = corners["ULB"].name[(2 + corners["ULB"].orientation) % 3];

    face[U3] = corners["UBR"].name[(0 + corners["UBR"].orientation)];
    face[B1] = corners["UBR"].name[(1 + corners["UBR"].orientation) % 3];
    face[R3] = corners["UBR"].name[(2 + corners["UBR"].orientation) % 3];

    face[D3] = corners["DFR"].name[(0 + corners["DFR"].orientation)];
    face[F9] = corners["DFR"].name[(1 + corners["DFR"].orientation) % 3];
    face[R7] = corners["DFR"].name[(2 + corners["DFR"].orientation) % 3];

    face[D1] = corners["DLF"].name[(0 + corners["DLF"].orientation)];
    face[L9] = corners["DLF"].name[(1 + corners["DLF"].orientation) % 3];
    face[F7] = corners["DLF"].name[(2 + corners["DLF"].orientation) % 3];

    face[D7] = corners["DBL"].name[(0 + corners["DBL"].orientation)];
    face[B9] = corners["DBL"].name[(1 + corners["DBL"].orientation) % 3];
    face[L7] = corners["DBL"].name[(2 + corners["DBL"].orientation) % 3];

    face[D9] = corners["DRB"].name[(0 + corners["DRB"].orientation)];
    face[R9] = corners["DRB"].name[(1 + corners["DRB"].orientation) % 3];
    face[B7] = corners["DRB"].name[(2 + corners["DRB"].orientation) % 3];

    face[U6] = edges["UR"].name[(0 + edges["UR"].orientation)];
    face[R2] = edges["UR"].name[(1 + edges["UR"].orientation) % 2];

    face[U8] = edges["UF"].name[(0 + edges["UF"].orientation)];
    face[F2] = edges["UF"].name[(1 + edges["UF"].orientation) % 2];

    face[U4] = edges["UL"].name[(0 + edges["UL"].orientation)];
    face[L2] = edges["UL"].name[(1 + edges["UL"].orientation) % 2];

    face[U2] = edges["UB"].name[(0 + edges["UB"].orientation)];
    face[B2] = edges["UB"].name[(1 + edges["UB"].orientation) % 2];

    face[D6] = edges["DR"].name[(0 + edges["DR"].orientation)];
    face[R8] = edges["DR"].name[(1 + edges["DR"].orientation) % 2];

    face[D2] = edges["DF"].name[(0 + edges["DF"].orientation)];
    face[F8] = edges["DF"].name[(1 + edges["DF"].orientation) % 2];

    face[D4] = edges["DL"].name[(0 + edges["DL"].orientation)];
    face[L8] = edges["DL"].name[(1 + edges["DL"].orientation) % 2];

    face[D8] = edges["DB"].name[(0 + edges["DB"].orientation)];
    face[B8] = edges["DB"].name[(1 + edges["DB"].orientation) % 2];

    face[F6] = edges["FR"].name[(0 + edges["FR"].orientation)];
    face[R4] = edges["FR"].name[(1 + edges["FR"].orientation) % 2];

    face[F4] = edges["FL"].name[(0 + edges["FL"].orientation)];
    face[L6] = edges["FL"].name[(1 + edges["FL"].orientation) % 2];

    face[B6] = edges["BL"].name[(0 + edges["BL"].orientation)];
    face[L4] = edges["BL"].name[(1 + edges["BL"].orientation) % 2];

    face[B4] = edges["BR"].name[(0 + edges["BR"].orientation)];
    face[R6] = edges["BR"].name[(1 + edges["BR"].orientation) % 2];

    // for (int i = 0; i < 8; ++i)
    // {
    //     str = corner_names[i];
    //     corners[str].name[(i + corners[str].orientation) % 3];
    // }
    // for (string c : face_corners[faceid])
    // {
    //     c = "UFR"
    //     i = index de faceid dans c;
    //     i += orientation du coin;
    //     i %= 3;
    //     corners[c].name[i];

    //     cout << c << c << endl;
    // }
    // for (string e : face_edges[faceid])
    // {
    //     cout << e.name << e.orientation << endl;
    // }

    return face;
}

const string Cube::corner_names[8] = {"URF", "UFL", "ULB", "UBR", "DFR", "DLF", "DBL", "DRB"};
const string Cube::edge_names[12] = {"UR", "UF", "UL", "UB", "DR", "DF", "DL", "DB", "FR", "FL", "BL", "BR"};
const char Cube::face_names[6] = {'u', 'r', 'f', 'd', 'l', 'b'};

map<char, vector<string> > Cube::face_corners;
map<char, vector<string> > Cube::face_edges;

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

bool Cube::is_cross()
{
    if (edges["UF"].orientation != 0
     || edges["UF"].name != "UF"
     || edges["UR"].orientation != 0
     || edges["UR"].name != "UR"
     || edges["UB"].orientation != 0
     || edges["UB"].name != "UB"
     || edges["UL"].orientation != 0
     || edges["UL"].name != "UL")
        return false;
    return true;
}

string Cube::to_string_forcross()
{
    string s = "";
    for (string edge_name : Cube::face_edges['u'])
    {
        Edge edge = edges[edge_name];
        s += edge.name + to_string(edge.orientation);
    }
    return s;
}


vector<int> Cube::get_face(char faceid) // TODO
{
    vector<int> face;

    // for (string c : face_corners[faceid])
    // {
    //     c = "UFR"
    //     i = index de faceid dans c;
    //     i += orientation du coin;
    //     i %= 3;
    //     corners[c].name[i];

    //     cout << c << c << endl;
    // }
    // for (string e : face_edges[faceid])
    // {
    //     cout << e.name << e.orientation << endl;
        
    // }
    return face;
}

