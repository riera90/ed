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
	float val, val2, val3;
	std::string cache;
	bool ok;
	char s=' ';
	std::cout <<"Los valores predeterminados serán indicados por '[]'\n\nIntroduzca los valores requeridos:\n\n";

	for(ok=false;!ok;){
		std::cout<<"Fecha : dia"<<CYAN<<"[0]"<<RESET<<":\n\t->";
		std::getline(std::cin, cache);
		if(cache==""){
			ok=true;val=0;
		}else{
			try{ok=true;val=std::stof(cache.c_str());}
			catch(...){std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
		}
	}val3=val;
	for(ok=false;!ok;){
		std::cout<<"Fecha : mes"<<CYAN<<"[0]"<<RESET<<":\n\t->";
		std::getline(std::cin, cache);
		if(cache==""){
			ok=true;val=0;
		}else{
			try{ok=true;val=std::stof(cache.c_str());}
			catch(...){std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
		}
	}val2=val;
	for(ok=false;!ok;){
		std::cout<<"Fecha : año"<<CYAN<<"[0]"<<RESET<<":\n\t->";
		std::getline(std::cin, cache);
		if(cache==""){
			ok=true;val=0;
		}else{
			try{ok=true;val=std::stof(cache.c_str());}
			catch(...){std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
		}
	}this->setFecha(Fecha(val3,val2,val));


	//precipitacion
	for(ok=false;!ok;){
		std::cout<<"Precipitacion "<<CYAN<<"[0]"<<RESET<<":\n\t->";
		std::getline(std::cin, cache);
		if(cache==""){
			ok=true;val=0;
		}else{
			try{ok=true;val=std::stof(cache.c_str());}
			catch(...){std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
		}
	}this->setPrecipitacion(val);


	//temperaturaMaxima
	for(ok=false;!ok;){
		std::cout<<"Temperatura maxima "<<CYAN<<"[0]"<<RESET<<":\n\t->";
		std::getline(std::cin, cache);
		if(cache==""){
			ok=true;val=0;
		}else{
			try{ok=true;val=std::stof(cache.c_str());}
			catch(...){std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
		}
	}this->setTemperaturaMaxima(val);

	//hora temperaturaMaxima
	for(ok=false;!ok;){
		std::cout<<"Hora temperatura maxima: hora "<<CYAN<<"[0]"<<RESET<<":\n\t->";
		std::getline(std::cin, cache);
		if(cache==""){
			ok=true;val=0;
		}else{
			try{ok=true;val=std::stof(cache.c_str());}
			catch(...){std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
		}
	}val2=val;
	for(ok=false;!ok;){
		std::cout<<"Hora temperatura maxima: minuto "<<CYAN<<"[0]"<<RESET<<":\n\t->";
		std::getline(std::cin, cache);
		if(cache==""){
			ok=true;val=0;
		}else{
			try{ok=true;val=std::stof(cache.c_str());}
			catch(...){std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
		}
	}this->setHoraTemperaturaMaxima(Hora(val2,val));

	//temperaturaMinima
	for(ok=false;!ok;){
		std::cout<<"Temperatura minima "<<CYAN<<"[0]"<<RESET<<":\n\t->";
		std::getline(std::cin, cache);
		if(cache==""){
			ok=true;val=0;
		}else{
			try{ok=true;val=std::stof(cache.c_str());}
			catch(...){std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
		}
	}this->setTemperaturaMinima(val);

	//hora temperaturaMinima
	for(ok=false;!ok;){
		std::cout<<"Hora temperatura minima: hora "<<CYAN<<"[0]"<<RESET<<":\n\t->";
		std::getline(std::cin, cache);
		if(cache==""){
			ok=true;val=0;
		}else{
			try{ok=true;val=std::stof(cache.c_str());}
			catch(...){std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
		}
	}val2=val;
	for(ok=false;!ok;){
		std::cout<<"Hora temperatura minima: minuto "<<CYAN<<"[0]"<<RESET<<":\n\t->";
		std::getline(std::cin, cache);
		if(cache==""){
			ok=true;val=0;
		}else{
			try{ok=true;val=std::stof(cache.c_str());}
			catch(...){std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
		}
	}this->setHoraTemperaturaMinima(Hora(val2,val));

	//temperaturaMedia
	for(ok=false;!ok;){
		std::cout<<"Temperatura media "<<CYAN<<"[0]"<<RESET<<":\n\t->";
		std::getline(std::cin, cache);
		if(cache==""){
			ok=true;val=0;
		}else{
			try{ok=true;val=std::stof(cache.c_str());}
			catch(...){std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
		}
	}this->setTemperaturaMedia(val);

	//humedaddRelativaMaxima
	for(ok=false;!ok;){
		std::cout<<"Humedad relativa maxima "<<CYAN<<"[0]"<<RESET<<":\n\t->";
		std::getline(std::cin, cache);
		if(cache==""){
			ok=true;val=0;
		}else{
			try{ok=true;val=std::stof(cache.c_str());}
			catch(...){std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
		}
	}this->setHumedadRelativaMaxima(val);

	//humedaddRelativaMinima
	for(ok=false;!ok;){
		std::cout<<"Humedad relativa minima "<<CYAN<<"[0]"<<RESET<<":\n\t->";
		std::getline(std::cin, cache);
		if(cache==""){
			ok=true;val=0;
		}else{
			try{ok=true;val=std::stof(cache.c_str());}
			catch(...){std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
		}
	}this->setHumedadRelativaMinima(val);

	//humedaddRelativaMedia
	for(ok=false;!ok;){
		std::cout<<"Humedad relativa media "<<CYAN<<"[0]"<<RESET<<":\n\t->";
		std::getline(std::cin, cache);
		if(cache==""){
			ok=true;val=0;
		}else{
			try{ok=true;val=std::stof(cache.c_str());}
			catch(...){std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
		}
	}this->setHumedadRelativaMedia(val);

	//velocidadVientoMedia
	for(ok=false;!ok;){
		std::cout<<"Velocidad del viento media "<<CYAN<<"[0]"<<RESET<<":\n\t->";
		std::getline(std::cin, cache);
		if(cache==""){
			ok=true;val=0;
		}else{
			try{ok=true;val=std::stof(cache.c_str());}
			catch(...){std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
		}
	}this->setVelocidadVientoMedia(val);

	//direccionVientoMedia
	for(ok=false;!ok;){
		std::cout<<"Direcion media del viento "<<CYAN<<"[0]"<<RESET<<":\n\t->";
		std::getline(std::cin, cache);
		if(cache==""){
			ok=true;val=0;
		}else{
			try{ok=true;val=std::stof(cache.c_str());}
			catch(...){std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
		}
	}this->setDireccionVientoMedia(val);

	//radiacionSolar
	for(ok=false;!ok;){
		std::cout<<"Radiacion solar "<<CYAN<<"[0]"<<RESET<<":\n\t->";
		std::getline(std::cin, cache);
		if(cache==""){
			ok=true;val=0;
		}else{
			try{ok=true;val=std::stof(cache.c_str());}
			catch(...){std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
		}
	}this->setRadiacionSolar(val);

	//eto
	for(ok=false;!ok;){
		std::cout<<"Eto "<<CYAN<<"[0]"<<RESET<<":\n\t->";
		std::getline(std::cin, cache);
		if(cache==""){
			ok=true;val=0;
		}else{
			try{ok=true;val=std::stof(cache.c_str());}
			catch(...){std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
		}
	}this->setEto(val);


	//valid
	this->setValid(true);


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
