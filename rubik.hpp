#pragma once 

#include <iostream>
#include <string>

#define R1 0
#define R2 1
#define R3 2
#define R4 3
#define R5 4
#define R6 5
#define R7 6
#define R8 7
#define R9 8

#define D1 9
#define D2 10
#define D3 11
#define D4 12
#define D5 13
#define D6 14
#define D7 15
#define D8 16
#define D9 17

#define F1 18
#define F2 19
#define F3 20
#define F4 21
#define F5 22
#define F6 23
#define F7 24
#define F8 25
#define F9 26

#define U1 27
#define U2 28
#define U3 29
#define U4 30
#define U5 31
#define U6 32
#define U7 33
#define U8 34
#define U9 35

#define L1 36
#define L2 37
#define L3 38
#define L4 39
#define L5 40
#define L6 41
#define L7 42
#define L8 43
#define L9 44

#define B1 45
#define B2 46
#define B3 47
#define B4 48
#define B5 49
#define B6 50
#define B7 51
#define B8 52
#define B9 53

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
    int& s(int position){
        return rubik[position / 9][position % 9];
    }

    // void rotate(char faceid, int direction);

    void horizontalMove(int direction, int rank);
    void verticalMove(int direction, int rank);
    void faceMove(int direction);
    void backMove(int direction);


    void moveU();
    void moveUPrime();
    void moveD();
    void moveDPrime();
    void moveR();
    void moveRPrime();
    void moveL();
    void moveLPrime();
    void moveF();
    void moveFPrime();
    void moveB();
    void moveBPrime();

    




};

int print_ascii_rubik(Rubik &rk);
