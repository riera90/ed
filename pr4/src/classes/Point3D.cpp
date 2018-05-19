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
