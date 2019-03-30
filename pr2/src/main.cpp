/*!
 \mainpage Implementación de un Polinomio
 \brief		\f$ P(X) = a_n X^n + a_{n-1} X^n-1} \cdots + a_2 X^2 + a_1 X + a_0 \f$
 \author   Diego Rodríguez Riera
 \date     30/3/19
 \version  1.0
*/

/*!

	\file principal.cpp
	\brief Programa principal de la practica 2 de ED: polinomios
*/

#include <iostream>

#include "funcionesAuxiliares.hpp"
#include "Polinomio.hpp"
#include "operadoresExternosPolinomios.hpp"

#include "macros.hpp"

/*! 
	\brief   Función principal de la práctica 2: polinomios
	\return  int
*/
int main()
{
	// // begin debug
	// 
	// 
	// ed::Polinomio p;
	// std::cin >> p;
	// 
	// return 0;
	// 
	// //end debug
	
	
	ed::Polinomio polinomio;
	int opcion;
	int min, max;

	do{

		// Se elige la opción del menún
		opcion = ed::menu();		

		std::cout << CLEAR_SCREEN;
		PLACE(3,1);

		// Se ejecuta la opción del menú elegida
		switch(opcion)
		{
			case 0: 
				PLACE(3,1);
				std::cout << BRED;
				std::cout << "[0] Fin del programa" << std::endl << std::endl;
				std::cout << RESET;
				break;

			case 1: 
			   	std::cout << BIBLUE;
				std::cout << "[1] Test de la clase Polinomio" << std::endl;
				std::cout << RESET;

				ed::testPolinomio();
				break;

			case 2: 
			   	std::cout << BIBLUE;
				std::cout << "[2] Operadores externos de la clase Polinomio " << std::endl;
				std::cout << RESET;

				ed::operadoresExternosPolinomios();
				break;
				
			case 3: 
			   	std::cout << BIBLUE;
				std::cout << "[3] introducir polinomio " << std::endl;
				std::cout << RESET;

				polinomio.leerPolinomio();
				break;
				
			case 4: 
				std::cout << BIBLUE;
				std::cout << "[4] plot polinomio " << std::endl;
				std::cout << RESET;
				std::cout << "introduce la x minima: ";
				std::cin >> min;
				std::cout << "introduce la x maxima: ";
				std::cin >> max;
				std::cout << '\n';
				
				polinomio.plot(min, max);
				
				break;
				
			case 5: 
				std::cout << BIBLUE;
				std::cout << "[5] print polinomio " << std::endl;
				std::cout << RESET;
				std::cout << '\n';
				polinomio.escribirPolinomio();
				break;

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
		std::cout << "Para mostrar el ";
		std::cout << BIGREEN ;
		std::cout << "menú, "; 
		std::cout << RESET;
		std::cout << "pulse ";
		std::cout << INVERSE ;
		std::cout << "ENTER";
		std::cout << RESET;

		// Pausa
		std::cin.ignore();

		std::cout << CLEAR_SCREEN;
    }
	  }while(opcion!=0);

	return 0;
}


