#include <iostream>
#include "Point.h"

int main() {
	cpp_math::Point a(1,8,3);
	cpp_math::Point b;

	std::printf("%f, %f,%f \n",a.getX(),a.getY(),a.getZ());

	std::printf("%f, %f,%f \n", b.getX(), b.getY(), b.getZ());

	a = b;

	std::printf("%f, %f,%f \n", a.getX(), a.getY(), a.getZ());

	std::cin.ignore();
	return 0;
}