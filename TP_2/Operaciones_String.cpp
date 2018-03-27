#include "Operaciones_String.h"
#define COMP_STR(a,b) if (sizeof(a) != sizeof(b)) { \
							return false;\
						}\
						for (int i = 0; i < sizeof(a); i++) {\
							if (a[i] != b[i]) return false;\
						}\
						return true;




bool CompareStrings(const char* a, const char* b) {
	COMP_STR(a, b);
}

std::string SonIgualesSignoDePregunta(char a[], char b[]) {
	return CompareStrings(a, b) ? "SON IGUALES" : "SON DIFERENTES";
}