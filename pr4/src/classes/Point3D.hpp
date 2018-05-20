#ifndef _POINT_H_
#define _POINT_H_

#include <sstream> //string included in this library
#include <iostream>
#include <cmath>

class Point3D {
private:
	float _x;
	float _y;
	float _z;

public:

	inline Point3D (float x=0, float y=0, float z=0) : _x(x), _y(y), _z(z) {};
	inline Point3D (const Point3D& point){*this=point;};

	inline float getX() const { return _x; }
	inline float getY() const { return _y; }
	inline float getZ() const { return _z; }

	inline void setX(float x) { _x=x; }
	inline void setZ(float z) { _z=z; }
	inline void setY(float y) { _y=y; }

	void SetPointString(std::string point);
	std::string getPointString() const ;

	void readPointStdin();
	void writePointStdout() const ;

	bool operator==(const Point3D& point) const ;
	inline bool operator!=(const Point3D& point) const {
		return (!(*this==point));
	};
	
	Point3D& operator=(const Point3D& point);

	float distance(const Point3D& point) const ;
};

#endif
