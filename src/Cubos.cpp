#include "../Cubos.hpp"
#include <iostream>
#include <sstream>

using namespace std;

const string Cube::corner_names[8] = {"URF", "UFL", "ULB", "UBR", "DFR", "DLF", "DBL", "DRB"};
const string Cube::edge_names[12] = {"UR", "UF", "UL", "UB", "DR", "DF", "DL", "DB", "FR", "FL", "BL", "BR"};
const char Cube::face_names[6] = {'u', 'r', 'f', 'd', 'l', 'b'};

map<char, vector<string> > Cube::face_corners;
map<char, vector<string> > Cube::face_edges;

map<string, string> Cube::corner_names_after_ymove;
map<string, string> Cube::edge_names_after_ymove;
map<string, string> Cube::algo_2FL;
map<string, string> Cube::algo_OLL;
map<string, string> Cube::algo_PLL;
string Cube::res_moves;

Corner::Corner(){}

Corner::Corner(string str)
{
    name = str;
    orientation = 0;
}

Corner& Corner::operator=(Corner const &other)
{
    name = other.name;
    orientation = other.orientation;
    return *this;
}

Edge::Edge(){}

Edge::Edge(string str)
{
    name = str;
    orientation = 0;
}

Edge& Edge::operator=(Edge const &other)
{
    name = other.name;
    orientation = other.orientation;
    return *this;
}

Cube::Cube()
{
    for (int i = 0; i < 8; ++i)
        corners[corner_names[i]] = Corner(corner_names[i]);
    for (int i = 0; i < 12; ++i)
        edges[edge_names[i]] = Edge(edge_names[i]);
}

void Cube::init_members()
{
    face_corners['u'] = {"URF", "UBR",  "ULB", "UFL"};
    face_corners['d'] = {"DFR", "DLF", "DBL", "DRB"};
    face_corners['r'] = {"DFR", "DRB", "UBR", "URF"};
    face_corners['f'] = {"URF", "UFL", "DLF", "DFR"};
    face_corners['l'] = {"UFL", "ULB", "DBL", "DLF"};
    face_corners['b'] = {"ULB", "UBR", "DRB", "DBL"};

    face_edges['u'] = {"UR", "UB", "UL", "UF"};
    face_edges['r'] = {"UR", "FR", "DR", "BR"};
    face_edges['f'] = {"UF", "FL", "DF", "FR"};
    face_edges['d'] = {"DR", "DF", "DL", "DB"};
    face_edges['l'] = {"UL", "BL", "DL", "FL"};
    face_edges['b'] = {"UB", "BR", "DB", "BL"};

    corner_names_after_ymove["UBR"] = "URF";
    corner_names_after_ymove["URF"] = "UFL";
    corner_names_after_ymove["UFL"] = "ULB";
    corner_names_after_ymove["ULB"] = "UBR";
    corner_names_after_ymove["DRB"] = "DFR";
    corner_names_after_ymove["DFR"] = "DLF";
    corner_names_after_ymove["DLF"] = "DBL";
    corner_names_after_ymove["DBL"] = "DRB";

    edge_names_after_ymove["UR"] = "UF";
    edge_names_after_ymove["UF"] = "UL";
    edge_names_after_ymove["UL"] = "UB";
    edge_names_after_ymove["UB"] = "UR";
    edge_names_after_ymove["DR"] = "DF";
    edge_names_after_ymove["DF"] = "DL";
    edge_names_after_ymove["DL"] = "DB";
    edge_names_after_ymove["DB"] = "DR";
    edge_names_after_ymove["FR"] = "FL";
    edge_names_after_ymove["FL"] = "BL";
    edge_names_after_ymove["BL"] = "BR";
    edge_names_after_ymove["BR"] = "FR";

    init_2FL();
    init_OLL();
    init_PLL();
}

void Cube::apply_moves(string moves)
{
    string parsed;
    stringstream input_ss(moves);

    if (moves == "")
        return;
    while (getline(input_ss, parsed, ' '))
        apply_move(parsed);
}

