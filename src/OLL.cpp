#include "../Cubos.hpp"

void Cube::solve_OLL()
{
    for (int i = 0; i < 4; i++)
    {
        if (algo_OLL.find(to_string_OLL()) != algo_OLL.end())   {
            Cube::res_moves += algo_OLL[to_string_OLL()] + " ";
            apply_moves(algo_OLL[to_string_OLL()]);
            if (to_string_OLL() != "00000000") {
                cout << "ERROR: Algo didn't solve : " << to_string_OLL() << endl;
                exit(1);
            }
            // cout << "OLL OK" << endl;
            return;
        }
        y();
        Cube::res_moves += "y ";
    }
    cout << "ERROR: " << to_string_OLL() << " not found !" << endl;
    exit(1);
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
    algo_OLL["01000002"] = "L F R' F' L' F R F'";
    algo_OLL["02000100"] = "F' L F R' F' L' F R";
    algo_OLL["00000102"] = "R2 D R' U2 R D' R' U2 R'";
    algo_OLL["00000000"] = "";
    // Tous les coins orientés correctement
    algo_OLL["00001010"] = "F R U R' U' F2 L' U' L U F";
    algo_OLL["00100010"] = "R U R' U' L R' F R F' L'";

    //10101112
    //02000110

    // En forme de "P"
    algo_OLL["12100001"] = "B U L U' L' B'";
    algo_OLL["00111200"] = "B' U' R' U R B";
    algo_OLL["11100002"] = "R U B' U' R' U R B R'";
    algo_OLL["11000012"] = "R' U' F U R U' R' F' R";
    // En forme de "W" (W shapes)
    algo_OLL["01001210"] = "R U R' U R U' R' U' R' F R F'";
    algo_OLL["10020011"] = "L' U' L U' L' U L U L F' L' F";
    // En forme de carré (square shapes)
    algo_OLL["12000212"] = "L F2 R' F' R F' L'";
    algo_OLL["11110001"] = "L' B2 R B R' B L";
    // En forme de "L"
    algo_OLL["02021111"] = "F R U R' U' R U R' U' F'";
    algo_OLL["11010212"] = "F' L' U' L U L' U' L U F";
    algo_OLL["02011211"] = "R' F' L F' L' F L F' L' F2 R";
    algo_OLL["12010211"] = "L F R' F R F' R' F R F2 L'";
    algo_OLL["12020111"] = "R' F R' F' R2 U2 B' R B R'";
    algo_OLL["01011212"] = "R' F R2 B' R2' F' R2 B R'";
    // En forme de poisson (fish shapes)
    algo_OLL["02021012"] = "R U R' U' R' F R2 U R' U' F'";
    algo_OLL["01101101"] = "R U R' B' R B U' B' R' B";
    algo_OLL["10110002"] = "R U2 R2 F R F' R U2 R'";
    algo_OLL["00011012"] = "F R' F' R U R U' R'";
    // De forme bizarre (Awkward Shapes)
    algo_OLL["10100201"] = "R2 U R' B' R U' R2 U R B R'";
    algo_OLL["01001012"] = "F R U R' U' F' U2 R U R' U' R' F R F'";
    algo_OLL["01021010"] = "R U R' U R U2 R' F R U R' U' F'";
    algo_OLL["02001011"] = "R' U2 R U R' U R R B U B' U' R'";
    // En forme d'éclair (Lightning Bolts)
    algo_OLL["01011110"] = "L F R' F R F2 L'";
    algo_OLL["00121202"] = "L' B' R B' R' B2 L";
    algo_OLL["00111101"] = "F' L' U' L U F R B U B' U' R'";
    algo_OLL["12100202"] = "F R U R' U' F' U F R U R' U' F'";
    algo_OLL["02100110"] = "R B' R' U' R U B U' R'";
    algo_OLL["00120011"] = "R' F R U R' U' F' U R";
    // En forme de "T" (T Shapes)
    algo_OLL["02100011"] = "F R U R' U' F'";
    algo_OLL["01100012"] = "R U R' U' R' F R F'";
    // En forme de "C" (C Shapes)
    algo_OLL["10011200"] = "R' U' R' F R F' U R";
    algo_OLL["02110010"] = "R U R' U' B' R' F R F' B";
    // En forme de "I" (I Shapes)
    algo_OLL["12011201"] = "R U2 R2 U' R U' R' U2 F R F'";
    algo_OLL["11011202"] = "R U R' U R U' B U' B' R'";
    algo_OLL["02110211"] = "F R U R' U' R F' L F R' F' L'";
    algo_OLL["02120111"] = "B U L U' L' U L U' L' B'";
    // En forme de "L" de Cavalier (Knight Move Shapes)
    algo_OLL["02100212"] = "L F L' R U R' U' L F' L'";
    algo_OLL["00110111"] = "R' F' R L' U' L U R' F R";
    algo_OLL["01110110"] = "F U R U2 R' U' R U R' F'";
    algo_OLL["02120012"] = "R' F R U R' F' R F U' F'";
    // Aucune arête en position
    algo_OLL["12111211"] = "R U2 R' R' F R F' U2 R' F R F'";
    algo_OLL["12121111"] = "F R U R' U' F' B U L U' L' B'";
    algo_OLL["11111011"] = "B U L U' L' B' U' F R U R' U' F'";
    algo_OLL["12101212"] = "B U L U' L' B' U F R U R' U' F'";
    algo_OLL["11121010"] = "F R U R' U F' U2 F' L F L'";
    algo_OLL["10101211"] = "R' U2 F R U R' U' F2 U2 F R";
    algo_OLL["10121011"] = "R U R' U R' F R F' U2 R' F R F'";
    algo_OLL["10101010"] = "R2 U2 R' F2 U2 R2 F' R2 U2 F2 R U2 R2 U'";
}