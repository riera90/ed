#ifndef _POINT_H_
#define _POINT_H_

#include <string>
#include <sstream>
#include <iostream>

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

	void SetPointString(std::string point);
	std::string getPointString() const ;

	void readPointStdin();
	void writePointStdout() const ;

	//asignation operators and copy constructor are not necesary as dinamic memory is not used.
};

#endif
