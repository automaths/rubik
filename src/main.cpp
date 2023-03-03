
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

bool check_string(string argz)
{
    string parsed;
    stringstream input_ss(argz);
    list<string> moves;

    list<string> authorized ({"F", "F'", "F2", "R", "R'", "R2", "U", "U'", "U2", "B", "B'", "B2", "L", "L'", "L2", "D", "D'", "D2"});
    while (getline(input_ss, parsed, ' '))
        moves.push_front(parsed);
    for (auto move : moves)
    {
        if (std::find(std::begin(authorized), std::end(authorized), move) == std::end(authorized) && move != "")
        {
            cout << "Incorrect move set: " << move << ", please provide only F R U B L D moves and their declinations" << endl;
            return (false);
        }
    }
    return (true);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "Wrong arguments, please provide rubik cube's instructions as a string" << endl;
        return (0);
    }
    else if (!check_string(argv[1]))
        return (0);
    Cube::init_members();
    Cube   rk;
    string argz(argv[1]);
    rk.apply_moves(argz);
    astar_for_cross(rk);
    rk.solve_2FL_v2();
    rk.solve_OLL();
    rk.solve_PLL();

    //display

    return (0);
}

// Main for Algorithms Check  
// int main(int argc, char **argv)
// {
    // algo_checker(&Cube::to_string_2FL, Cube::algo_2FL);
    // cout << "2FL algos checked." << endl;
    // algo_checker(&Cube::to_string_OLL, Cube::algo_OLL);
    // cout << "OLL algos checked." << endl;
    // algo_checker(&Cube::to_string_PLL, Cube::algo_PLL);
    // cout << "PLL algos checked." << endl;
    // exit(0);
    // Cube::init_members();
    // Cube   rk;
    // for (int i = 0; i < 1; ++i)
    // {
    //     rk.shuffle();
    //     Cube cpy = rk;
    //     print_ascii_rubik(rk);

    //     astar_for_cross(rk);
    //     rk.solve_2FL_v2();
    //     rk.solve_OLL();
    //     rk.solve_PLL();

    //     test_res(cpy);
    //     cout << "====================" << endl;
        // cout << formula_cleaner(Cube::res_moves) << endl;
    // }
// }