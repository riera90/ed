/*!
	\file FileWrapper.cpp
	\brief cpp de la clase FileWrapper
*/

#include "FileWrapper.hpp"

bool FileWrapper::write(DenseGraph graph){
	std::ofstream file;
	file.open(_fileName.c_str());
	if(!file.is_open()){
		std::cout << "ERROR, the file could not be oppened" << '\n';
		return false;
	}

	std::cout << "this is not implemented, as is not requiered by the assigment" << '\n';

	file.close();
	if (file.is_open()) {
		std::cout << "ERROR, the file could not be oppened" << '\n';
		return false;
	}
	return true;
}

DenseGraph FileWrapper::read(){
	std::ifstream file;
	file.open(_fileName.c_str());
	if(!file.is_open()){
		std::cout << "ERROR, the file could not be oppened" << '\n';
		return DenseGraph();
	}
	DenseGraph graph;

	char cache_char[1000];
	std::string cache, line;
	float x,y;
	int position;


	file.getline(cache_char, 100, '\n');
	line=cache_char;

	while (line!=""){
		position=line.find(" ",0);
		cache=line.substr(0,position);
		line=line.substr(position+1,line.size());
		x=atof(cache.c_str());
		y=atof(line.c_str());

		graph.addVertex(new Vertex(Point2D(x,y)));

		file.getline(cache_char, 100, '\n');
		line=cache_char;
	}



	file.close();
	if (file.is_open()) {
		std::cout << "ERROR, the file could not be oppened" << '\n';
		return DenseGraph();
	}
	return graph;
}
