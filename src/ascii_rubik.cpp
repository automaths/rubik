#include "../Cubos.hpp"
#include <iostream>

void prt(int color, int nb)
{
    int i = -1;
    int letter = 0;

    if (color == 'U')
        letter = 47; // white
    if (color == 'B')
        letter = 44;  // blue
    if (color == 'R')
        letter = 41;  // red
    if (color == 'F')
        letter = 42;  // green
    if (color == 'L') 
        letter = 45;  // magenta
    if (color == 'D')
        letter = 43;  // blue

    cout << " " << "\033[1;" << letter << "m";
    while (++i < nb)
        cout << " ";
    cout << "\033[0m" << " ";
}

void ptr_r(int color)
{
    int letter = 0;

    if (color == 'U')
        letter = 47; // white
    if (color == 'B')
        letter = 44;  // blue
    if (color == 'R')
        letter = 41;  // red
    if (color == 'F')
        letter = 42;  // green
    if (color == 'L') 
        letter = 45;  // magenta
    if (color == 'D')
        letter = 43;  // blue
    
    cout << "   " << "\033[1;" << letter << "m    \033[0m" << "";
}

int convert_color(int color)
{
    if (color == 'U')
        return 47; // white
    if (color == 'B')
        return 44;  // blue
    if (color == 'R')
        return 41;  // red
    if (color == 'F')
        return 42;  // green
    if (color == 'L') 
        return 45;  // magenta
    if (color == 'D')
        return 43;  // blue 
    return 0;
}

