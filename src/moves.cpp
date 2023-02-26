#include "../rubik.hpp"

// U 2U U' D 2D D'         R 2R R' L 2L L'          F 2F F' B 2B B'

void Rubik::horizontalMove(int direction, int rank){
    int tmpL;
    int tmpB;
    int tmpR;
    int tmpF;
    int tmp1 = s(U1);
    int tmp2 = s(U2);
    int tmp3 = s(U3);
    int tmp4 = s(U4);
    int tmp5 = s(U5);
    int tmp6 = s(U6);
    int tmp7 = s(U7);
    int tmp8 = s(U8);
    int tmp9 = s(U9);

    if (!direction)
    {
        for (int i = 0; i < 3; ++i)
        {
            tmpL = s(L1 + i + (rank * 6));
            tmpB = s(B1 + i + (rank * 6));
            tmpR = s(R1 + i + (rank * 6));
            tmpF = s(F1 + i + (rank * 6));
            s(L1 + i + (rank * 6)) = tmpF;
            s(B1 + i + (rank * 6)) = tmpL;
            s(R1 + i + (rank * 6)) = tmpB;
            s(F1 + i + (rank * 6)) = tmpR;
        }
        s(U1) = tmp3;
        s(U2) = tmp6;
        s(U3) = tmp9;
        s(U4) = tmp2;
        s(U5) = tmp5;
        s(U6) = tmp8;
        s(U7) = tmp1;
        s(U8) = tmp4;
        s(U9) = tmp7;
    }
    else
    {
        for (int i = 0; i < 3; ++i)
        {
            tmpL = s(L1 + i + (rank * 6));
            tmpB = s(B1 + i + (rank * 6));
            tmpR = s(R1 + i + (rank * 6));
            tmpF = s(F1 + i + (rank * 6));
            s(R1 + i + (rank * 6)) = tmpF;
            s(B1 + i + (rank * 6)) = tmpR;
            s(L1 + i + (rank * 6)) = tmpB;
            s(F1 + i + (rank * 6)) = tmpL;
        }
        s(U1) = tmp7;
        s(U2) = tmp4;
        s(U3) = tmp1;
        s(U4) = tmp8;
        s(U5) = tmp5;
        s(U6) = tmp2;
        s(U7) = tmp9;
        s(U8) = tmp6;
        s(U9) = tmp3;
    }
}

void Rubik::verticalMove(int direction, int rank){
    int tmpU;
    int tmpB;
    int tmpD;
    int tmpF;
    int tmp1 = s(R1);
    int tmp2 = s(R2);
    int tmp3 = s(R3);
    int tmp4 = s(R4);
    int tmp5 = s(R5);
    int tmp6 = s(R6);
    int tmp7 = s(R7);
    int tmp8 = s(R8);
    int tmp9 = s(R9);
    int tmpl1 = s(L1);
    int tmpl2 = s(L2);
    int tmpl3 = s(L3);
    int tmpl4 = s(L4);
    int tmpl5 = s(L5);
    int tmpl6 = s(L6);
    int tmpl7 = s(L7);
    int tmpl8 = s(L8);
    int tmpl9 = s(L9);

    if (!direction)
    {
        for (int i = 0; i < 3; ++i)
        {
            tmpU = s(U1 + (i * 3) + (rank * 2));
            tmpB = s(B1 + (i * 3) + (rank * 2));
            tmpD = s(D1 + (i * 3) + (rank * 2));
            tmpF = s(F1 + (i * 3) + (rank * 2));
            s(D1 + (i * 3) + (rank * 2)) = tmpB;
            s(B1 + (i * 3) + (rank * 2)) = tmpU;
            s(U1 + (i * 3) + (rank * 2)) = tmpF;
            s(F1 + (i * 3) + (rank * 2)) = tmpD;
        }
        if (rank)
        {
            s(R1) = tmp3;
            s(R2) = tmp6;
            s(R3) = tmp9;
            s(R4) = tmp2;
            s(R5) = tmp5;
            s(R6) = tmp8;
            s(R7) = tmp1;
            s(R8) = tmp4;
            s(R9) = tmp7;
        }
        else
        {
            s(L1) = tmpl3;
            s(L2) = tmpl6;
            s(L3) = tmpl9;
            s(L4) = tmpl2;
            s(L5) = tmpl5;
            s(L6) = tmpl8;
            s(L7) = tmpl1;
            s(L8) = tmpl4;
            s(L9) = tmpl7;
        }
    }
    else
    {
        for (int i = 0; i < 3; ++i)
        {
            tmpU = s(U1 + (i * 3) + (rank * 2));
            tmpB = s(B1 + (i * 3) + (rank * 2));
            tmpD = s(D1 + (i * 3) + (rank * 2));
            tmpF = s(F1 + (i * 3) + (rank * 2));
            s(U1 + (i * 3) + (rank * 2)) = tmpB;
            s(B1 + (i * 3) + (rank * 2)) = tmpD;
            s(D1 + (i * 3) + (rank * 2)) = tmpF;
            s(F1 + (i * 3) + (rank * 2)) = tmpU;
        }
        if (rank)
        {
            s(R1) = tmp7;
            s(R2) = tmp4;
            s(R3) = tmp1;
            s(R4) = tmp8;
            s(R5) = tmp5;
            s(R6) = tmp2;
            s(R7) = tmp9;
            s(R8) = tmp6;
            s(R9) = tmp3;
        }
        else
        {
            s(L1) = tmpl7;
            s(L2) = tmpl4;
            s(L3) = tmpl1;
            s(L4) = tmpl8;
            s(L5) = tmpl5;
            s(L6) = tmpl2;
            s(L7) = tmpl9;
            s(L8) = tmpl6;
            s(L9) = tmpl3;
        }
    }
}

