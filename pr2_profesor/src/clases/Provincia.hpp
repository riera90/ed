/*!
	\file  Provincia.hpp
	\brief Definición de la clase Provincia
	\author
	\date
	\version

*/

#ifndef _PROVINCIA_HPP_
#define _PROVINCIA_HPP_

// Para comprobar las pre y post condiciones
#include <cassert>

#include <string>


#include "ListaDoblementeEnlazadaOrdenadaMunicipios.hpp"
// #include "CSV_reader.hpp"
// #include "CSV_writer.hpp"
// #include "CSV_data.hpp"


// DEBES COMPLETAR O MODIFICAR EL CÓDIGO DE LA CLASE Provincia

// DEBES COMPLETAR LOS COMENTARIOS DE DOXYGEN

// IMPORTANTE
// Se incluyen los prototipos de las funciones virtuales que hay que redefinir
// Hay que incluir los prototipos de las demás funciones


/*!
	\namespace ed
	\brief Espacio de nombres para la Provincia Estructuras de Datos

*/
namespace ed{
/*!

  \class Provincia
  \brief Definición de la clase Provincia

*/
class Provincia
{
	//!	\name Métodos públicos de la clase Provincia

	private:
		std::string _nombre;   //!<  \brief Nombre de la Provincia
		int         _codigo;	  //!<  \brief Código de la Provincia
		ed::ListaDoblementeEnlazadaOrdenadaMunicipios _listaMunicipios; //!<  \brief Lista de municipios de la Provincia


	/////////////////////////////////////////////////////////////////////

	//!	\name  Métodos públicos de la clase Provincia

  public:

	//!	\name Constructor
	/*!
	\brief constructor con parametros opcionales de la provincia
	construye una provincia , la cual, si no tiene parametros tomará los valores
	predeterminados nombre="" y codigo=1
	\param nombre : nombre de la provincia (std::string)
	\param codigo : código de la provincia (int)
	*/
	Provincia(std::string nombre="", int codigo=0)
	: _nombre(nombre), _codigo(codigo) {};


	/////////////////////////////////////////////////////////////////////

	//!	\name Observadores
	/*!
	\brief observador de el nombre
	\return nombre: nombre de la provincia (std::string)
	\note funcion const e inline
	*/
	inline std::string getNombre() const {return _nombre;};

	/*!
	\brief observador de el codigo
	\return codigo: codigo de la provincia (integer)
	\note funcion const e inline
	*/
	inline int getCodigo() const {return _codigo;};

	//!	\name Observadores
	/*!
	\brief modificador de el nombre
	\param nombre: nombre de la provincia (std::string)
	\note funcion inline
	*/
	inline void setNombre(std::string nombre) {_nombre=nombre;};

	/*!
	\brief modificador de el codigo
	\param codigo: codigo de la provincia (integer)
	\note funcion inline
	*/
	inline void setCodigo(int codigo) {_codigo=codigo;};


	/*!
	\brief  Comprueba si la lista no está vacía
	\note   Función de tipo "const": no puede modificar al objeto actual
	\return true, si la lista no está vacía; false, en caso contrario
	\note   Función inline
	\note internamente se llama a ListaDoblementeEnlazadaOrdenadaMunicipios::isEmpty()
	*/
	inline bool hayMunicipios() const {return !_listaMunicipios.isEmpty();};

	/*!
	\brief  observador para el numero de municipios de la provincia
	\return entero: numero de municipios
	\note   Función de tipo "const": no puede modificar al objeto actual
	\note   Función inline
	\note internamente se llama a ListaDoblementeEnlazadaOrdenadaMunicipios::isEmpty()
	*/
	inline int getNumeroMunicipios() const {return _listaMunicipios.nItems();}

	/*!
	\brief  observador para un municipio de la lista
	\return Municipio: municipio de la lista de municipios
	\note   Función inline
	\note internamente se llama a ListaDoblementeEnlazadaOrdenadaMunicipios::find()
	*/
	inline Municipio getMunicipio(std::string nombre){
		ListaDoblementeEnlazadaOrdenadaMunicipios* it=new ListaDoblementeEnlazadaOrdenadaMunicipios(_listaMunicipios);
		Municipio municipio(nombre);
		if (it->find(municipio)){
			return it->getMunicipio();
		}else{
			municipio.setNombre("");
			return municipio;
		}
	}

	/*!
	\brief  observador logico para ver si existe otro elemento
	\return boolean: true si existe, false si es el ultimo
	\note   Función inline
	*/
	inline bool existeSiguiente(){
		return _listaMunicipios.existeSiguiente();
	}

