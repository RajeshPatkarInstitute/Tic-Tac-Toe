#include "stdafx.h"
#include "Model.h"
static char board[3][3] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
static char lastchar = ' ';

static bool IsSymbol(char symbol){
    return symbol == ' ' || symbol == 'x' || symbol == 'o';
}

static bool IsEmpty(int row, int col){
    return board[row][col] == ' ';
}

static bool IsValidRow(int row){
    return row >= 0 && row <= 2;
}

static bool IsValidColumn(int col){
    return col >= 0 && col <= 2;
}

static bool IsRepeatMove(char symbol){
    return symbol == lastchar;
}

void Init(){
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            board[row][col] = ' ';
        }
    }
}

void Init(char prefill[3][3]){
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            board[row][col] = prefill[row][col];
        }
    }
}

bool Move(int row, int col, char symbol){
    bool flag = false;
    if ( 
        IsSymbol(symbol) && 
        IsValidRow(row)  && 
        IsValidColumn(col) && 
        IsEmpty(row, col) && 
        !IsRepeatMove(symbol)
       )
    {
        board[row][col] = symbol;
        flag = true;
        lastchar = symbol;
    }
    return flag;
}

char *GetRow(Rows row,char *vm){
    for (int i = 0; i < 3; i++){
        vm[i] = board[row][i];
    }
    return vm;
}

char *GetColumn(Columns column,char *vm){
    for (int i = 0; i < 3; i++){
        vm[i] = board[i][column];
    }
    return vm;
}

char *GetDiagonal(Diagonals diagonal,char *vm){
    if (diagonal){
        vm[0] = board[0][2]; vm[1] = board[1][1]; vm[2]=board[2][0];
    }
    else{
        vm[0] = board[0][0]; vm[1] = board[1][1]; vm[2] = board[2][2];
    }
    return vm;
}

 char(*GetBoard(char b[3][3]))[3]{
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            b[row][col] = board[row][col];
        }
    }
    return b;
}

static bool XwinsSlot(char *vm){
    return vm[0] == Symbols::X && vm[1] == Symbols::X && vm[2] == Symbols::X;
}

static bool OwinsSlot(char *vm){
    return vm[0] == Symbols::O && vm[1] == Symbols::O && vm[2] == Symbols::O;
}


static bool Xwins(){
    char slot[3];
    for (int i = 0; i < 3 ; i++){
        if (XwinsSlot(GetRow((Rows)i, slot)) || XwinsSlot(GetColumn((Columns)i, slot)))
            return true;
    }
    if (XwinsSlot(GetDiagonal(D1, slot)) || XwinsSlot(GetDiagonal(D2, slot))) 
            return true;
    return false;
}

static bool Owins(){
    char slot[3];
    for (int i = 0; i < 3; i++){
        if (OwinsSlot(GetRow((Rows)i, slot)) || OwinsSlot(GetColumn((Columns)i, slot)))
            return true;
    }
    if (OwinsSlot(GetDiagonal(D1, slot)) || OwinsSlot(GetDiagonal(D2, slot)))
            return true;
    return false;
}

static bool IsDraw(){
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            if (IsEmpty(row, col)) return false;
        }
    }
    return true;
}

Result GetWinner(){
    if (Xwins()) return XWINS;
    if (Owins()) return OWINS;
    if (IsDraw()) return DRAW;
    return CONTINUE;
}
