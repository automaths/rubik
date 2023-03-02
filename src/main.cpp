
#include "../Cubos.hpp"

int main()
{
    Cube::init_members();
    Cube   rk;

    algo_checker(&Cube::to_string_2FL, Cube::algo_2FL);
    cout << "2FL algos checked." << endl;
    algo_checker(&Cube::to_string_OLL, Cube::algo_OLL);
    cout << "OLL algos checked." << endl;
    algo_checker(&Cube::to_string_PLL, Cube::algo_PLL);
    cout << "PLL algos checked." << endl;

    // print_ascii_rubik(rk);
    // rk.rotate('r', 1);
    // rk.rotate('u', 1);
    // rk.rotate('f', 1);
    // cout << rk.corners["URF"].orientation << endl;
    // cout << rk.to_string_2FL() << endl;
    // print_ascii_rubik(rk);
    // exit(0);
    for (int i = 0; i < 1; ++i)
    {
        rk.shuffle();
        astar_for_cross(rk);
        rk.solve_2FL_v2();
        rk.solve_OLL();
        rk.solve_PLL();
    }
    // rk.find_2FL();
    print_ascii_rubik(rk);
    
}