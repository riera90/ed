#ifndef _MENU_SELECTOR_HPP_
#define _MENU_SELECTOR_HPP_

#include "macros.hpp"
#include "MonticuloMediciones.hpp"
#include "funcionesAuxiliares.hpp"

void print_menu();
void menu_selector(ed::MonticuloMediciones &heap);
inline void pause(){
	std::cout<<RESET;
	std::cin.clear();
	// std::cin.ignore(1000,'\n');
	std::cout <<"pulse "<<BIWHITE<<"ENTER"<<RESET<<" para continuar"<< '\n';
	std::cin.ignore();
}
inline void setup(){
	std::cout <<CLEAR_SCREEN<<RESET;
}

#endif