int print_ascii_rubik(Cube &rk) {

    vector<int> rubik = rk.get_facelets();

    cout << endl;
    cout << endl;
    cout << endl;
    cout << "                                         / - - - / - - - / - - - /| - - - | - - - | - - - |" << endl;
    cout << "                                       /";prt(rubik[U1], 4);cout << " /";prt(rubik[U2], 4);cout << " /";prt(rubik[U3], 4);cout << " /";
    cout << "  |";
    prt(rubik[B1], 5);cout << "|";prt(rubik[B2], 5);cout << "|";prt(rubik[B3], 5);cout << "|";cout << endl;
    cout << "                                     /";ptr_r(rubik[U1]);cout << "/";ptr_r(rubik[U2]);cout << "/";ptr_r(rubik[U3]);cout << "/";
    cout << "    |";
    prt(rubik[B1], 5);cout << "|";prt(rubik[B2], 5);cout << "|";prt(rubik[B3], 5);cout << "|";cout << endl;
    cout << "                                   / - - - / - - - / - - - / ";
    cout << " " << "\033[1;" << convert_color(rubik[R3]) << "m    \033[0m";
    cout << "| - - - | - - - | - - - |" << endl;
    cout << "                                 /";prt(rubik[U4], 4);cout << " /";prt(rubik[U5], 4);cout << " /";prt(rubik[U6], 4);cout << " /";
    cout << "  |    /|";
    prt(rubik[B4], 5);cout << "|";prt(rubik[B5], 5);cout << "|";prt(rubik[B6], 5);cout << "|";cout << endl;
    cout << "                               /";ptr_r(rubik[U4]);cout << "/";ptr_r(rubik[U5]);cout << "/";ptr_r(rubik[U6]);cout << "/";
    cout << "    |  /  |";
    prt(rubik[B4], 5);cout << "|";prt(rubik[B5], 5);cout << "|";prt(rubik[B6], 5);cout << "|";cout << endl;
    cout << "                             / - - - / - - - / - - - /|";
    cout << " " << "\033[1;" << convert_color(rubik[R2]) << "m    \033[0m";
    cout << "|/";
    cout << "\033[1;" << convert_color(rubik[R6]) << "m    \033[0m";
    cout << "| - - - | - - - | - - - |" << endl;
    cout << "                           /";prt(rubik[U7], 4);cout << " /";prt(rubik[U8], 4);cout << " /";prt(rubik[U9], 4);cout << " /";
    cout << "  |    /|    /|";
    prt(rubik[B7], 5);cout << "|";prt(rubik[B8], 5);cout << "|";prt(rubik[B9], 5);cout << "|";cout << endl;
    cout << "                         /";ptr_r(rubik[U7]);cout << "/";ptr_r(rubik[U8]);cout << "/";ptr_r(rubik[U9]);cout << "/";
    cout << "    |  /  |  /  |";
    prt(rubik[B7], 5);cout << "|";prt(rubik[B8], 5);cout << "|";prt(rubik[B9], 5);cout << "|";cout << endl;
    cout << "| - - - | - - - | - - - | - - - | - - - | - - - |";
    cout << " " << "\033[1;" << convert_color(rubik[R1]) << "m    \033[0m";
    cout << "|/";
    cout << "\033[1;" << convert_color(rubik[R5]) << "m    \033[0m";
    cout << "|/";
    cout << "\033[1;" << convert_color(rubik[R9]) << "m    \033[0m";
    cout << "| - - - | - - - | - - - |" << endl;
    cout << "|";prt(rubik[L1], 5); cout << "|"; prt(rubik[L2], 5);cout << "|";prt(rubik[L3], 5);cout << "|";prt(rubik[F1], 5); cout << "|"; prt(rubik[F2], 5);cout << "|";prt(rubik[F3], 5);cout << "|";
    cout << "    /|    /|    /" << endl;
    cout << "|";prt(rubik[L1], 5); cout << "|"; prt(rubik[L2], 5);cout << "|";prt(rubik[L3], 5);cout << "|";prt(rubik[F1], 5); cout << "|"; prt(rubik[F2], 5);cout << "|";prt(rubik[F3], 5);cout << "|";
    cout << "  /  |  /  |  /" << endl;
    cout << "| - - - | - - - | - - - | - - - | - - - | - - - |/";
    cout << "\033[1;" << convert_color(rubik[R4]) << "m    \033[0m";
    cout << "|/";
    cout << "\033[1;" << convert_color(rubik[R8]) << "m    \033[0m";
    cout << "|/" << endl;
    cout << "|";prt(rubik[L4], 5); cout << "|"; prt(rubik[L5], 5);cout << "|";prt(rubik[L6], 5);cout << "|";prt(rubik[F4], 5); cout << "|"; prt(rubik[F5], 5);cout << "|";prt(rubik[F6], 5);cout << "|";
    cout << "    /|    /" << endl;
    cout << "|";prt(rubik[L4], 5); cout << "|"; prt(rubik[L5], 5);cout << "|";prt(rubik[L6], 5);cout << "|";prt(rubik[F4], 5); cout << "|"; prt(rubik[F5], 5);cout << "|";prt(rubik[F6], 5);cout << "|";
    cout << "  /  |  /" << endl;
    cout << "| - - - | - - - | - - - | - - - | - - - | - - - |/";
    cout << "\033[1;" << convert_color(rubik[R7]) << "m    \033[0m";
    cout << "|/" << endl;
    cout << "|";prt(rubik[L7], 5); cout << "|"; prt(rubik[L8], 5);cout << "|";prt(rubik[L9], 5);cout << "|";prt(rubik[F7], 5); cout << "|"; prt(rubik[F8], 5);cout << "|";prt(rubik[F9], 5);cout << "|";
    cout << "    /" << endl;
    cout << "|";prt(rubik[L7], 5); cout << "|"; prt(rubik[L8], 5);cout << "|";prt(rubik[L9], 5);cout << "|";prt(rubik[F7], 5); cout << "|"; prt(rubik[F8], 5);cout << "|";prt(rubik[F9], 5);cout << "|";
    cout << "  /" << endl;
    cout << "| - - - | - - - | - - - | - - - | - - - | - - - |/" << endl;
    cout << "                        |";
    prt(rubik[D1], 5); cout << "|"; prt(rubik[D2], 5);cout << "|";prt(rubik[D3], 5);cout << "|";cout << endl;
    cout << "                        |";
    prt(rubik[D1], 5);cout << "|";prt(rubik[D2], 5);cout << "|";prt(rubik[D3], 5);cout << "|";cout << endl;
    cout << "                        | - - - | - - - | - - - |" << endl;
    cout << "                        |";
    prt(rubik[D4], 5);cout << "|";prt(rubik[D5], 5);cout << "|";prt(rubik[D6], 5);cout << "|";cout << endl;
    cout << "                        |";
    prt(rubik[D4], 5);cout << "|";prt(rubik[D5], 5);cout << "|";prt(rubik[D6], 5);cout << "|";cout << endl;
    cout << "                        | - - - | - - - | - - - |" << endl;
    cout << "                        |";
    prt(rubik[D7], 5);cout << "|";prt(rubik[D8], 5);cout << "|";prt(rubik[D9], 5);cout << "|";cout << endl;
    cout << "                        |";
    prt(rubik[D7], 5);cout << "|";prt(rubik[D8], 5);cout << "|";prt(rubik[D9], 5);cout << "|";cout << endl;
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