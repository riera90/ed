/*!
   \file  Medicion.cpp
   \brief Fichero que contiene el código de las funciones de la clase Medicion
*/

#include "Medicion.hpp"

namespace ed{

Medicion::Medicion(Fecha fecha, float precipitacion){
	setFecha(fecha);
	setPrecipitacion(precipitacion);
	setTemperaturaMaxima(0);
	setHoraTemperaturaMaxima(Hora(0,0));
	setTemperaturaMinima(0);
	setHoraTemperaturaMinima(Hora(0,0));
	setTemperaturaMedia(0);
	setHumedadRelativaMaxima(0);
	setHumedadRelativaMinima(0);
	setHumedadRelativaMedia(0);
	setVelocidadVientoMedia(0);
	setDireccionVientoMedia(0);
	setRadiacionSolar(0);
	setEto(0);
	setValid(false);
}

void Medicion::leerMedicion(){
	int h,m,dp;
	float val;
	std::string cache;
	char s=' ';
	std::cout <<"Introduzca la fecha:\n\tdia-mes-año\n\t->";
	int dia, mes, ano;
	std::getline(std::cin, cache, '-');
	dia=atoi(cache.c_str());
	std::getline(std::cin, cache, '-');
	mes=atoi(cache.c_str());
	std::getline(std::cin, cache, '\n');
	ano=atoi(cache.c_str());
	Fecha fecha(dia,mes,ano);
	if (!fecha.esCorrecta()) {
		std::cout<<"Introduzca una fecha válida.\n";
	}else{
		if (0) {//exists TODO
			std::cout <<"medicion ya registrada\n";
		}else{
			this->setFecha(ed::Fecha(dia,mes,ano));
		}
	}


	//precipitacion
	for(cache="";cache=="";){
		std::cout<<"Precipitacion "<<CYAN<<"[0]"<<RESET<<":\n\t->";
		std::getline(std::cin,cache,'\n');
		if(cache==""){cache="ok";val=0;
		}else{
			val=atof(cache.c_str());
		}if(val<=-0.000001){
			cache="";std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';
		}
}
	this->setPrecipitacion(val);



	//hora temperaturaMaxima
	for(h=m=-1;!Hora(h,m).isValid();){
	std::cout<<"Hora temperatura maxima "<<CYAN<<"[00:00]"<<RESET<<":\n\t->";
	std::getline(std::cin,cache,'\n');if(cache==""){h=m=0;}else{dp=cache.find(':');h=atoi(cache.substr(0,dp).c_str());m=atoi(cache.substr(dp+1,cache.size()).c_str());}if(!Hora(h,m).isValid()){cache="";
	std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';}}
	this->setHoraTemperaturaMaxima(Hora(h,m));

}

void Medicion::escribirMedicion() {
	std::cout<<"\t ";
	std::cout<<getFecha()<<",";
	std::cout<<getTemperaturaMaxima()<<",";
	std::cout<<getHoraTemperaturaMaxima().getHoraString()<<",";
	std::cout<<getTemperaturaMinima()<<",";
	std::cout<<getHoraTemperaturaMinima().getHoraString()<<",";
	std::cout<<getTemperaturaMedia()<<",";
	std::cout<<getHumedadRelativaMaxima()<<",";
	std::cout<<getHumedadRelativaMinima()<<",";
	std::cout<<getHumedadRelativaMedia()<<",";
	std::cout<<getVelocidadVientoMedia()<<",";
	std::cout<<getDireccionVientoMedia()<<",";
	std::cout<<getRadiacionSolar()<<",";
	std::cout<<getPrecipitacion()<<",";
	std::cout<<getEto()<<"\n";
}

void Medicion::cargarMedicionDeFichero(std::istream &stream){
	Medicion medicion;
	int h,m,dp;
	char cache_char[1000];
	stream.getline(cache_char, 10000, '\n');
	std::string all_cache=cache_char;
	// std::cout << "cache:" <<all_cache<< '\n';
	size_t position;
	std::string cache;

	position=all_cache.find("-",0);
	cache=all_cache.substr(0,position);
	all_cache=all_cache.substr(position+1,all_cache.size());
	int dia=atoi(cache.c_str());

	position=all_cache.find("-",0);
	cache=all_cache.substr(0,position);
	all_cache=all_cache.substr(position+1,all_cache.size());
	int mes=atoi(cache.c_str());

	position=all_cache.find("-",0);
	cache=all_cache.substr(0,position);
	all_cache=all_cache.substr(position+1,all_cache.size());
	int ano=atoi(cache.c_str());

	Fecha fecha(dia,mes,ano);
	this->setFecha(fecha);

	//ignores the element of the day
	position=all_cache.find(";",0);
	cache=all_cache.substr(0,position);
	all_cache=all_cache.substr(position+1,all_cache.size());
	position=all_cache.find(";",0);
	cache=all_cache.substr(0,position);
	all_cache=all_cache.substr(position+1,all_cache.size());

	position=all_cache.find(";",0);
	cache=all_cache.substr(0,position);
	all_cache=all_cache.substr(position+1,all_cache.size());
	this->setTemperaturaMaxima(atof(cache.c_str()));

	position=all_cache.find(";",0);
	cache=all_cache.substr(0,position);
	all_cache=all_cache.substr(position+1,all_cache.size());
	dp=cache.find(':');
	h=atoi(cache.substr(0,dp).c_str());
	m=atoi(cache.substr(dp+1,cache.size()).c_str());
	this->setHoraTemperaturaMaxima(Hora(h,m));

	position=all_cache.find(";",0);
	cache=all_cache.substr(0,position);
	all_cache=all_cache.substr(position+1,all_cache.size());
	this->setTemperaturaMinima(atof(cache.c_str()));

	position=all_cache.find(";",0);
	cache=all_cache.substr(0,position);
	all_cache=all_cache.substr(position+1,all_cache.size());
	dp=cache.find(':');
	h=atoi(cache.substr(0,dp).c_str());
	m=atoi(cache.substr(dp+1,cache.size()).c_str());
	this->setHoraTemperaturaMinima(Hora(h,m));

	position=all_cache.find(";",0);
	cache=all_cache.substr(0,position);
	all_cache=all_cache.substr(position+1,all_cache.size());
	this->setTemperaturaMedia(atof(cache.c_str()));

	position=all_cache.find(";",0);
	cache=all_cache.substr(0,position);
	all_cache=all_cache.substr(position+1,all_cache.size());
	this->setHumedadRelativaMaxima(atof(cache.c_str()));

	position=all_cache.find(";",0);
	cache=all_cache.substr(0,position);
	all_cache=all_cache.substr(position+1,all_cache.size());
	this->setHumedadRelativaMinima(atof(cache.c_str()));

	position=all_cache.find(";",0);
	cache=all_cache.substr(0,position);
	all_cache=all_cache.substr(position+1,all_cache.size());
	this->setHumedadRelativaMedia(atof(cache.c_str()));

	position=all_cache.find(";",0);
	cache=all_cache.substr(0,position);
	all_cache=all_cache.substr(position+1,all_cache.size());
	this->setVelocidadVientoMedia(atof(cache.c_str()));

	position=all_cache.find(";",0);
	cache=all_cache.substr(0,position);
	all_cache=all_cache.substr(position+1,all_cache.size());
	this->setDireccionVientoMedia(atof(cache.c_str()));

	position=all_cache.find(";",0);
	cache=all_cache.substr(0,position);
	all_cache=all_cache.substr(position+1,all_cache.size());
	this->setRadiacionSolar(atof(cache.c_str()));

	position=all_cache.find(";",0);
	cache=all_cache.substr(0,position);
	all_cache=all_cache.substr(position+1,all_cache.size());
	this->setPrecipitacion(atof(cache.c_str()));

	position=all_cache.find(";",0);
	cache=all_cache.substr(0,position);
	all_cache=all_cache.substr(position+1,all_cache.size());
	this->setEto(atof(cache.c_str()));

	this->setValid(true);
}


// Sobrecarga del operador de salida
std::ostream &operator<<(std::ostream &stream, Medicion const &medicion)
{
	stream << medicion.getFecha().getFechaString();
	stream << " ";
	stream << medicion.getPrecipitacion();
	stream << "\n";

  return stream;
}

// Sobrecarga del operador de entrada
std::istream &operator>>(std::istream &stream, Medicion &medicion)
{
	std::string cache;
	std::getline(stream, cache, '-');
	int dia=atoi(cache.c_str());
	std::getline(stream, cache, '-');
	int mes=atoi(cache.c_str());
	std::getline(stream, cache, '-');
	int ano=atoi(cache.c_str());
	Fecha fecha(dia,mes,ano);
	std::cout <<fecha.getFechaString()<< '\n';
	medicion.setFecha(fecha);
	std::getline(stream, cache, ';');
	std::getline(stream, cache, ';');
	medicion.setTemperaturaMaxima(atof(cache.c_str()));

	std::getline(stream, cache, ';');
	int dp=cache.find(':');
	int h=atoi(cache.substr(0,dp).c_str());
	int m=atoi(cache.substr(dp+1,cache.size()).c_str());
	medicion.setHoraTemperaturaMaxima(Hora (h,m));

	std::getline(stream, cache, ';');
	medicion.setTemperaturaMinima(atof(cache.c_str()));

	std::getline(stream, cache, ';');
	dp=cache.find(':');
	h=atoi(cache.substr(0,dp).c_str());
	m=atoi(cache.substr(dp+1,cache.size()).c_str());
	medicion.setHoraTemperaturaMinima(Hora (h,m));

	std::getline(stream, cache, ';');
	medicion.setTemperaturaMedia(atof(cache.c_str()));
	std::getline(stream, cache, ';');
	medicion.setHumedadRelativaMaxima(atof(cache.c_str()));
	std::getline(stream, cache, ';');
	medicion.setHumedadRelativaMinima(atof(cache.c_str()));
	std::getline(stream, cache, ';');
	medicion.setHumedadRelativaMedia(atof(cache.c_str()));
	std::getline(stream, cache, ';');
	medicion.setVelocidadVientoMedia(atof(cache.c_str()));
	std::getline(stream, cache, ';');
	medicion.setDireccionVientoMedia(atof(cache.c_str()));
	std::getline(stream, cache, ';');
	medicion.setRadiacionSolar(atof(cache.c_str()));
	std::getline(stream, cache, ';');
	medicion.setPrecipitacion(atof(cache.c_str()));
	std::getline(stream, cache, '\n');
	medicion.setEto(atof(cache.c_str()));
	medicion.setValid(true);

  return stream;
}

} // Fin del espacio de nombres ed
