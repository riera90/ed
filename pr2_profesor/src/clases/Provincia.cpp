/*!

	\file  Provincia.cpp
	\brief Definición de la clase Provincia
	\author
	\date
	\version 1.0

*/
//Para los flujos de entrada/salida en ficheros.
#include <fstream>
#include <iostream>

// Para comprobar las pre y post condiciones
#include <cassert>

#include "Provincia.hpp"
namespace ed{
	///////////////////////////////////////////////////////////////////////////////

	// OSBSERVADORES



	/////////////////////////////////////////////////////////////////////////////////////////

	// MODIFICADORES




	///////////////////////////////////////////////////////////////////////////////////

	// FUNCIÓN DE ESCRITURA



	/////////////////////////////////////////////////////////////////////////////////////////

	// OPERACIONES CON FICHEROS

	// bool Provincia::cargarFichero(std::string route){
	// 	CSV_reader csv(route);
	// 	CSV_line line;
	// 	CSV_data data=csv.load_csv();
	// 	Municipio municipio;
	// 	std::string postal_and_name, name;
	// 	int separator, postal_code;
	// 	//dumps the data into the class
	// 	line=data.get_line(0);
	// 	std::string provincia_data=line.get_field(0);
	// 	separator=provincia_data.find(' ');
	// 	setCodigo(atoi(provincia_data.substr(0,separator).c_str()));
	// 	setNombre(provincia_data.substr(separator+1));
	// 	for (size_t i = 1; i < data.lines(); i++) {
	//
	// 		line=data.get_line(i);
	//
	// 		postal_and_name = line.get_field(0);
	// 		separator=postal_and_name.find(' ');
	//
	// 		postal_code=atoi(postal_and_name.substr(0,separator).c_str());
	// 		municipio.setCodigoPostal(postal_code);
	//
	// 		municipio.setNombre(postal_and_name.substr(separator+1));
	//
	// 		municipio.setHombres(atoi(line.get_field(1).c_str()));
	// 		municipio.setMujeres(atoi(line.get_field(2).c_str()));
	// 		if (municipio.getNombre()!="") {
	// 			insertarMunicipio(municipio);
	// 		}
	// 	}
	// }

	bool ed::Provincia::cargarFichero(std::string nombre){
    std::ifstream fichero;
    fichero.open(nombre.c_str());
      std::string cadena;
      std::getline(fichero,cadena,' ');
      setCodigo(atoi(cadena.c_str()));
      std::getline(fichero,cadena,'\n');
      setNombre(cadena);
    if( (fichero.rdstate() & std::ifstream::failbit ) != 0 )return false;
    ed::Municipio aux;
   while(fichero>>aux){
        _listaMunicipios.insert(aux);
     }
     return true;
}

	// bool Provincia::grabarFichero(std::string route){
	// 	CSV_data data;
	// 	CSV_line line;
	// 	CSV_writer csv(route);
	// 	line.push_field(std::to_string(getCodigo())+" "+getNombre());
	// 	data.push_line(line);
	// 	// csv.dump_csv(data);
	// 	_listaMunicipios.grabarFichero(data,line,csv);
	// };
	bool ed::Provincia::grabarFichero(std::string route){
    std::ofstream fichero;
    fichero.open(route.c_str());

	  if( (fichero.rdstate() & std::ofstream::failbit ) != 0 )return false;

		fichero<<_codigo<<" "<<_nombre<<"\n";
    _listaMunicipios.gotoHead();
   	while(!_listaMunicipios.isLastItem()){
    	fichero<<_listaMunicipios.getCurrentItem()<<"\n";
    	_listaMunicipios.gotoNext();
	 	}
    fichero<<_listaMunicipios.getCurrentItem()<<"\n";
    fichero.close();
		return true;

	}

	int Provincia::getTotalHombres(){
		int count=0;
		ListaDoblementeEnlazadaOrdenadaMunicipios* it= new ListaDoblementeEnlazadaOrdenadaMunicipios(_listaMunicipios);
		for(it->gotoHead();it->existeSiguiente();it->gotoNext()){
			count+=it->getMunicipio().getHombres();
		}
		return count;
	}

	int Provincia::getTotalMujeres(){
		int count=0;
		ListaDoblementeEnlazadaOrdenadaMunicipios* it= new ListaDoblementeEnlazadaOrdenadaMunicipios(_listaMunicipios);
		for(it->gotoHead();it->existeSiguiente();it->gotoNext()){
			count+=it->getMunicipio().getMujeres();
		}
		return count;
	}

}