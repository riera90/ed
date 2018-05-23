#ifndef _POINT_HPP_
#define _POINT_HPP_

#include <sstream> //string included in this library
#include <iostream>
#include <cmath>

class Point2D {
private:
	float _x;
	float _y;

public:

	inline Point2D (float x=0, float y=0) : _x(x), _y(y) {};
	inline Point2D (const Point2D& point){*this=point;};

	inline float getX() const { return _x; }
	inline float getY() const { return _y; }

	inline void setX(float x) { _x=x; }
	inline void setY(float y) { _y=y; }

	void SetPointString(std::string point);
	std::string getPointString() const ;

	void readPointStdin();
	void writePointStdout() const ;

	bool operator==(const Point2D& point) const ;
	inline bool operator!=(const Point2D& point) const {
		return (!(*this==point));
	};

	Point2D& operator=(const Point2D& point);

	float distance(const Point2D& point) const ;
};

#endif
