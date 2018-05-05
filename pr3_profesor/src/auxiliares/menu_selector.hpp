#ifndef _MENU_SELECTOR_HPP_
#define _MENU_SELECTOR_HPP_

#include "macros.hpp"
#include "MonticuloMediciones.hpp"
#include "funcionesAuxiliares.hpp"

/*!
	\brief		funcion escritora del menu
	\note esta funcion escribe en pantalla de forma predeterminada
*/
void print_menu();

/*!
	\brief		funcion selectora del menu
	\note 		esta funcion interactua con el montuculo, es el wraper de la interfaz de usuario con el backend
*/
void menu_selector(ed::MonticuloMediciones &heap);

/*!
	\brief		funcion de pausa interactiva del programa
	\note 		esta funcion escribe en pantalla de forma predeterminada
	\warning	funcion inline
*/
inline void pause(){
	std::cout<<RESET;
	std::cin.clear();
	// std::cin.ignore(1000,'\n');
	std::cout <<"pulse "<<BIWHITE<<"ENTER"<<RESET<<" para continuar"<< '\n';
	std::cin.ignore();
}

/*!
	\brief		funcion preparadora para la interacion por pantalla con el usuario
	\note esta funcion escribe o interactua con legal pantalla de forma predeterminada
	\warning funcion inline
*/
inline void setup(){
	std::cout <<CLEAR_SCREEN<<RESET;
}

#endif
