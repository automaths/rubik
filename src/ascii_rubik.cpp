#include "../rubik.hpp"

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

void prt(int color, int nb)
{
    int i = -1;
    cout << " " << "\033[1;" << color << "m";
    while (++i < nb)
        cout << " ";
    cout << "\033[0m" << " ";
}

void ptr_r(int color)
{
    cout << "   " << "\033[1;" << color << "m    \033[0m" << "";
}

int print_ascii_rubik() {
    Rubik   rk(9);

    cout << endl;
    cout << endl;
    cout << endl;
    cout << "                                         / - - - / - - - / - - - /| - - - | - - - | - - - |" << endl;
    cout << "                                       /";prt(rk.s(U1), 4);cout << " /";prt(rk.s(U2), 4);cout << " /";prt(rk.s(U3), 4);cout << " /";
    cout << "  |";
    prt(rk.s(B1), 5);cout << "|";prt(rk.s(B2), 5);cout << "|";prt(rk.s(B3), 5);cout << "|";cout << endl;
    cout << "                                     /";ptr_r(rk.s(U1));cout << "/";ptr_r(rk.s(U2));cout << "/";ptr_r(rk.s(U3));cout << "/";
    cout << "    |";
    prt(rk.s(B1), 5);cout << "|";prt(rk.s(B2), 5);cout << "|";prt(rk.s(B3), 5);cout << "|";cout << endl;
    cout << "                                   / - - - / - - - / - - - / ";
    cout << " " << "\033[1;" << rk.s(R3) << "m    \033[0m";
    cout << "| - - - | - - - | - - - |" << endl;
    cout << "                                 /";prt(rk.s(U4), 4);cout << " /";prt(rk.s(U5), 4);cout << " /";prt(rk.s(U6), 4);cout << " /";
    cout << "  |    /|";
    prt(rk.s(B4), 5);cout << "|";prt(rk.s(B5), 5);cout << "|";prt(rk.s(B6), 5);cout << "|";cout << endl;
    cout << "                               /";ptr_r(rk.s(U4));cout << "/";ptr_r(rk.s(U5));cout << "/";ptr_r(rk.s(U6));cout << "/";
    cout << "    |  /  |";
    prt(rk.s(B4), 5);cout << "|";prt(rk.s(B5), 5);cout << "|";prt(rk.s(B6), 5);cout << "|";cout << endl;
    cout << "                             / - - - / - - - / - - - /|";
    cout << " " << "\033[1;" << rk.s(R2) << "m    \033[0m";
    cout << "|/";
    cout << "\033[1;" << rk.s(R6) << "m    \033[0m";
    cout << "| - - - | - - - | - - - |" << endl;
    cout << "                           /";prt(rk.s(U7), 4);cout << " /";prt(rk.s(U8), 4);cout << " /";prt(rk.s(U9), 4);cout << " /";
    cout << "  |    /|    /|";
    prt(rk.s(B7), 5);cout << "|";prt(rk.s(B8), 5);cout << "|";prt(rk.s(B9), 5);cout << "|";cout << endl;
    cout << "                         /";ptr_r(rk.s(U7));cout << "/";ptr_r(rk.s(U8));cout << "/";ptr_r(rk.s(U9));cout << "/";
    cout << "    |  /  |  /  |";
    prt(rk.s(B7), 5);cout << "|";prt(rk.s(B8), 5);cout << "|";prt(rk.s(B9), 5);cout << "|";cout << endl;
    cout << "| - - - | - - - | - - - | - - - | - - - | - - - |";
    cout << " " << "\033[1;" << rk.s(R1) << "m    \033[0m";
    cout << "|/";
    cout << "\033[1;" << rk.s(R5) << "m    \033[0m";
    cout << "|/";
    cout << "\033[1;" << rk.s(R9) << "m    \033[0m";
    cout << "| - - - | - - - | - - - |" << endl;
    cout << "|";prt(rk.s(L1), 5); cout << "|"; prt(rk.s(L2), 5);cout << "|";prt(rk.s(L3), 5);cout << "|";prt(rk.s(F1), 5); cout << "|"; prt(rk.s(F2), 5);cout << "|";prt(rk.s(F3), 5);cout << "|";
    cout << "    /|    /|    /" << endl;
    cout << "|";prt(rk.s(L1), 5); cout << "|"; prt(rk.s(L2), 5);cout << "|";prt(rk.s(L3), 5);cout << "|";prt(rk.s(F1), 5); cout << "|"; prt(rk.s(F2), 5);cout << "|";prt(rk.s(F3), 5);cout << "|";
    cout << "  /  |  /  |  /" << endl;
    cout << "| - - - | - - - | - - - | - - - | - - - | - - - |/";
    cout << "\033[1;" << rk.s(R4) << "m    \033[0m";
    cout << "|/";
    cout << "\033[1;" << rk.s(R8) << "m    \033[0m";
    cout << "|/" << endl;
    cout << "|";prt(rk.s(L4), 5); cout << "|"; prt(rk.s(L5), 5);cout << "|";prt(rk.s(L6), 5);cout << "|";prt(rk.s(F4), 5); cout << "|"; prt(rk.s(F5), 5);cout << "|";prt(rk.s(F6), 5);cout << "|";
    cout << "    /|    /" << endl;
    cout << "|";prt(rk.s(L4), 5); cout << "|"; prt(rk.s(L5), 5);cout << "|";prt(rk.s(L6), 5);cout << "|";prt(rk.s(F4), 5); cout << "|"; prt(rk.s(F5), 5);cout << "|";prt(rk.s(F6), 5);cout << "|";
    cout << "  /  |  /" << endl;
    cout << "| - - - | - - - | - - - | - - - | - - - | - - - |/";
    cout << "\033[1;" << rk.s(R7) << "m    \033[0m";
    cout << "|/" << endl;
    cout << "|";prt(rk.s(L7), 5); cout << "|"; prt(rk.s(L8), 5);cout << "|";prt(rk.s(L9), 5);cout << "|";prt(rk.s(F7), 5); cout << "|"; prt(rk.s(F8), 5);cout << "|";prt(rk.s(F9), 5);cout << "|";
    cout << "    /" << endl;
    cout << "|";prt(rk.s(L7), 5); cout << "|"; prt(rk.s(L8), 5);cout << "|";prt(rk.s(L9), 5);cout << "|";prt(rk.s(F7), 5); cout << "|"; prt(rk.s(F8), 5);cout << "|";prt(rk.s(F9), 5);cout << "|";
    cout << "  /" << endl;
    cout << "| - - - | - - - | - - - | - - - | - - - | - - - |/" << endl;
    cout << "                        |";
    prt(rk.s(D1), 5); cout << "|"; prt(rk.s(D2), 5);cout << "|";prt(rk.s(D3), 5);cout << "|";cout << endl;
    cout << "                        |";
    prt(rk.s(D1), 5);cout << "|";prt(rk.s(D2), 5);cout << "|";prt(rk.s(D3), 5);cout << "|";cout << endl;
    cout << "                        | - - - | - - - | - - - |" << endl;
    cout << "                        |";
    prt(rk.s(D4), 5);cout << "|";prt(rk.s(D5), 5);cout << "|";prt(rk.s(D6), 5);cout << "|";cout << endl;
    cout << "                        |";
    prt(rk.s(D4), 5);cout << "|";prt(rk.s(D5), 5);cout << "|";prt(rk.s(D6), 5);cout << "|";cout << endl;
    cout << "                        | - - - | - - - | - - - |" << endl;
    cout << "                        |";
    prt(rk.s(D7), 5);cout << "|";prt(rk.s(D8), 5);cout << "|";prt(rk.s(D9), 5);cout << "|";cout << endl;
    cout << "                        |";
    prt(rk.s(D7), 5);cout << "|";prt(rk.s(D8), 5);cout << "|";prt(rk.s(D9), 5);cout << "|";cout << endl;
    cout << "                        | - - - | - - - | - - - |" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    return 0;
}

    // cout << "                                         / - - - / - - - / - - - /| - - - | - - - | - - - |" << endl;
    // cout << "                                       /       /       /       /  |       |       |       |" << endl;
    // cout << "                                     /       /       /       /    |       |       |       |" << endl;
    // cout << "                                   / - - - / - - - / - - - /      | - - - | - - - | - - - |" << endl;
    // cout << "                                 /       /       /       /  |    /|       |       |       |" << endl;
    // cout << "                               /       /       /       /    |  /  |       |       |       |" << endl;
    // cout << "                             / - - - / - - - / - - - /|     |/    | - - - | - - - | - - - |" << endl;
    // cout << "                           /       /       /       /  |    /|    /|       |       |       |" << endl;
    // cout << "                         /       /       /       /    |  /  |  /  |       |       |       |" << endl;
    // cout << "| - - - | - - - | - - - | - - - | - - - | - - - |     |/    |/    | - - - | - - - | - - - |" << endl;
    // cout << "|       |       |       |       |       |       |    /|    /|    /" << endl;
    // cout << "|       |       |       |       |       |       |  /  |  /  |  /" << endl;
    // cout << "| - - - | - - - | - - - | - - - | - - - | - - - |/    |/    |/" << endl;
    // cout << "|       |       |       |       |       |       |    /|    /" << endl;
    // cout << "|       |       |       |       |       |       |  /  |  /" << endl;
    // cout << "| - - - | - - - | - - - | - - - | - - - | - - - |/    |/" << endl;
    // cout << "|       |       |       |       |       |       |    /" << endl;
    // cout << "|       |       |       |       |       |       |  /" << endl;
    // cout << "| - - - | - - - | - - - | - - - | - - - | - - - |/" << endl;
    // cout << "                        |       |       |       |" << endl;
    // cout << "                        |       |       |       |" << endl;
    // cout << "                        | - - - | - - - | - - - |" << endl;
    // cout << "                        |       |       |       |" << endl;
    // cout << "                        |       |       |       |" << endl;
    // cout << "                        | - - - | - - - | - - - |" << endl;
    // cout << "                        |       |       |       |" << endl;
    // cout << "                        |       |       |       |" << endl;
    // cout << "                        | - - - | - - - | - - - |" << endl;