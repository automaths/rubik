#include "../Cubos.hpp"

void Cube::solve_2FL()
{
    for (int i = 0; i < 4; i++)
    {
        one_corner_2FL();
        y();
    }
}

void Cube::one_corner_2FL()
{
    int tmp = 0;
    for (auto corner : corners)
    {
        if (corner.second.name == "DFR")
        {
            if (corner.first == "DFR")
                ++tmp;
            else if (corner.first == "URF")
                ;
            else if (corner.first == "UFL")
                rotate('u', 3);
            else if (corner.first == "ULB")
                rotate('u', 2);
            else if (corner.first == "UBR")
                rotate('u', 1);
            else if (corner.first == "DLF")
            {
                rotate('l', 3);
                rotate('u', 3);
                rotate('l', 1);               
            }
            else if (corner.first == "DBL")
            {
                rotate('l', 1);
                rotate('u', 1);
                rotate('l', 3);
                rotate('u', 1);
            }
            else if (corner.first == "DRB")
            {
                rotate('r', 3);
                rotate('u', 3);
                rotate('r', 1);  
                rotate('u', 2);
            }
        }
    }
    for (auto edge : edges)
    {
        if (edge.second.name == "FR")
        {
            if (edge.first == "FL")
            {
                rotate('l', 3);
                rotate('u', 3);
                rotate('l', 1);
                if (!tmp)
                    rotate('u', 1);  
            }
            else if (edge.first == "BR")
            {
                rotate('r', 3);
                rotate('u', 3);
                rotate('r', 1);            
            }
            else if (edge.first == "BL")
            {
                rotate('l', 1);
                rotate('u', 1);  
                rotate('l', 3);              
                rotate('u', 2);  
            }
        }
    }
    cout << "the string is : " << to_string_2FL() << " and the algo is " << algo_2FL[to_string_2FL()] << endl;
    apply_moves(algo_2FL[to_string_2FL()]);
    cout << "the result is: " << to_string_2FL() << endl;
}

// par example : le tout premier algo de speedcubingtips insertion simple sappelle
// "***E0C1**"

// string Cube::to_string_2FL()
// {
//     string s = "";
//     s += (edges["UL"].name == "FR") ? ("E" + to_string(edges["UL"].orientation)) : "*";
//     s += (edges["UB"].name == "FR") ? ("E" + to_string(edges["UB"].orientation)) : "*";
//     s += (edges["UF"].name == "FR") ? ("E" + to_string(edges["UF"].orientation)) : "*";
//     s += (edges["UR"].name == "FR") ? ("E" + to_string(edges["UR"].orientation)) : "*";

//     s += (corners["URF"].name == "DFR") ? ("C" + to_string(corners["URF"].orientation)) : "*";
    
//     s += (edges["FR"].name == "FR") ? ("E" + to_string(edges["FR"].orientation)) : "*";

//     s += (corners["DFR"].name == "DFR") ? ("C" + to_string(corners["DFR"].orientation)) : "*";
//     return s;
// }

void Cube::init_2FL()
{
    // Insertions simples
    algo_2FL["***E0C1**"] = "U R U' R'";
    algo_2FL["**E1*C2**"] = "y' U' R' U R";
    algo_2FL["E1***C1**"] = "y' R' U' R";
    algo_2FL["*E0**C2**"] = "R U R'";
    // F2L Cas 1
    algo_2FL["*E1**C1**"] = "U' R U' R' U y' R' U' R";
    algo_2FL["E0***C2**"] = "U' R U R' U R U R'";
    algo_2FL["***E1C1**"] = "U' R U2 R' U y' R' U' R";
    algo_2FL["**E0*C2**"] = "R' U2 R2 U R2' U R";
    algo_2FL["**E1*C1**"] = "y' U R' U R U' R' U' R";
    algo_2FL["***E0C2**"] = "U' R U' R' U R U R'";    
    // F2L Cas 2
    algo_2FL["*E0**C1**"] = "U' R U R' U2 R U' R'";
    algo_2FL["E1***C2**"] = "y' U R' U' R U2 R' U R";
    algo_2FL["E0***C1**"] = "U' R U2 R' U2 R U' R'";
    algo_2FL["*E1**C2**"] = "y' U R' U2 R U2 R' U R";
    // F2L Cas 3
    algo_2FL["*E0**C0**"] = "U R U2 R' U R U' R'";
    algo_2FL["E1***C0**"] = "y' U' R' U2 R U' R' U R";
    algo_2FL["E0***C0**"] = "U2 R U R' U R U' R'";
    algo_2FL["*E1**C0**"] = "F' L' U2 L F";
    // Coin et arrete non connetes correctement
    algo_2FL["**E0*C1**"] = "y' R' U R U2 y R U R'";
    algo_2FL["***E1C2**"] = "R U' R' U2 F' U' F";
    algo_2FL["***E0C0**"] = "R U2 R' U' R U R'";
    algo_2FL["**E1*C0**"] = "y' R' U2 R U R' U' R";
    algo_2FL["**E0*C0**"] = "U2 R2 U2 R' U' R U' R2";
    algo_2FL["***E1C0**"] = "y' U2 R2 U2 R U R' U R2";
    // Coin en place et arrete en face superieure
    algo_2FL["***E0**C0"] = "R' F' R U R U' R' F";
    algo_2FL["**E1***C0"] = "U R U' R' U' F' U F";
    algo_2FL["***E0**C2"] = "R U' R' U R U' R'";
    algo_2FL["**E1***C1"] = "R U' R' U2 F' U F";
    algo_2FL["**E1***C2"] = "y' R' U' R U R' U' R";
    algo_2FL["***E0**C1"] = "R U R' U' R U R'";
    // Arrete en place et coin en face superieure
    algo_2FL["****C0E1*"] = "R U' R' U y' R' U R";
    algo_2FL["****C0E0*"] = "U R U' R' U R U' R' U R U' R'";
    algo_2FL["****C1E0*"] = "U' R U' R' U2 R U' R'";
    algo_2FL["****C2E0*"] = "U' R U2 R' U R U R'";
    algo_2FL["****C1E1*"] = "U2 R U' R' U' F' U' F";
    algo_2FL["****C2E1*"] = "U F' U' F U' R U R'";
    // Coin et arrete en place
    algo_2FL["*****E0C2"] = "R U R' U' R U2 R' U' R U R'";
    algo_2FL["*****E0C0"] = "";
    algo_2FL["*****E1C0"] = "R U' R' U y' R' U2 R U2 R' U R";
    algo_2FL["*****E0C1"] = "R U R' U2 R U' R' U R U R'";
    algo_2FL["*****E1C2"] = "F' U F U2 R U R' U R U' R'";
    algo_2FL["*****E1C1"] = "R U R' U' R U' R' U2 F' U' F";
}

