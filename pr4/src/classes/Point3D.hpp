#ifndef _POINT_H_
#define _POINT_H_

#include <string>
#include <sstream>

class Point3D {
private:
	float _x;
	float _y;
	float _z;

public:

	Point3D (float x=0, float y=0, float z=0) : _x(x), _y(y), _z(z) {};

	void setX(float x) { _x=x; }
	float getX() const { return _x; }

	void setY(float y) { _y=y; }
	float getY() const { return _y; }

	void setZ(float z) { _z=z; }
	float getZ() const { return _z; }

	std::string getPointString() const ;
};

#endif
