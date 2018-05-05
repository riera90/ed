/*!
	\file MonticuloMediciones.cpp
	\brief Fichero que contiene el código de las funciones de la clase MonticuloMediciones.
	\author
	\date
*/


#include "MonticuloMediciones.hpp"


void ed::MonticuloMediciones::insert(Medicion &medicion){
	if (this->has(medicion)){
		std::cout << "la medicion es duplicada!!" << '\n';
		std::cout << "\t->"; medicion.escribirMedicion();
		return;
	}
	mediciones_.push_back(medicion);
	shiftUp(size()-1);
}

ed::Medicion ed::MonticuloMediciones::getElement(int index){
	if (index >= mediciones_.size()) return ed::Medicion(ed::Fecha(0,0,0),0.0);
	return mediciones_[index];
}

void ed::MonticuloMediciones::shiftUp(int index){
	int index_parent;
	bool exit_loop=false;
	while (!exit_loop){
		index_parent=getParent(index);
		// std::cout << "parent index: ["<<index_parent<<"] index["<<index<<"]" << '\n';
		if(index_parent==-1){//the parent does not exist
			exit_loop=true;
		}else{//parent exists
			if(compareMedicion(index_parent,index)<0){//paretn is greater than the children
				swap(index,index_parent);
				// std::cout << "\tswaping["<<index<<"]["<<index_parent<<"]" << '\n';
				index=index_parent;
			}else{//the parent is equal or lower than the children
				// std::cout << "exiting " << '\n';
				exit_loop=true;
			}
		}
	}
}




void ed::MonticuloMediciones::shiftDown(int index){
	int index_right_child;
	int index_left_child;
	bool exit_loop=false;
	while(!exit_loop){
		index_right_child=getRightChild(index);
		index_left_child =getLeftChild (index);
		#ifdef DEBUG
		std::cout << "\niteration!!" << '\n';
		#endif
		if (index_right_child==-1) {//there is not right child
			if (index_left_child==-1) {//there is none childrens, exit
				#ifdef DEBUG
				std::cout << "exiting_1" << '\n';
				#endif
				exit_loop=true;
			}else{//there is only one left child
				if(compareMedicion(index,index_left_child)<0){//parent is greater than child
					#ifdef DEBUG
					std::cout << "swaping ["<<index<<"] ["<<index_left_child<<"]" << '\n';
					#endif
					swap(index,index_left_child);
				}else{//child is equal or greater than parent
					#ifdef DEBUG
					std::cout << "exiting_2" << '\n';
					#endif
					exit_loop=true;//all is done
				}
			}
		}else{//there are two childrens
			if(compareMedicion(index_right_child, index_left_child)<0){//right children is greater than left children
				swap(index,index_left_child);
				#ifdef DEBUG
				std::cout << "swaping ["<<index<<"] ["<<index_left_child<<"]" << '\n';
				#endif
				index=index_left_child;
			}else{//left children is equal or greater than right children
				swap(index,index_right_child);
				#ifdef DEBUG
				std::cout << "swaping ["<<index<<"] ["<<index_right_child<<"]" << '\n';
				#endif
				index=index_right_child;
			}
		}
	}
}

void ed::MonticuloMediciones::swap(int index_1, int index_2){
	Medicion aux(mediciones_[index_1]);
	mediciones_[index_1]=mediciones_[index_2];
	mediciones_[index_2]=aux;
}

void ed::MonticuloMediciones::modify(Medicion const &medicion){
	mediciones_[0]=medicion;
}

void ed::MonticuloMediciones::remove(){
	this->swap(0,size()-1);
	mediciones_.erase(mediciones_.end());
	this->shiftDown(0);
}

int ed::MonticuloMediciones::compareMedicion(int index_1, int index_2){
	return \
	getElement(index_1).getFecha().fechaCompare(\
	getElement(index_2).getFecha());
}

bool ed::MonticuloMediciones::has(Medicion medicion){
	for (size_t i = 0; i < mediciones_.size(); i++) {
		if (mediciones_[i].equal(medicion)) return true;
	}
	return false;
}

ed::MonticuloMediciones& ed::MonticuloMediciones::operator=(MonticuloMediciones const &heap){
	this->mediciones_=heap.getHeap();
	return *this;
}
