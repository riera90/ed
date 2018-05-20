#include "Point3D.hpp"

void Point3D::SetPointString(std::string point){
	std::string x,y,z;

	x=point.substr(0,point.find(" "));
	point=point.substr(point.find(" ")+1,point.size());

	y=point.substr(0,point.find(" "));
	point=point.substr(point.find(" ")+1,point.size());

	z=point.substr(0,point.size());

	this->setX(atof(x.c_str()));
	this->setY(atof(y.c_str()));
	this->setZ(atof(z.c_str()));
}

std::string Point3D::getPointString() const {
	std::ostringstream stream;
	stream<<getX()<<" "<<getY()<<" "<<getZ();
	return stream.str();
}

void Point3D::readPointStdin(){
	std::string input;
	std::getline(std::cin,input);
	SetPointString(input);
}

void Point3D::writePointStdout() const {
	std::cout <<this->getPointString()<<"\n";
}

bool Point3D::operator==(const Point3D &point) const {
	if (point.getX()!=this->getX()) return false;
	if (point.getY()!=this->getY()) return false;
	if (point.getZ()!=this->getZ()) return false;
	return true;
}

Point3D& Point3D::operator=(const Point3D &point){
	this->setX(point.getX());
	this->setY(point.getY());
	this->setZ(point.getZ());
	return *this;
}

float Point3D::distance(const Point3D& point) const {
	float difX,difY,difZ;

	difX=pow(this->getX()-point.getX(),2);
	difY=pow(this->getY()-point.getY(),2);
	difZ=pow(this->getZ()-point.getZ(),2);

	return (float) sqrt(difX+difY+difZ);
}
