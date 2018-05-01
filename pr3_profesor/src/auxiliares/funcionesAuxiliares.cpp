/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares para el programa principal de la práctica 1
  \author
  \date
*/



#include "funcionesAuxiliares.hpp"



void ed::cargarMonticuloDeFichero(std::string const & nombreFichero, ed::MonticuloMediciones & monticulo){

ed::MonticuloMediciones aux_(monticulo);

	std::ifstream fichero;
	fichero.open(nombreFichero.c_str());
	if (!fichero.is_open()) {
		std::cout << "el fichero no se pudo abrir" << '\n';
		return;
	}
	Medicion aux;
	aux.cargarMedicionDeFichero(fichero);
	
			std::cout<<UWHITE;aux.escribirMedicion();std::cout<<RESET;

			aux_=monticulo;for(;!(aux_.isEmpty());aux_.remove()){
				if(aux_.size()%30==0){std::cout<<CLEAR_SCREEN;std::cout<<CYAN;}
				aux_.top().escribirMedicion();}

	while(aux.getFecha().getFechaString()!="0-0-0"){
		monticulo.insert(aux);
		aux.clear();
		aux.cargarMedicionDeFichero(fichero);

					std::cout<<UWHITE;aux.escribirMedicion();std::cout<<RESET;

					aux_=monticulo;for(;!(aux_.isEmpty());aux_.remove()){
						if(aux_.size()%30==0){std::cout<<CLEAR_SCREEN;std::cout<<CYAN;}
						aux_.top().escribirMedicion();}

	}
	fichero.close();
	return;
}


void ed::grabarMonticuloEnFichero(std::string const & nombreFichero, ed::MonticuloMediciones const & monticulo){
	std::ofstream file;
  file.open(nombreFichero.c_str());
  if( (file.rdstate() & std::ofstream::failbit ) != 0 ){
		std::cout << "ERROR el fichero no se pudo abrir" << '\n';
		return;
	}
  ed::MonticuloMediciones aux(monticulo);
	for (; !(aux.isEmpty()); aux.remove()) {
		file<<aux.top().getMedicionString()<<"\n";
	}
	file<<aux.top().getMedicionString()<<"\n";
  file.close();
	return;
}
