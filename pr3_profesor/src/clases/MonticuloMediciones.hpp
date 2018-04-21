/*!
	\file MonticuloMediciones.hpp
	\brief Se define el TAD MonticuloMediciones.
	\author Diego Rodriguez Riera
	\date 17.04.2018
*/

#ifndef _MONTICULO_MEDICIONES_HPP
#define _MONTICULO_MEDICIONES_HPP

#include <vector>
#include <cassert>

#include "Medicion.hpp"
#include "MonticuloMedicionesInterfaz.hpp"


namespace ed
{

class MonticuloMediciones : public MonticuloMedicionesInterfaz
{
	private:
		//! \name Atributos privados de la clase MonticuloMediciones
		std::vector<Medicion> mediciones_; //!< vector de Mediciones

		//! \name Métodos privados de la clase MonticuloMediciones

	//! \name Métodos públicos de la clase MonticuloMediciones
	public:

		//! \name Constructor
		/*!
		\brief			Constructor que crea un monticulo de mediciones
		\note				Función inline
		\post				isEmpty() == verdadero
		*/
		MonticuloMediciones(){
		}

		//! \name Observadores
		/*!
		\brief		observador logico de lista vacia
		\note			funcion inline
		\note			funcion constante
		\return		logico: verdadero si la lista está vacia, falso si existe algún elemento
		*/
		bool isEmpty() const {
			return mediciones_.size()==0 ? true:false;
		}

		//! \name Operaciones de modificación
		/*!
		\brief		modificador de insercion de la clase MonticuloMediciones
		inserta una medicion en el monticulo de mediciones, en su
		\note			funcion constante
		\pre			isEmpty() == false
		*/
		void insert(Medicion &medicion);

		/*!
		\brief		observador de elementos del vector donde se implementa el monticulo
		\post			isEmpty() == false
		*/
		Medicion getElement(int index);

		/*!
		\brief		observador de indice corespondiente de el hijo izquerdo al indice pasado
		\post			isEmpty() == false
		\return		entero: indice de el hijo izquerdo al indice pasado
		*/
		int getLeftChild(int parent_index){
			if (parent_index < 0) return -1;
			int child_index=((parent_index*2)+1);
			return (size()<=child_index) ? -1:child_index;//out of boundries:correct
		}

		/*!
		\brief		observador de indice corespondiente de el hijo de recho del indice pasado
		\post			isEmpty() == false
		\return		entero: indice de el hijo de recho del indice pasado
		*/
		int getRightChild(int parent_index){
			if (parent_index < 0) return -1;
			int child_index=((parent_index*2)+2);
			return (size()<=child_index) ? -1:child_index;//out of boundries:correct
		}

		/*!
		\brief		observador de indice corespondiente del padre del indice pasado
		\post			isEmpty() == false
		\return		entero: indice del padre del indice pasado
		*/
		int getParent(int child_index){
			if (child_index < 1) return -1;
			// std::cout << "\t\tindex returned <"<<((child_index-1)/2)<<">" << '\n';
			return ((child_index-1)/2);
		}

		/*!
		\brief		mueve hacia arriba un elemento hasta que este se encuentre en la posicion que hace el monticulo estable
		\param		entero: indice del elemento a mover (chekear)
		\post			su padre (a no ser que sea cima) es igual o mayor que el
		\post			sus hijos (todos los que tenga) son menores o iguales que el
		*/
		void shiftUp(int index); //TODO

		/*!
		\brief		mueve hacia abajo un elemento hasta que este se encuentre en la posicion que hace el monticulo estable
		\param		entero: indice del elemento a mover (chekear)
		\post			su padre (a no ser que sea cima) es igual o mayor que el
		\post			sus hijos (todos los que tenga) son menores o iguales que el
		*/
		void shiftDown(int index); //TODO

		/*!
		\brief		cambia de posicion dos elementos de el vector
		\param		index_1, index del primer elemento a intercambiar
		\param		index_2, index del segundo elemento a intercambiar
		*/
		void swap(int index_1, int index_2);

		/*!
		\brief		observador del tamaño del montuculo (en numero de mediciones)
		\return		entero: tamaño del Monticulo
		*/
		int size(){return mediciones_.size();}

		void modify(Medicion const &medicion);

		void remove();

		//! \name Operadores

		//! \name Función de escritura

	}; // Clase MonticuloMediciones

} // Espacio de nombres ed


#endif // _MONTICULO_MEDICIONES_HPP
