/*!
	\file FileWrapper.hpp
	\brief clase FileWrapper
*/


#ifndef _FILE_WRAPPER_
#define _FILE_WRAPPER_

#include <iostream>
#include <fstream>

#include "DenseGraph.hpp"

class FileWrapper {
private:
	std::string _fileName;

public:
	FileWrapper (std::string fileName) { _fileName=fileName; };

	inline void setFilename(std::string fileName){_fileName=fileName;}

	bool write(DenseGraph graph);
	DenseGraph read();
};

#endif
