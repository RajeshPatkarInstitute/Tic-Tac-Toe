#include "stdafx.h"

enum Result { DRAW, XWINS, OWINS, CONTINUE };
enum Rows{ R1, R2, R3 };
enum Columns{ C1, C2, C3};
enum Diagonals { D1, D2};
enum Symbols { SPACE = ' ', X = 'x', O = 'o' };

void Init();
void Init(char prefill[3][3]);
bool Move(int row, int col, char symbol);
Result GetWinner();
char* GetRow(Rows row,char *vm);
char* GetColumn(Columns columns,char *vm);
char* GetDiagonal(Diagonals diagonal,char *vm);
char (*GetBoard(char vm[3][3]))[3];
