#include "../Cubos.hpp"

void Cube::solve_PLL()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            {
                if (algo_PLL.find(to_string_PLL()) != algo_PLL.end())   {
                    string cas = to_string_PLL();
                    apply_moves(algo_PLL[to_string_PLL()]);
                    Cube::res_moves += algo_PLL[to_string_PLL()] + " | ";
                    for (int k = 0; k < 4 && to_string_PLL() != "UL ULB UB UBR UR URF UF UFL"; k++) {
                        rotate('u', 1);
                    }

                    if (i == 1)
                        Cube::res_moves += "U ";
                    else if (i == 2)
                        Cube::res_moves += "U2 ";
                    else if (i == 3)
                        Cube::res_moves += "U' ";
                    else if (to_string_PLL() != "UL ULB UB UBR UR URF UF UFL") {
                        cout << "ERROR: Algo didn't solve : " << cas << endl;
                        exit(1);
                    }
                    else
                        cout << "PLL OK" << endl;
                    return;
                }
                rotate('u', 1);
                cout << "the algo tried is: " << to_string_PLL() << endl;
            }
        }
        y();
    }
    cout << "ERROR: " << to_string_PLL() << " not found !" << endl;
    exit(1);
}

string Cube::to_string_PLL()
{
    string s = edges["UL"].name + " " + corners["ULB"].name \
    + " " + edges["UB"].name + " " + corners["UBR"].name \
    + " " + edges["UR"].name + " " + corners["URF"].name \
    + " " + edges["UF"].name + " " + corners["UFL"].name;
    return s;
}

/*

*/

void Cube::init_PLL()
{
    // Permutations des arrêtes ou des coins seulement
    algo_PLL["UR ULB UB UBR UF URF UL UFL"] = "R2 U R U R' U' R' U' R' U R'";
    algo_PLL["UF ULB UB UBR UL URF UR UFL"] = "R U' R U R U R U' R' U' R2";
    algo_PLL["UB ULB UL UBR UF URF UR UFL"] = "R' U' R2 U R U R' U' R U R U' R U' R'";
    algo_PLL["UR ULB UF UBR UL URF UB UFL"] = "L R U2 L' R' F' B' U2 F B";
    algo_PLL["UL UBR UB URF UR ULB UF UFL"] = "R' F R' B2 R F' R' B2 R2";
    algo_PLL["UL ULB UB UFL UR UBR UF URF"] = "R B' R F2 R' B R F2 R2";
    algo_PLL["UL UFL UB URF UR UBR UF ULB"] = "R B' R' F R B R' F' R B R' F R B' R' F'";
    algo_PLL["UL ULB UB UBR UR URF UF UFL"] = "";
    // Permutation deux coins adjacents
    algo_PLL["UF UBR UB ULB UR URF UL UFL"] = "L U2' L' U2' L F' L' U' L U L F L2' U";
    algo_PLL["UL UBR UB ULB UF URF UR UFL"] = "R' U2 R U2 R' F R U R' U' R' F' R2 U'";
    algo_PLL["UB UBR UL ULB UR URF UF UFL"] = "R' U L' U2 R U' R' U2 R L U'";
    algo_PLL["UL ULB UB URF UF UBR UR UFL"] = "R U R' F' R U R' U' R' F R2 U' R' U'";
    algo_PLL["UR ULB UB URF UL UBR UF UFL"] = "R U R' U' R' F R2 U' R' U' R U R' F'";
    algo_PLL["UL ULB UF URF UR UBR UB UFL"] = "R' U' F' R U R' U' R' F R2 U' R' U' R U R' U R";
    // Permutation deux coins en diagonale
    algo_PLL["UL URF UR UBR UB ULB UF UFL"] = "R' U R' U' B' R' B2 U' B' U B' R B R";
    algo_PLL["UB URF UL UBR UR ULB UF UFL"] = "F R U' R' U' R U R' F' R U R' U' R' F R F'";
    algo_PLL["UL URF UF UBR UR ULB UB UFL"] = "L U' R U2 L' U R' L U' R U2 L' U R' U";
    algo_PLL["UL ULB UF UFL UR URF UB UBR"] = "R' U L' U2 R U' L R' U L' U2 R U' L U'";
    // Double rotation
    algo_PLL["UR UBR UL UFL UB URF UF ULB"] = "R2 D B' U B' U' B D' R2 F' U F";
    algo_PLL["UR UFL UB UBR UF ULB UL URF"] = "R2 D' F U' F U F' D R2 B U' B'";
    algo_PLL["UF UBR UL UFL UR URF UB ULB"] = "R U R' F2 D' L U' L' U L' D F2";
    algo_PLL["UB UFL UF UBR UR ULB UL URF"] = "R' U' R B2 D L' U L U' L D' B2";
}
