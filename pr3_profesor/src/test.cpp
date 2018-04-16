/*!
 \mainpage Implementación de un montículo de mediciones
 \author   Nicolás Luis Fernández García
 \date     2018-3-7
 \version  1.0
*/


/*!

	\file principalMediciones.cpp
	\brief Programa principal de la practica 3 de Estructuras de Datos
*/

#include <iostream>

#include <string>


#include "Medicion.hpp"


/*!
		\brief   Programa principal de la práctica 2: montículo de mediciones
		\return  int
*/
int main(int argc, char *argv[])
{
	ed::Medicion a;
	a.leerMedicion();
	a.escribirMedicion();
	return 0;
}
