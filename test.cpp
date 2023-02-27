#include "../Cubos.hpp"

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

vector<int> Cube::get_facelets()
{
    vector<int> face(54);
    string str;

    face[U9] = corners["URF"].name[(0 + corners["URF"].orientation)];
    face[R1] = corners["URF"].name[(1 + corners["URF"].orientation) % 3];
    face[F3] = corners["URF"].name[(0 + corners["URF"].orientation) % 3];

    face[U7] = corners["UFL"].name[(0 + corners["UFL"].orientation)];
    face[F1] = corners["UFL"].name[(1 + corners["UFL"].orientation) % 3];
    face[L3] = corners["UFL"].name[(0 + corners["UFL"].orientation) % 3];

    face[U1] = corners["ULB"].name[(0 + corners["ULB"].orientation)];
    face[L1] = corners["ULB"].name[(1 + corners["ULB"].orientation) % 3];
    face[B1] = corners["ULB"].name[(0 + corners["ULB"].orientation) % 3];

    face[U3] = corners["UBR"].name[(0 + corners["UBR"].orientation)];
    face[B1] = corners["UBR"].name[(1 + corners["UBR"].orientation) % 3];
    face[R3] = corners["UBR"].name[(0 + corners["UBR"].orientation) % 3];

    face[D3] = corners["DFR"].name[(0 + corners["DFR"].orientation)];
    face[F9] = corners["DFR"].name[(1 + corners["DFR"].orientation) % 3];
    face[R7] = corners["DFR"].name[(0 + corners["DFR"].orientation) % 3];

    face[D1] = corners["DLF"].name[(0 + corners["DLF"].orientation)];
    face[L9] = corners["DLF"].name[(1 + corners["DLF"].orientation) % 3];
    face[F7] = corners["DLF"].name[(0 + corners["DLF"].orientation) % 3];

    face[D7] = corners["DBL"].name[(0 + corners["DBL"].orientation)];
    face[B9] = corners["DBL"].name[(1 + corners["DBL"].orientation) % 3];
    face[L7] = corners["DBL"].name[(0 + corners["DBL"].orientation) % 3];

    face[D9] = corners["DRB"].name[(0 + corners["DRB"].orientation)];
    face[R9] = corners["DRB"].name[(1 + corners["DRB"].orientation) % 3];
    face[B7] = corners["DRB"].name[(0 + corners["DRB"].orientation) % 3];

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

    face[U6] = edges["FR"].name[(0 + edges["FR"].orientation)];
    face[R2] = edges["FR"].name[(1 + edges["FR"].orientation) % 2];

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
