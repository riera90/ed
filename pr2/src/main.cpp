/*!

	\file main.cpp
	\brief Menu of the program
	\author Nicolas Luis Fernandez Garcia
	\version 1.0
*/

/*!
 \mainpage Double linked list implementation of Municipios
 \author Diego Rodríguez Riera
 \date 29/March/2018
 \version  1.0
*/

/*!
\brief Menu of the program
\return  int
*/

#include "menu_wraper.hpp"
#include "funciones_auxiliares.hpp"


int main(){
	std::cout << "test!!!" << '\n';

	Provincia provincia;

	int opcion;

	do{
		// Se elige la opción del menún
		opcion = menu();

		std::cout << CLEAR_SCREEN;
		PLACE(3,1);

		// Se ejecuta la opción del menú elegida
		switch(opcion)
		{
			case 0:
					std::cout << INVERSE;
					std::cout << "Fin del programa" << std::endl;
					std::cout << RESET;
			break;

		   ///////////////////////////////////////////////////////////////////

			case 1:
					std::cout << "[1] Comprobar si la provincia tiene municipios" << std::endl;
					comprobarProvinciaVacia(provincia);
					break;

			//////////////////////////////////////////////////////////////////////////////
			case 2:
					std::cout << "[2] Cargar la provincia desde un fichero" << std::endl;
					cargarProvincia(provincia);
				break;

			case 3:
					std::cout << "[3] Grabar la provincia en un fichero" << std::endl;
					grabarProvincia(provincia);
					break;

			//////////////////////////////////////////////////////////////////////////////
			case 4:
				  std::cout << "[4] Consultar datos de la provincia: " << std::endl;
					consultarDatosDeProvincia(provincia);
					break;

			case 5:
				  std::cout << "[5] Mostrar municipios de la provincia: " << std::endl;
					mostrarMunicipiosDeProvincia(provincia);
					break;


			//////////////////////////////////////////////////////////////////////////////
			case 6:
					std::cout << "[6] Modificar datos de la provincia: código o nombre"<< std::endl;
				  modificarDatosDeProvincia(provincia);
					break;


			case 7:
					std::cout << "[7] Borrar todos los municipios de una provincia" << std::endl;
				 	borrarTodosLosMunicipiosDeProvincia(provincia);
					break;

			//////////////////////////////////////////////////////////////////////////////
			case 8:
					std::cout << "[8] Consultar el municipio" << std::endl;
			    consultarMunicipioDeProvincia(provincia);
					break;

			case 9:
					std::cout << "[9] Insertar un municipio" << std::endl;
				  insertarMunicipioEnProvincia(provincia);
					break;

			case 10:
					std::cout << "[10] Borrar el municipio" << std::endl;
					borrarMunicipioDeProvincia(provincia);
					break;

			case 11:
					std::cout << "[11] goto_next" << std::endl;
					if (provincia.n_municipios()==0) {
						std::cout << "nothing to do, please load at least 1 element" << '\n';
					}else{
						provincia.goto_next();
					}
					break;

			case 12:
					std::cout << "[12] goto_previous" << std::endl;
					if (provincia.n_municipios()==0) {
						std::cout << "nothing to do, please load at least 1 element" << '\n';
					}else{
						provincia.goto_previous();
					}
					break;

			case 13:
					std::cout << "[13] modify Municipio" << std::endl;
					if (provincia.n_municipios()==0) {
						std::cout << "nothing to do, please load at least 1 element" << '\n';
					}else{
						Municipio municipio;
						municipio.read_Municipio();
						provincia.modify(municipio);
						provincia.list_actialization();
					}
					break;

			case 14:{
					std::cout << "[14] buscar un Municipio" << std::endl;
					if (provincia.n_municipios()==0) {
						std::cout << "nothing to do, please load at least 1 element" << '\n';
					}else{
						std::string name;
						std::cout << "introduzca el nombre a buscar" << '\n';
						getline(std::cin,name);
						if (provincia.find(name)) {
							std::cout << "encontrado!!\nAhora el puntero apunta a el." << '\n';
						}else std::cout << "no encontrado..." << '\n';
					}
					std::cin.ignore();
					break;
				}

			//////////////////////////////////////////////////////////////////////////////
			default:
				std::cout << BIRED;
				std::cout << "Opción incorrecta ";
				std::cout << RESET;
				std::cout << "--> ";
			  	std::cout << ONIRED;
				std::cout << opcion << std::endl;
				std::cout << RESET;
     }

    if (opcion !=0)
    {
		PLACE(25,1);
		std::cout << "Pulse ";
		std::cout << BIGREEN;
		std::cout << "ENTER";
		std::cout << RESET;
		std::cout << " para mostrar el ";
		std::cout << INVERSE;
		std::cout << "menú";
		std::cout << RESET;

		// Pausa
		std::cin.ignore();

		std::cout << CLEAR_SCREEN;
    }
	  }while(opcion!=0);

	return 0;
}
