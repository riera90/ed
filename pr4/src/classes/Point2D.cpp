/*!
	\file Point2D.cpp
	\brief cpp de la clase Point2D
*/

#include "Point2D.hpp"

void Point2D::SetPointString(std::string point){
	std::string x,y;

	x=point.substr(0,point.find(" "));
	point=point.substr(point.find(" ")+1,point.size());

	y=point.substr(0,point.size());

	this->setX(atof(x.c_str()));
	this->setY(atof(y.c_str()));
}

std::string Point2D::getPointString() const {
	std::ostringstream stream;
	stream<<getX()<<" "<<getY();
	return stream.str();
}

void Point2D::readPointStdin(){
	std::string input;
	std::getline(std::cin,input);
	SetPointString(input);
}

void Point2D::writePointStdout() const {
	std::cout <<this->getPointString()<<"\n";
}

bool Point2D::operator==(const Point2D &point) const {
	if (point.getX()!=this->getX()) return false;
	if (point.getY()!=this->getY()) return false;
	return true;
}

Point2D& Point2D::operator=(const Point2D &point){
	this->setX(point.getX());
	this->setY(point.getY());
	return *this;
}

float Point2D::distance(const Point2D& point) const {
	float difX,difY;

	difX=pow(this->getX()-point.getX(),2);
	difY=pow(this->getY()-point.getY(),2);

	return (float) sqrt(difX+difY);
}
