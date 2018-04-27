#pragma once

namespace cpp_math {

	class Point
	{
	public:
		Point();
		~Point();
		Point(float x, float y, float z);
		Point(const Point& other);
		Point operator=(Point other);
		float getX() const;
		float getY() const;
		float getZ() const;
		void setX(float x);
		void setY(float y);
		void setZ(float z);
		void setXY(float x, float y);
		void setYZ(float y, float z);
		void setXYZ(float x, float y, float z);

		Point getAddition(const Point& p);
		Point add(const Point& p);

		Point getSubtraction(const Point& p);
		Point subtract(const Point& p);

	private:
		float *mX, *mY, *mZ;
	};

}