	/*!
	\brief  observador para el numerto de Hombres de la provincia
	\return entero: numero de hombres de la provincia
	*/
	int getTotalHombres();

	/*!
	\brief  observador para el numerto de mujeres de la provincia
	\return entero: numero de mujeres de la provincia
	*/
	int getTotalMujeres();

	/*!
	\brief  observador para el numerto de habitantes de la provincia
	\return entero: numero de habitantes de la provincia
	\note   Función inline
	*/
	int getTotalHabitantes(){return getTotalHombres()+getTotalMujeres();};


	/////////////////////////////////////////////////////////////////////

	//!	\name Modificadores

	/*!
	\brief modifica el cursor para situarlo en primer municipio
	\pre no isEmpty()
	\post new.getCurrent()=old.getHead()
	\note internamente llama a ListaDoblementeEnlazadaOrdenadaMunicipios::gotoHead()
	\note function inline
	*/
	inline void gotoHead(){_listaMunicipios.gotoHead();};

	/*!
	\brief modifica el cursor para situarlo en el último municipio
	\pre no isEmpty()
	\post new.getCurrent()=old.getLast()
	\note internamente llama a ListaDoblementeEnlazadaOrdenadaMunicipios::gotoLast()
	\note function inline
	*/
	inline void gotoLast(){_listaMunicipios.gotoLast();};

	/*!
	\brief modifica el cursor para situarlo en el sigiente municipio
	\pre no isEmpty()
	\post new.getCurrent()=old.getNext()
	\note internamente llama a ListaDoblementeEnlazadaOrdenadaMunicipios::gotoNext()
	\note function inline
	*/
	inline void gotoNext(){_listaMunicipios.gotoNext();};

	/*!
	\brief modifica el cursor para situarlo en el anterior municipio
	\pre no isEmpty()
	\post new.getCurrent()=old.getPrevious()
	\note internamente llama a ListaDoblementeEnlazadaOrdenadaMunicipios::gotoPrevious()
	\note function inline
	*/
	inline void gotoPrevious(){_listaMunicipios.gotoPrevious();};

	/*!
	\brief inserta el municipio en lña lista
	\param municipio: municipio a insertar
	\note el elemento se insertará de forma que la lista este ordenada
	\post getCurrent()->getItem()=municipio
	\post old.nItems()+1=new.nItems()
	\note internamente llama a ListaDoblementeEnlazadaOrdenadaMunicipios::insert(Municipio municipio)
	\note function inline
	*/
	inline void insertarMunicipio(Municipio municipio){_listaMunicipios.insert(municipio);};

	/*!
	\brief borra un municipio de la lista de municipios de la provincia
	\param municipio: municipio a borrar
	\pre find(municipio)
	\post no find(municipio)
	\post old.nItems()+1=new.nItems()
	\note internamente llama a ListaDoblementeEnlazadaOrdenadaMunicipios::remove(Municipio municipio)
	\note function inline
	*/
	inline bool borrarMunicipio(std::string nombre){
		bool retval=_listaMunicipios.find(getMunicipio(nombre));
		if (retval) {
			_listaMunicipios.remove(getMunicipio(nombre));
		}
		return retval;
	}

	/*!
	\brief borra toda al lista de Municipios
	\post nItems()=0
	\note internamente llama a ListaDoblementeEnlazadaOrdenadaMunicipios::removeAll()
	\note function inline
	*/
	inline void borrarTodosLosMunicipios(){_listaMunicipios.removeAll();};

	/////////////////////////////////////////////////////////////////////

	//! \name Función de escritura de la clase Provincia
	/*!
	\brief escribe por pantalla todos los municipios de la provincia
	*/
	void escribirMunicipios(){_listaMunicipios.print();};


	/////////////////////////////////////////////////////////////////////

	//! Operaciones con ficheros
	/*!
	\brief carga los datos de un csv con municipios en el programa
	\param route: std::string ruta donde se encuantra el fichero
	*/
	bool cargarFichero(std::string route);
	//

	/*!
	\brief hace "dump" (guarda) los datos (municipios) del programa en un csv
	\param route: std::string ruta donde se desea guardar el fichero
	\note internamente se llama a ListaOrdenadaMunicipiosInterfaz::grabarFichero()
	*/
	bool grabarFichero(std::string route);


}; //Fin de la clase  Provincia


} // Fin del espacio de nombres ed

#endif // _PROVINCIA_HPP_
