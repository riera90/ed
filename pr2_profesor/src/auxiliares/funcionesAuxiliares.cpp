/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares del programa principal de la provincia
  \author
  \date
*/

#include <iostream>
#include <string>

// Para usar atoi
#include <stdlib.h>

#include "Provincia.hpp"

#include "Municipio.hpp"

#include "funcionesAuxiliares.hpp"


#include "macros.hpp"

int ed::menu()
{
	int opcion;
	int posicion;

	// Se muestran las opciones del menú
	posicion=2;

	// Se borra la pantalla
	std::cout << CLEAR_SCREEN;

	PLACE(1,10);
	std::cout << BIBLUE;
	std::cout << "Programa principial | Opciones del menú";
	std::cout << RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout <<  "[1] Comprobar si la provincia tiene municipios";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[2] Cargar la provincia desde un fichero";

	PLACE(posicion++,10);
	std::cout << "[3] Grabar la provincia en un fichero";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[4] Consultar datos de la provincia";

	PLACE(posicion++,10);
	std::cout <<  "[5] Mostrar municipios de la provincia";

	PLACE(posicion++,10);
	std::cout << "[6] Modificar datos de la provincia: código o nombre";

	PLACE(posicion++,10);
	std::cout << "[7] Borrar todos los municipios de una provincia";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[8] Consultar un municipio";

	PLACE(posicion++,10);
	std::cout << "[9] Insertar un municipio";

	PLACE(posicion++,10);
	std::cout << "[10] Borrar un municipio";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << BIRED << "[0] Salir";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << BIGREEN;
	std::cout << "Opción: ";
	std::cout << RESET;

	// Se lee el número de opción
	std::cin >> opcion;

    // Se elimina el salto de línea del flujo de entrada
    std::cin.ignore();

	return opcion;
}


//////////////////////////////////////////////////////////////////////////////

void ed::comprobarProvinciaVacia(ed::Provincia &provincia)
{
	std::cout << "la provincia "<<(provincia.hayMunicipios()?"contiene elementos":"esta vacia")<< '\n';

	return;
}

//////////////////////////////////////////////////////////////////////////////

void ed::cargarProvincia(ed::Provincia &provincia)
{
	std::string route="output/Cordoba.csv";
	provincia.cargarFichero(route);

	return;
}

void ed::grabarProvincia(ed::Provincia  &provincia)
{
	std::string route="output/Cordoba2.csv";
	provincia.grabarFichero(route);

	return;
}

//////////////////////////////////////////////////////////////////////

void ed::consultarDatosDeProvincia(ed::Provincia &provincia)
{
	std::cout << "nombre provincia:" << provincia.getNombre() <<'\n';
	std::cout << "codigo provincia:" << provincia.getCodigo() <<'\n';

	return;
}


//
void ed::mostrarMunicipiosDeProvincia(ed::Provincia & provincia)
{
	provincia.escribirMunicipios();

	return;
}


////////////////////////////////////////////////////////////////////////
void ed::modificarDatosDeProvincia(ed::Provincia &provincia)
{


// QUITAR LOS COMENTARIOS CUANDO SE HAYA CODIFICADO LA CLASE Provincia


	int opcion, codigo;
	std::string nombre;

	do{
		std::cout << BIYELLOW  << "Nombre de la provincia: "  << RESET
				  << provincia.getNombre() << std::endl;
		std::cout << BIYELLOW << "Código de la provincia: " << RESET
				  << provincia.getCodigo() << std::endl  << std::endl;

		std::cout << "Indique qué dato desea modificar: " << std::endl;
		std::cout << BIBLUE << "(1) Nombre " << std::endl;
		std::cout << BIBLUE << "(2) Código" << std::endl  << std::endl;
		std::cout << BIRED << "(0) Salir" << std::endl << std::endl  << std::endl;
		std::cout << BIGREEN;
		std::cout << "Opción: ";
		std::cout << RESET;

		// Se lee el número de opción
		std::cin >> opcion;

    	// Se elimina el salto de línea del flujo de entrada
	    std::cin.ignore();

		std::cout << std::endl;

		switch(opcion)
		{
			case 0:
					// Fin de las modificaciones
					break;
			case 1:
					std::cout << BIGREEN;
					std::cout << "Nuevo nombre de la provincia: ";
					std::cout << RESET;
					std::getline(std::cin,nombre);
					provincia.setNombre(nombre);
					break;

			case 2:
					std::cout << BIGREEN;
					std::cout << "Nuevo código de la provincia: ";
					std::cout << RESET;
					std::cin >> codigo;
					provincia.setCodigo(codigo);
					break;
			default:
					std::cout << BIRED << "Opción incorrecta:" << RESET
							  << opcion << std::endl;
		}
	}while (opcion != 0);

	return;
}


void ed::borrarTodosLosMunicipiosDeProvincia(ed::Provincia &provincia)
{
	provincia.borrarTodosLosMunicipios();

	return;
}


void ed::consultarMunicipioDeProvincia(ed::Provincia &provincia)
{
	std::string name;
	std::cout << "introduzca el nombre de la provincia " << std::endl;
	std::cin >> name;
	Municipio municipio;
	municipio = provincia.getMunicipio(name);
	if (municipio.getNombre()=="") {
		std::cout << "no se ha encontrado.." << '\n';
	}else{
		std::cout << municipio << '\n';
	}
	std::cin.ignore();
	return;
}

void ed::insertarMunicipioEnProvincia(ed::Provincia &provincia)
{
	Municipio municipio;
	std::cout << "CP Nombre; hombres; mujeres;" << '\n';
	std::cin>>municipio;
	provincia.insertarMunicipio(municipio);
	std::cin.ignore();
	return;
}




void ed::borrarMunicipioDeProvincia(ed::Provincia &provincia)
{
	std::string name;
	std::cout << "introduzca el nombre de la provincia " << std::endl;
	std::cin >> name;
	Municipio municipio;
	municipio = provincia.getMunicipio(name);
	std::cout << municipio << '\n';
	if (municipio.getNombre()=="") {
		std::cout << "no se ha encontrado.." << '\n';
	}else{
		provincia.borrarMunicipio(name);
		std::cout << "borrado satisfactoriamente" << '\n';
	}
	std::cin.ignore();
	return;

	return;
}
