#include "Point3D.hpp"

std::string Point3D::getPointString(){
	std::ostringstream stream;
	stream<<getX()<<","<<getY()<<","<<getZ();
	return stream.str();
}
