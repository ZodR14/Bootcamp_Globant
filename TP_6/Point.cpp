#include "Point.h"
#include <assert.h>

namespace cpp_math {
	Point::Point() : mX(new float(0)), mY(new float(0)), mZ(new float(0)) {
		
	}

	Point::Point(float x, float y, float z) : mX(new float(x)), mY(new float(y)), mZ(new float(z)) {

	}

	Point::Point(const Point& other) {
		mX = new float(*other.mX);
		mY = new float(*other.mY);
		mZ = new float(*other.mZ);
	}

	Point Point::operator=(Point other) {
		*mX = (*other.mX);
		*mY = (*other.mY);
		*mZ = (*other.mZ);

		return *this;
	}

	float Point::getX() const {
		return *mX;
	};

	float Point::getY() const {
		return *mY;
	};

	float Point::getZ() const {
		return *mZ;
	};

	void Point::setX(float x) {
		*mX = x;
	};

	void Point::setY(float y) {
		*mY = y;
	};

	void Point::setZ(float z) {
		*mZ = z;
	};

	void Point::setXY(float x, float y) {
		*mX = x;
		*mY = y;
	};

	void Point::setYZ(float y, float z) {
		*mY = y;
		*mZ = z;
	}

	void Point::setXYZ(float x, float y, float z) {
		*mX = x;
		*mY = y;
		*mZ = z;
	}

	Point Point::getAddition(const Point& p){
		return Point(*mX + p.getX(), *mY + p.getY(), *mZ + p.getZ());
	};

	Point Point::add(const Point& p) {
		*mX += p.getX();
		*mY += p.getY();
		*mZ += p.getZ();

		return *this;
	};

	Point Point::getSubtraction(const Point& p) {
		return Point(*mX - p.getX(), *mY - p.getY(), *mZ - p.getZ());
	};

	Point Point::subtract(const Point& p) {
		*mX -= p.getX();
		*mY -= p.getY();
		*mZ -= p.getZ();

		return *this;
	};

	Point::~Point(){
		delete mX,mY,mZ;
	}
}
