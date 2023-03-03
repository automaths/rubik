
#include "../Cubos.hpp"
#include <algorithm>

void print_res(Cube rk)
{
    string res = y_translator(Cube::res_moves);
    string res2 = clean_formula(res);
    Cube rk2 = rk;

    rk.apply_moves(res);
    rk2.apply_moves(res2);
    if (!rk.is_solved())
    {
        cout << "Error: failed solve with y_translator. " << res << endl;
        print_ascii_rubik(rk);
        exit(1);
    }
    if (!rk2.is_solved())
    {
        cout << "Error: failed solve with clean formula. " << res2 << endl;
        print_ascii_rubik(rk2);
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
            cout << "Incorrect move: '" << move << "'. Please provide only F R U B L D moves and their declinations" << endl;
            return (false);
        }
    }
    return (true);
}

int main(int argc, char **argv)
{
    Cube::init_members();
    if (argc == 1 || (argc == 3 && string(argv[1]) != "-g") || argc > 3)
    {
        cout << "Wrong number of arguments, please provide rubik cube's instructions as a string" << endl;
        cout << "  or use -g <number> for generate random mix." << endl;
        return (0);
    }
    Cube   rk;
    string argz(argv[1]);
    if (string(argv[1]) == "-g")
    {
        int nb_moves = 100;
        if (argc >= 3)
            nb_moves = atoi(argv[2]);
        if (nb_moves == 0)
        {
            cout << "Wrong number of moves, please provide a number > 0" << endl;
            return (0);
        }
        rk.shuffle(nb_moves);
        cout << "Generated random mix: " << Cube::res_moves << endl;
    }
    else if (!check_string(argv[1]))
        return (0);
    else
        rk.apply_moves(argz);

    Cube   cpy = rk;
    astar_for_cross(rk);
    rk.solve_2FL_v2();
    rk.solve_OLL();
    rk.solve_PLL();

    print_res(cpy);
    return (0);
}
