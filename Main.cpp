#include "stdafx.h"
#include "Model.h"
#include <iostream>

using namespace System;
using namespace std;

int main(array<System::String ^> ^args)
{
    char c[3][3] = { { 'x', 'x', ' ' }, { 'o', 'x', 'x' }, { ' ', 'o', 'o' } };
    Init(c);
    switch (GetWinner()){
    case DRAW: cout << "Game is a Draw" << endl; break;
    case XWINS: cout << "X wins the Game" << endl; break;
    case OWINS: cout << "O wins the Game" << endl; break;
    case CONTINUE: cout << "Continue playing the Game" << endl; break;
    }
    cout << "Move " << Move(0, 2, 'x') << endl;
    cout << "Move " << Move(0, 2, 'o') << endl;
    cout << "Move " << Move(2, 0, 'x') << endl;
    char ch[3][3];
    GetBoard(ch);
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            cout << ch[row][col];
        }
    }
    switch (GetWinner()){
    case DRAW: cout << "Game is a Draw" << endl; break;
    case XWINS: cout << "X wins the Game" << endl; break;
    case OWINS: cout << "O wins the Game" << endl; break;
    case CONTINUE: cout << "Continue playing the Game" << endl; break;
    }
    return 0;
}
