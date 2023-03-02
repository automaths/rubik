#include "../Cubos.hpp"

void Cube::solve_OLL()
{
    for (int i = 0; i < 4; i++)
    {
        if (algo_OLL.find(to_string_OLL()) != algo_OLL.end())   {
            apply_moves(algo_OLL[to_string_OLL()]);
            return;
        }
        y();
    }
    cout << "ERROR: " << to_string_OLL() << endl;
}

string Cube::to_string_OLL()
{
    string s = to_string(edges["UL"].orientation) + to_string(corners["ULB"].orientation) \
        + to_string(edges["UB"].orientation) + to_string(corners["UBR"].orientation) \
        + to_string(edges["UR"].orientation) + to_string(corners["URF"].orientation) \
        + to_string(edges["UF"].orientation) + to_string(corners["UFL"].orientation);
    return s;
}

void Cube::init_OLL()
{
    // Toutes les arêtes orientées correctement
    algo_OLL["01010100"] = "R U R' U R U2 R'";
    algo_OLL["02000202"] = "R U2 R' U' R U' R'";
    algo_OLL["02020101"] = "R U2' R2' U' R2 U' R2' U2 R";
    algo_OLL["01020102"] = "F R U R' U' R U R' U' R U R' U' F'";
    algo_OLL["01000002"] = "Rw U R' U' Rw' F R F'";
    algo_OLL["02000100"] = "F' Rw U R' U' Rw' F R";
    algo_OLL["00000102"] = "R2 D R' U2 R D' R' U2 R'";
    algo_OLL["00000000"] = "";
    // Tous les coins orientés correctement
    algo_OLL["00001010"] = "M U M' U2 M U M'";
    algo_OLL["00100010"] = "R U R' U' Rw R' U R U' Rw'";
    // En forme de "P"
    algo_OLL["12100001"] = "Fw R U R' U' Fw'";
    algo_OLL["00111200"] = "Fw' L' U' L U Fw";
    algo_OLL["12100002"] = "R U B' U' R' U R B R'";
    algo_OLL["12000012"] = "R' U' F U R U' R' F' R";
    // En forme de "W" (W shapes)
    algo_OLL["01001210"] = "R U R' U R U' R' U' R' F R F'";
    algo_OLL["10010011"] = "L' U' L U' L' U L U L F' L' F";
    // En forme de carré (square shapes)
    algo_OLL["12000212"] = "Rw U2 R' U' R U' Rw'";
    algo_OLL["11110001"] = "Rw' U2 R U R' U Rw";
    // En forme de "L"
    algo_OLL["20211110"] = "F R U R' U' R U R' U' F'";
    algo_OLL["11010212"] = "F' L' U' L U L' U' L U F";
    algo_OLL["11010212"] = "y2 Rw' U' R U' R' U R U' R' U2 Rw";
    algo_OLL["02011211"] = "Rw U R' U R U' R' U R U2 Rw'";
    algo_OLL["12020111"] = "R' F R' F' R2 U2 y R' F R F' y'";
    algo_OLL["01011212"] = "R' F R2 B' R2' F' R2 B R'";
    // En forme de poisson (fish shapes)
    algo_OLL["02021012"] = "R U R' U' R' F R2 U R' U' F'";
    algo_OLL["02101101"] = "R U R' y R' F R U' R' F' R y'";
    algo_OLL["10110002"] = "R U2 R2 F R F' R U2 R'";
    algo_OLL["00011012"] = "F R' F' R U R U' R'";
    // De forme bizarre (Awkward Shapes)
    algo_OLL["10100201"] = "R2 U R' B' R U' R2 U R B R'";
    algo_OLL["02001012"] = "R U R' U' R U' R' F' U' F R U R'";
    algo_OLL["02011010"] = "R U R' U R U2 R' F R U R' U' F'";
    algo_OLL["02001012"] = "R' U2 R U R' U R y F R U R' U' F' y'";
    // En forme d'éclair (Lightning Bolts)
    algo_OLL["02021110"] = "Rw U R' U R U2 Rw'";
    algo_OLL["00111202"] = "Rw' U' R U' R' U2 Rw";
    algo_OLL["00121101"] = "F' L' U' L U F y F R U R' U' F'";
    algo_OLL["12100202"] = "F R U R' U' F' U F R U R' U' F'";
    algo_OLL["02100110"] = "R B' R' U' R U B U' R'";
    algo_OLL["00120011"] = "R' F R U R' U' F' U R";
    // En forme de "T" (T Shapes)
    algo_OLL["02100011"] = "F R U R' U' F'";
    algo_OLL["02100012"] = "R U R' U' R' F R F'";
    // En forme de "C" (C Shapes)
    algo_OLL["10011200"] = "R' U' R' F R F' U R";
    algo_OLL["02120010"] = "R U R' U' B' R' F R F' B";
    // En forme de "I" (I Shapes)
    algo_OLL["12011201"] = "R U2 R2 U' R U' R' U2 F R F'";
    algo_OLL["12011202"] = "R U R' U R U' y R U' R' F' y'";
    algo_OLL["02110211"] = "F R U R' U' R F' Rw U R' U' Rw'";
    algo_OLL["02120111"] = "y2 F U R U' R' U R U' R' F' y2";
    // En forme de "L" de Cavalier (Knight Move Shapes)
    algo_OLL["02100212"] = "L F L' R U R' U' L F' L'";
    algo_OLL["00110111"] = "R' F' R L' U' L U R' F R";
    algo_OLL["01110110"] = "F U R U2 R' U' R U R' F'";
    algo_OLL["02120012"] = "R' F R U R' F' R y' R U' R' y";
    // Aucune arête en position
    algo_OLL["12111211"] = "R U2 R' R' F R F' U2 R' F R F'";
    algo_OLL["12121111"] = "F R U R' U' F' Fw R U R' U' Fw'";
    algo_OLL["11111011"] = "Fw R U R' U' Fw' U' F R U R' U' F'";
    algo_OLL["10101211"] = "Fw R U R' U' Fw' U [F R U R' U' F'";
    algo_OLL["12121010"] = "F R U R' U F' y' U2 R' F R F'";
    algo_OLL["10101211"] = "Rw' U2 R U R' U Rw2 U2 R' U' R U' Rw";
    algo_OLL["10121011"] = "R U R' U R' F R F' U2 R' F R F'";
    algo_OLL["10101010"] = "Rw' R U R U R' U' Rw2 R2' U R U' Rw'";
}