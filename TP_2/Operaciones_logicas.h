#pragma once
#define SWAP(a,b) int aux = *a;\
					*a = *b;\
					*b = aux;

void Swap(int* a, int* b);