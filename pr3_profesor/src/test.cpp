#include <iostream>
#include <string>
#include "Hora.hpp"


int main(int argc, char *argv[])
{
	ed::Hora hora(1,2);
	std::cout << hora.getHoraString() << '\n';
	return 0;
}
