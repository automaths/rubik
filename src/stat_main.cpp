#include "../Cubos.hpp"

void print_res(Cube rk)
{
    string res = y_translator(Cube::res_moves);
    string res2 = clean_formula(res);
    Cube rk2 = rk;
    rk.apply_moves(res);
    rk2.apply_moves(res2);
    if (!rk.is_solved())
    {
        cout << "Error: failed solve with y_translator. " << endl;
        print_ascii_rubik(rk);
        exit(1);
    }
    if (!rk2.is_solved())
    {
        cout << "Error: failed solve with clean formula. " << endl;
        print_ascii_rubik(rk);
        exit(1);
    }
    cout << res2 << endl;
}

// Main for Algorithms Check  
int main()
{
    // algo_checker(&Cube::to_string_2FL, Cube::algo_2FL);
    // cout << "2FL algos checked." << endl;
    // algo_checker(&Cube::to_string_OLL, Cube::algo_OLL);
    // cout << "OLL algos checked." << endl;
    // algo_checker(&Cube::to_string_PLL, Cube::algo_PLL);
    // cout << "PLL algos checked." << endl;
    // exit(0);

    Cube::init_members();
    int nb_moves_tot = 0;
    int nb_echantillion = 0;

    Cube   rk;
    for (int i = 0; i < 100; ++i)
    {
        rk.shuffle();
        Cube cpy = rk;
        // print_ascii_rubik(rk);

        astar_for_cross(rk);
        rk.solve_2FL_v2();
        rk.solve_OLL();
        rk.solve_PLL();


        print_res(cpy);
        // Stats
        nb_moves_tot += Cube::nb_moves;
        nb_echantillion++;
        cout << "Optimized formula: " << Cube::nb_moves << " moves" << endl;
        cout << "Mean: " << nb_moves_tot / nb_echantillion << " moves on " << nb_echantillion << " samples." << endl;
        
        cout << "====================" << endl;
    }
}