void Rubik::faceMove(int direction){
    int tmpU;
    int tmpR;
    int tmpD;
    int tmpL;
    int tmp1 = s(F1);
    int tmp2 = s(F2);
    int tmp3 = s(F3);
    int tmp4 = s(F4);
    int tmp5 = s(F5);
    int tmp6 = s(F6);
    int tmp7 = s(F7);
    int tmp8 = s(F8);
    int tmp9 = s(F9);

    if (!direction)
    {
        for (int i = 0; i < 3; ++i)
        {
            tmpU = s(U9 - i);
            tmpR = s(R7 - (i * 3));
            tmpD = s(D3 - i);
            tmpL = s(L9 - (i * 3));
            s(R7 - (i * 3)) = tmpU;
            s(D3 - i) = tmpR;
            s(L9 - (i * 3)) = tmpD;
            s(U9 - i) = tmpL;
        }
        s(F1) = tmp3;
        s(F2) = tmp6;
        s(F3) = tmp9;
        s(F4) = tmp2;
        s(F5) = tmp5;
        s(F6) = tmp8;
        s(F7) = tmp1;
        s(F8) = tmp4;
        s(F9) = tmp7;
    }
    else
    {
        for (int i = 0; i < 3; ++i)
        {
            tmpU = s(U9 - i);
            tmpR = s(R7 - (i * 3));
            tmpD = s(D3 - i);
            tmpL = s(L9 - (i * 3));
            s(R7 - (i * 3)) = tmpD;
            s(D3 - i) = tmpL;
            s(L9 - (i * 3)) = tmpU;
            s(U9 - i) = tmpR;
        }
        s(F1) = tmp7;
        s(F2) = tmp4;
        s(F3) = tmp1;
        s(F4) = tmp8;
        s(F5) = tmp5;
        s(F6) = tmp2;
        s(F7) = tmp9;
        s(F8) = tmp6;
        s(F9) = tmp3;
    }
}

void Rubik::backMove(int direction){
    int tmpU;
    int tmpR;
    int tmpD;
    int tmpL;
    int tmp1 = s(B1);
    int tmp2 = s(B2);
    int tmp3 = s(B3);
    int tmp4 = s(B4);
    int tmp5 = s(B5);
    int tmp6 = s(B6);
    int tmp7 = s(B7);
    int tmp8 = s(B8);
    int tmp9 = s(B9);

    if (!direction)
    {
        for (int i = 0; i < 3; ++i)
        {
            tmpU = s(U1 + i);
            tmpR = s(R3 + (i * 3));
            tmpD = s(D9 - i);
            tmpL = s(L7 - (i * 3));
            s(L7 - (i * 3)) = tmpU;
            s(U1 + i) = tmpR;
            s(R3 + (i * 3)) = tmpD;
            s(D9 - i) = tmpL;
        }
        s(B1) = tmp7;
        s(B2) = tmp4;
        s(B3) = tmp1;
        s(B4) = tmp8;
        s(B5) = tmp5;
        s(B6) = tmp2;
        s(B7) = tmp9;
        s(B8) = tmp6;
        s(B9) = tmp3;
    }
    else
    {
        for (int i = 0; i < 3; ++i)
        {
            tmpU = s(U1 + i);
            tmpR = s(R3 + (i * 3));
            tmpD = s(D9 - i);
            tmpL = s(L7 - (i * 3));
            s(L7 - (i * 3)) = tmpD;
            s(U1 + i) = tmpL;
            s(R3 + (i * 3)) = tmpU;
            s(D9 - i) = tmpR;
        }
        s(B1) = tmp3;
        s(B2) = tmp6;
        s(B3) = tmp9;
        s(B4) = tmp2;
        s(B5) = tmp5;
        s(B6) = tmp8;
        s(B7) = tmp1;
        s(B8) = tmp4;
        s(B9) = tmp7;
    }
}

void Rubik::moveU(){
    horizontalMove(0, 0);
}

void Rubik::moveUPrime(){
    horizontalMove(1, 0);
}

void Rubik::moveD(){
    horizontalMove(0, 1);
}

void Rubik::moveDPrime(){
    horizontalMove(1, 1);
}

void Rubik::moveL(){
    verticalMove(1, 0);
}

void Rubik::moveLPrime(){
    verticalMove(0, 0);
}

void Rubik::moveR(){
    verticalMove(0, 1);
}

void Rubik::moveRPrime(){
    verticalMove(1, 1);
}

void Rubik::moveF(){
    faceMove(0);
}

void Rubik::moveFPrime(){
    faceMove(1);
}

void Rubik::moveB(){
    backMove(0);
}

void Rubik::moveBPrime(){
    backMove(1);
}


