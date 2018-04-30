#include "Hora.hpp"


ed::Hora::Hora(int hora, int minuto){
	setHora(hora);
	setMinuto(minuto);
}

void ed::Hora::setHora(int hora){
	_hora=hora;
}

void ed::Hora::setMinuto(int minuto){
	_minuto=minuto;
}

int ed::Hora::getHora() const {
	return _hora;
}

int ed::Hora::getMinuto() const {
	return _minuto;
}

std::string ed::Hora::getHoraString() const {
	std::ostringstream stream;
	stream<< this->getHora() << ":"
				<< this->getMinuto();
				return stream.str();
}

void ed::Hora::leerHora(){
	int hora, minuto;
	std::cout << "\n Lectura de una hora" << std::endl;
	std::cout << " Hora --> ";
	std::cin >> hora;
	std::cout << " Minuto --> ";
	std::cin >> minuto;
	this->setHora(hora);
	this->setMinuto(minuto);
}

bool ed::Hora::isValid() const {
	if (getHora()>=0 && getHora()<24 && getMinuto()>=0 && getMinuto()<=60) {
		return true;
	}else{
		return false;
	}
}
