#pragma once
#define PRNT_LIT() (std::cout << "Esto es un texto literal?." << std::endl)
#define CONC(a,b) a##b
#define NOMB(a,b) #a#b
#include <iostream>

void PrintLiteral();