#include "../rubik.hpp"

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

int print_ascii_rubik(Rubik &rk) {
    // Rubik   rk(9);

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