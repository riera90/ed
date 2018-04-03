/*!
	\file   ListaDoblementeEnlazadaOrdenadaMunicipios.hpp
	\brief  Clase de una lista doblemente enlazada y ordenada de Municipios
	\author
	\date
	\version 1.0

*/

#ifndef __ListaDoblementeEnlazadaOrdenadaMunicipios_HPP__
#define __ListaDoblementeEnlazadaOrdenadaMunicipios_HPP__

// Para comprobar las pre y post-condiciones
#include <cassert>

#include "ListaOrdenadaMunicipiosInterfaz.hpp"

#include "NodoDoblementeEnlazadoMunicipio.hpp"

#include "Municipio.hpp"

// DEBES ESPECIFICAR LAS FUNCIONES DE LA CLASE ListaDoblementeEnlazadaOrdenadaMunicipios


/*!
	\namespace ed
	\brief Espacio de nombres para la asignatura Estructuras de Datos

*/
namespace ed {

/*!
	\class ListaDoblementeEnlazadaOrdenadaMunicipios
	\brief Definición de la clase ListaDoblementeEnlazadaOrdenadaMunicipios
			\n Lista doblemente enlazada de nodos de municipios ordenados alfabéticamente de forma ascendente
*/
	class ListaDoblementeEnlazadaOrdenadaMunicipios: public ed::ListaOrdenadaMunicipiosInterfaz
	{
	//! \name  Atributos y métodos privados

	private:
		ed::NodoDoblementeEnlazadoMunicipio *_head;    //!< \brief puntero al primer nodo de la lista
		ed::NodoDoblementeEnlazadoMunicipio *_current; //!< \brief puntero al nodo current de la lista

		// \name Observadores privados

		inline ed::NodoDoblementeEnlazadoMunicipio * getHead() const
	{
		return this->_head;
	}

	inline ed::NodoDoblementeEnlazadoMunicipio * getCurrent() const
	{
		return this->_current;
	}

		//! \name Modificadores privados

	inline void setHead(ed::NodoDoblementeEnlazadoMunicipio *head)
	{
		this->_head = head;

		#ifndef NDEBUG
			// Se comprueba la postcondición
			assert(this->getHead() == head);
		#endif //NDEBUG
	}

		inline void setCurrent(ed::NodoDoblementeEnlazadoMunicipio *current)
	{
		this->_current = current;

		#ifndef NDEBUG
			// Se comprueba la postcondición
			assert(this->getCurrent() == current);
		#endif //NDEBUG
	}


	//! \name  Métodos públicos

	public:

	//! \name Constructores

		/*!
		\brief Construye una lista vacía
		\note  Función inline
		\post  isEmpty() == true
	*/
	inline ListaDoblementeEnlazadaOrdenadaMunicipios(){
		_head=NULL;
	}


	//! \name Destructor

		/*!
		\brief Destruye una lista liberando la memoria de sus nodos
		\note Función codificada en el fichero cpp
		\post isEmpty() == true
	*/
	~ListaDoblementeEnlazadaOrdenadaMunicipios();

	//! \name Observadores públicos

	/*!
	\brief  observador para el numero de municipios de la provincia
	\return entero: numero de municipios
	*/
	int nItems()const;

	/*!
	\brief  Comprueba si la lista está vacía
	\note   Función inline
	\note   Función de tipo "const": no puede modificar al objeto actual
	\return true, si la lista está vacía; false, en caso contrario
	*/
	inline bool isEmpty() const{return (_head==NULL ? true:false);}

	//! \name Modificadores públicos



	/*!
	\brief modifica el cursor para situarlo en primer municipio
	\pre no isEmpty()
	\post new.getCurrent()=old.getHead()
	*/
	void gotoHead();

	/*!
	\brief modifica el cursor para situarlo en el último municipio
	\pre no isEmpty()
	\post new.getCurrent()=old.getLast()
	*/
	void gotoLast();

	/*!
	\brief modifica el cursor para situarlo en el sigiente municipio
	\pre no isEmpty()
	\post new.getCurrent()=old.getNext()
	*/
	void gotoNext();

	/*!
	\brief modifica el cursor para situarlo en el anterior municipio
	\pre no isEmpty()
	\post new.getCurrent()=old.getPrevious()
	*/
	void gotoPrevious();

	/*!
	\brief inserta el municipio en lña lista
	\param municipio: municipio a insertar
	\note el elemento se insertará de forma que la lista este ordenada
	\post getCurrent()->getItem()=municipio
	\post old.nItems()+1=new.nItems()
	*/
	void insert(Municipio municipio);

	/*!
	\brief intenta localizar un municipio dentro de la Provincia
	\note si es encontrado el cursor quedara apuntando a dicho municipio
	\note si no es encontrado retorna false y el cursor quedará apuntando al final de la lista
	\param municipio: municipio a encontrar
	\return true si es encontrado, fasle si no.
	*/
	bool find(Municipio municipio);

	/*!
	\brief borra un municipio de la lista de municipios de la provincia
	\param municipio: municipio a borrar
	\pre find(municipio)
	\post no find(municipio)
	\post old.nItems()+1=new.nItems()
	*/
	void remove(Municipio municipio);

	/*!
	\brief borra toda al lista de Municipios
	\post nItems()=0
	*/
	void removeAll();


	/*!
	\brief imprime por pantalla todos los municipios de la provincia
	*/
	void print();

	inline Municipio getMunicipio() const {return (this->getCurrent()->getItem());}

}; // Fin de la clase ListaDoblementeEnlazadaOrdenadaMunicipios

} //namespace ed

#endif // __ListaDoblementeEnlazadaOrdenadaMunicipios_HPP__
