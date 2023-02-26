#pragma once 

#include <iostream>
#include <string>

using namespace std;

class Rubik {
    private:
    int rubik[6][9];

    public:
    Rubik(int bloup){
        for (int i = 0; i < 6; ++i)
            for(int j = 0; j < 9; ++j)
            {
                if (41 + i == 46)
                    rubik[i][j] = 47;
                else
                    rubik[i][j] = 41 + i;
            }
    }
    int& s(int position)
    {
        return rubik[position / 9][position % 9];
    }
};

int print_ascii_rubik();
