#ifndef _MENU_SELECTOR_HPP_
#define _MENU_SELECTOR_HPP_

#include "macros.hpp"
#include "MonticuloMediciones.hpp"

void print_menu();
void menu_selector(ed::MonticuloMediciones &heap);
inline void pause(){
	std::cout <<"pulse "<<BIWHITE<<"ENTER"<<RESET<<" para continuar"<< '\n';
	std::cin.ignore();
}

#endif
