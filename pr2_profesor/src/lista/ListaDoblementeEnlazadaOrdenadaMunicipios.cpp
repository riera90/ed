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
		// while(_head->getNext()!=NULL){
			// next=_head->getNext();
		// }
	}

	// int ListaDoblementeEnlazadaOrdenadaMunicipios::nItems(){
	// 	if(this->isEmpty())return 0;
	// 	ListaDoblementeEnlazadaOrdenadaMunicipios iterator(*this);
	// 	it.gotoNext()
	// 	while()
	// }

	void ListaDoblementeEnlazadaOrdenadaMunicipios::gotoHead(){
		this->setCurrent(this->getHead());
	}

	void ListaDoblementeEnlazadaOrdenadaMunicipios::gotoLast(){
		this->setCurrent(this->getHead()->getPrevious());
	}

	void ListaDoblementeEnlazadaOrdenadaMunicipios::gotoNext(){
		this->setCurrent(this->getCurrent()->getNext());
	}

	void ListaDoblementeEnlazadaOrdenadaMunicipios::gotoPrevious(){
		this->setCurrent(this->getCurrent()->getPrevious());
	}

	void ListaDoblementeEnlazadaOrdenadaMunicipios::insert(Municipio municipio){
		NodoDoblementeEnlazadoMunicipio* nodo=new NodoDoblementeEnlazadoMunicipio(municipio,NULL,NULL);
		if (this->isEmpty()){
			// std::cout << "nohead" << '\n';
			this->setHead(nodo);
			this->gotoHead();
		}else{
			// std::cout << "head" << '\n';
			this->gotoHead();
			if (this->getCurrent()->getNext()==NULL) {
				if (this->getCurrent()->getItem().getNombre() < municipio.getNombre()) {
					//back insert
					// std::cout << "back insert" << '\n';
					NodoDoblementeEnlazadoMunicipio* previous = this->getCurrent();
					this->getCurrent()->setNext(nodo);
					this->getCurrent()->setPrevious(nodo);
					nodo->setPrevious(previous);
				}else{
					//front insert
					// std::cout << "front insert" << '\n';
					NodoDoblementeEnlazadoMunicipio* next = this->getCurrent();
					nodo->setNext(next);
					nodo->setPrevious(next);
					this->getCurrent()->setPrevious(nodo);
					this->setHead(nodo);
				}
			}else{
				// std::cout << "testing" << '\n';
				while(this->getCurrent()!=NULL){
					// std::cout << "searching" << '\n';
					if (this->getCurrent()->getItem().getNombre() > municipio.getNombre()) {
						// std::cout << "found!!" << '\n';
						break;
					}
					this->gotoNext();
				}
				if (this->getCurrent()==NULL) {
					// std::cout << "last" << '\n';
					// std::cout <<"es el mas grande: "<< municipio.getNombre()<< '\n';
					this->gotoLast();
					NodoDoblementeEnlazadoMunicipio* previous = this->getCurrent();
					this->getCurrent()->setNext(nodo);
					nodo->setPrevious(previous);
					this->getHead()->setPrevious(nodo);
				}else{
					// std::cout << this->getCurrent()->getItem().getNombre() <<" > "<< municipio.getNombre()<< '\n';
					NodoDoblementeEnlazadoMunicipio* next     = this->getCurrent();
					NodoDoblementeEnlazadoMunicipio* previous = this->getCurrent()->getPrevious();
					nodo->setNext(next);
					nodo->setPrevious(previous);
					next->setPrevious(nodo);
					previous->setNext(nodo);
				}
			}
			// this->print();
		}
	}

	void ListaDoblementeEnlazadaOrdenadaMunicipios::print(){
		ListaDoblementeEnlazadaOrdenadaMunicipios* it=new ListaDoblementeEnlazadaOrdenadaMunicipios(*this);
		it->gotoHead();
		if ( it->isEmpty() ) std::cout << "la lista esta vacia" << '\n';
		else{
			while(it->getCurrent()!=NULL){
				std::cout << "name: <" << it->getCurrent()->getItem().getNombre()<< ">\n";
				it->gotoNext();
			}
		}
		std::cout << "----------------------" << '\n';
	}

	bool ListaDoblementeEnlazadaOrdenadaMunicipios::find(Municipio municipio){
		this->gotoHead();
		while(this->getCurrent()!=NULL){
			if (this->getCurrent()->getItem().getNombre() < municipio.getNombre()){

			}else{
				return this->getCurrent()->getItem().getNombre()==municipio.getNombre() ? true:false;
			}
			this->gotoNext();
		}
	}

	void ListaDoblementeEnlazadaOrdenadaMunicipios::remove(Municipio municipio){
		if(!this->find(municipio)){//checks if it's empty
			std::cout << "el municipio no esta en la lista" << '\n';
		}else{//checks for the last element
			if (this->getHead()==this->getCurrent()) {
				this->setHead(this->getCurrent()->getNext());
				this->getHead()->setPrevious(this->getCurrent()->getPrevious());
			}else{//checks for the first element
				NodoDoblementeEnlazadoMunicipio* next     = this->getCurrent()->getNext();
				NodoDoblementeEnlazadoMunicipio* previous = this->getCurrent()->getPrevious();
				if (this->getCurrent()->getNext()==NULL) {
					this->getHead()->setPrevious(previous);
					previous->setNext(NULL);
				}else{
					next->setPrevious(previous);
					previous->setNext(next);
				}
			}
			delete(this->getCurrent());
		}
	}

	void ListaDoblementeEnlazadaOrdenadaMunicipios::removeAll(){
		if(this->getHead()==NULL){//checks if it's empty
			std::cout << "el municipio no esta en la lista" << '\n';
		}else{//checks for the last element
			if (this->getHead()->getPrevious()==NULL) {
				delete(this->getHead());
				this->setHead(NULL);
			}else{
				this->gotoLast();
				while(this->getCurrent()!=this->getHead()){
					this->gotoPrevious();
					delete(this->getCurrent()->getNext());
				}
				delete(this->getHead());
			}
		}
	}

}