void Cube::apply_move(string move)
{
    char face = move[0] + 32;
    int direction = 1;
    
    if (move.size() > 1)
    {
        if (move[1] == '\'')
            direction = 3;
        else if (move[1] == '2')
            direction = 2;
    }
    if (move[0] == 'y') {
        for (int i = 0; i < direction; i++)
            y();
        return;
    }
    rotate(face, direction);
}

void Cube::rotate(char faceid, int direction)
{
    direction = (direction + 4) % 4;

    if (!face_corners.count(faceid) || !face_edges.count(faceid))
    {
        // cout << "Invalid faceid: '" << faceid << "'" << endl;
        if (faceid != ' ')
            exit(1);
        else return;
    }

    vector<string> &rot_corners = Cube::face_corners[faceid];
    vector<string> &rot_edges = Cube::face_edges[faceid];

    bool corner_pattern = (faceid != 'u' && faceid != 'd');
    bool edge_pattern = (faceid == 'f' || faceid == 'b');

    for (int d = 0; d < direction; d++)
    {
        // Permute corners
        for (int i = 0; corner_pattern && i < 4; i++) {
            corners[rot_corners[i]].orientation += 1 + i%2;
            corners[rot_corners[i]].orientation %= 3;
        }
        Corner tmpC = corners[rot_corners[0]];
        corners[rot_corners[0]] = corners[rot_corners[1]];
        corners[rot_corners[1]] = corners[rot_corners[2]];
        corners[rot_corners[2]] = corners[rot_corners[3]];
        corners[rot_corners[3]] = tmpC;
        
        // Permute edges
        for (int i = 0; edge_pattern && i < 4; i++) {
            edges[rot_edges[i]].orientation += 1;
            edges[rot_edges[i]].orientation %= 2;
        }    
        Edge tmpE = edges[rot_edges[0]];
        edges[rot_edges[0]] = edges[rot_edges[1]];
        edges[rot_edges[1]] = edges[rot_edges[2]];
        edges[rot_edges[2]] = edges[rot_edges[3]];
        edges[rot_edges[3]] = tmpE;
    }
}

void Cube::shuffle(int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        char faceid = Cube::face_names[rand() % 6];
        int direction = 1 + rand() % 3;
        rotate(faceid, direction);
        Cube::res_moves += string(1, faceid - 'a' + 'A') + string(direction == 1 ? "" : direction == 2 ? "2" : "\'") + " ";
    }
}

void Cube::y()
{
    // rotate every thing along y axis
    rotate('u', 1);
    rotate('d', 3);
    vector<string> middle_edges = {"BL", "FL", "FR", "BR"};
    Edge tmp = edges[middle_edges[0]];
    edges[middle_edges[0]] = edges[middle_edges[1]];
    edges[middle_edges[1]] = edges[middle_edges[2]];
    edges[middle_edges[2]] = edges[middle_edges[3]];
    edges[middle_edges[3]] = tmp;
    for (int i = 0; i < 4; i++)
        edges[middle_edges[i]].orientation = 1 - edges[middle_edges[i]].orientation;
    // change colors
    for (auto &corner : corners)
    {
        corner.second.name = corner_names_after_ymove[corner.second.name];
        // corner.second.orientation = (corner.second.orientation + 1) % 3;
    }
    for (auto &edge : edges)
    {
        edge.second.name = edge_names_after_ymove[edge.second.name];
        if (edge.second.name[0] != 'U' && edge.second.name[0] != 'D')
            edge.second.orientation = (edge.second.orientation + 1) % 2;
    }
}

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

    return face;
}

bool Cube::is_solved()
{
    for (auto &corner : corners)
    {
        if (corner.first != corner.second.name || corner.second.orientation != 0)
            return false;
    }
    for (auto &edge : edges)
    {
        if (edge.first != edge.second.name || edge.second.orientation != 0)
            return false;
    }
    return true;
}

SearchCube::SearchCube(Cube& cube, vector<string> moves)
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

bool SearchCube::operator<(const SearchCube& other) const
{
    return distance + moves.size() > other.distance + other.moves.size();
}


