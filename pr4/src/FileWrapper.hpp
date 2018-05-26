/*!
	\file FileWrapper.hpp
	\brief clase FileWrapper
*/


#ifndef _FILE_WRAPPER_
#define _FILE_WRAPPER_

#include <iostream>
#include <fstream>

#include "DenseGraph.hpp"

//!< Definicion de la clase FileWrapper
class FileWrapper {
private:
	std::string _fileName; //!< string con el nombre del fichero

public:
	/*!
		\brief		constructor de la clase FileWrapper
		\param		fileName: nombre del fichero
		\note			function inline
	*/
	inline FileWrapper (std::string fileName) { _fileName=fileName; };

	/*!
		\brief		modificador del nombre del fichero
		\param		fileName: nuebo nombre de fichero
		\note			function inline
	*/
	inline void setFilename(std::string fileName){_fileName=fileName;}

	/*!
		\brief		modificador de fichero de escritura
		\param		graph: grafo a escribir en el fichero
		\return		booleano si la operacion se llebo a cabo con exito, falso en el caso contrario
	*/
	bool write(DenseGraph graph);

	/*!
		\brief		observador de lectura del fichero
		\return		grafo leido del fichero
	*/
	DenseGraph read();
};

#endif
