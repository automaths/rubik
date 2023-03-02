#include "../Cubos.hpp"
#include <sstream>

string formula_reverser(string formula)
{
    string parsed;
    stringstream input_ss(formula);
    list<string> moves;

    while (getline(input_ss, parsed, ' '))
        moves.push_front(parsed);

    string result = "";
    for (auto move : moves)
    {
        if (move.size() > 1)
        {
            if (move[1] == '\'')
                result += move.substr(0, 1) + " ";
            else if (move[1] == '2')
                result += move + " ";
        }
        else
            result += move + "\' ";
    }
    return result;
}

bool algo_checker(std::string (Cube::*tostr)(), map<string, string> algos)
{
    for (auto algo : algos)  {

        Cube cube;
        cube.apply_moves(formula_reverser(algo.second));
        bool good = false;
        for (int i = 0; i < 4; ++i)
        {
            if (algos == Cube::algo_PLL)
                cube.rotate('u', 1);
            if ((cube.*tostr)() == algo.first)
                good = true;
        }
        if (!good)
        {
            cout << "ERROR: " << algo.first << endl;
            return false;
        }
    }
    return true;
}
