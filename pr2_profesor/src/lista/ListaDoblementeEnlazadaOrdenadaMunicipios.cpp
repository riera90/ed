/*!
	\file   ListaDoblementeEnlazadaOrdenadaMunicipios.cpp
	\brief  Clase de una lista doblemente enlazada y ordenada de Municipios
	\author
	\date
	\version 1.0
*/

// Para comprobar las pre y post-condiciones
#include <cassert>

#include "ListaDoblementeEnlazadaOrdenadaMunicipios.hpp"
#include "NodoMunicipioInterfaz.hpp"
#include "Municipio.hpp"

namespace ed{

ListaDoblementeEnlazadaOrdenadaMunicipios::~ListaDoblementeEnlazadaOrdenadaMunicipios(){
	while(_head->getNext()!=NULL){
		 // next=_head->getNext();

	}
}

}
