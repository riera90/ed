/*!
	\file MonticuloMediciones.cpp
	\brief Fichero que contiene el código de las funciones de la clase MonticuloMediciones.
	\author
	\date
*/

#include <vector>

#include <cassert>

#include "Medicion.hpp"

#include "MonticuloMediciones.hpp"


void ed::MonticuloMediciones::insert(Medicion &medicion){
	std::vector<Medicion>::iterator it;
	it=mediciones_.end();
	mediciones_.insert(it,medicion);
	shiftUp(size()-1);
}

ed::Medicion ed::MonticuloMediciones::getElement(int index){
	if (index >= mediciones_.size()) return ed::Medicion(ed::Fecha(0,0,0),0.0);
	return mediciones_[index];
}

void ed::MonticuloMediciones::shiftUp(int index){
	for(;\
		getElement(index).getFecha().fechaCompare(getElement(getParent(index)).getFecha()) < 0;\
		index=getParent(index)){
				//std::cout<<"swaping\n\t["<<index<<"]";getElement(index).escribirMedicion();std::cout<<"\t["<<getParent(index)<<"]";getElement(getParent(index)).escribirMedicion();std::cout<<"\n";
			Medicion parent(getElement(getParent(index)));
			swap(index,getParent(index));
		}
}

void ed::MonticuloMediciones::shiftDown(int index){

}

void ed::MonticuloMediciones::swap(int index_1, int index_2){
	Medicion aux(mediciones_[index_1]);
	mediciones_[index_1]=mediciones_[index_2];
	mediciones_[index_2]=aux;

}
