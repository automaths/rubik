
#include "../Cubos.hpp"

void test_res()
{
    Cube rk;
    string res = formula_cleaner(Cube::res_moves);
    cout << res << endl;
    rk.apply_moves(res);
    print_ascii_rubik(rk);
}

int main()
{
    Cube::init_members();
    Cube   rk;

    // algo_checker(&Cube::to_string_2FL, Cube::algo_2FL);
    // cout << "2FL algos checked." << endl;
    // algo_checker(&Cube::to_string_OLL, Cube::algo_OLL);
    // cout << "OLL algos checked." << endl;
    // algo_checker(&Cube::to_string_PLL, Cube::algo_PLL);
    // cout << "PLL algos checked." << endl;
    // exit(0);


    for (int i = 0; i < 1; ++i)
    {
        rk.shuffle();
        astar_for_cross(rk);
        test_res();
        rk.solve_2FL_v2();
        test_res();
        rk.solve_OLL();
        test_res();
        rk.solve_PLL();
        test_res();
    }

}