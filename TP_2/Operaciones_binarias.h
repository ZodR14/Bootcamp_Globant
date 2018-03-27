#pragma once
#define BIN_AND(x,y) (x&y)
#define BIN_OR(x,y) (x|y)
#define BIN_SR(x,y) (x >> 2)
#define BIN_SL(x,y) (x << 2)

int BinaryAnd(int a, int b);

int BinaryOr(int a, int b);

int ShiftRight(int a);

int Shiftleft(int a);