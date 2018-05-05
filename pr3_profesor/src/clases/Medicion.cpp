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
}


bool Medicion::isValid() const {
	if ( ! (getFecha().esCorrecta()) ){
		return false;
	}
	if ( ! (getPrecipitacion()>=0 && getPrecipitacion()<=9999) ){
		return false;
	}
	if ( ! (getTemperaturaMaxima()>=getTemperaturaMinima() && getTemperaturaMaxima()<=100) ){
		return false;
	}
	if ( ! (getHoraTemperaturaMaxima().isValid()) ){
		return false;
	}
	if ( ! (getTemperaturaMinima()>=-100 && getTemperaturaMinima()<=getTemperaturaMaxima()) ){
		return false;
	}
	if ( ! (getHoraTemperaturaMinima().isValid()) ){
		return false;
	}
	if ( ! (getTemperaturaMedia()>=getTemperaturaMinima() && getTemperaturaMedia()<=getTemperaturaMaxima()) ){
		return false;
	}
	if ( ! (getHumedadRelativaMaxima()>=getHumedadRelativaMinima() && getHumedadRelativaMaxima()<=100) ){
		return false;
	}
	if ( ! (getHumedadRelativaMinima()>=0 && getHumedadRelativaMinima()<=getHumedadRelativaMaxima()) ){
		return false;
	}
	if ( ! (getHumedadRelativaMedia()>=getHumedadRelativaMinima() && getHumedadRelativaMedia()<=getHumedadRelativaMaxima()) ){
		return false;
	}
	if ( ! (getVelocidadVientoMedia()>=0 && getVelocidadVientoMedia()<=500) ){
		return false;
	}
	if ( ! (getDireccionVientoMedia()>=0 && getDireccionVientoMedia()<=365) ){
		return false;
	}
	if ( ! (getRadiacionSolar()>=0 && getRadiacionSolar()<=100) ){
		return false;
	}
	if ( ! (getEto()>=0 && getEto()<=1000) ){
		return false;
	}
	return true;
}


void Medicion::leerMedicion(){
	this->setTemperaturaMinima(-100);
	float val, val2, val3;
	std::string cache;
	bool ok;
	char s=' ';
	std::cout <<"Los valores predeterminados serán indicados por '[]'\n\nIntroduzca los valores requeridos:\n\n";
	for(ok=false;!ok;){
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
		if (this->getFecha().esCorrecta()){ok=true;
		}else{std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
	}

	//precipitacion
	for(ok=false;!ok;){
		std::cout<<"Precipitacion "<<CYAN<<"[0]"<<RESET<<":\n\t->";
		std::getline(std::cin, cache);
		if(cache==""){
			ok=true;val=0;
			this->setPrecipitacion(val);
		}else{
			try{ok=true;val=std::stof(cache.c_str());}
			catch(...){std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
			this->setPrecipitacion(val);
			if (this->isValid()){ok=true;
			}else{std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
		}
	}


	//temperaturaMaxima
	for(ok=false;!ok;){
		std::cout<<"Temperatura maxima "<<CYAN<<"[0]"<<RESET<<":\n\t->";
		std::getline(std::cin, cache);
		if(cache==""){
			ok=true;val=0;
			this->setTemperaturaMaxima(val);
		}else{
			try{ok=true;val=std::stof(cache.c_str());}
			catch(...){std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
			this->setTemperaturaMaxima(val);
			if (this->isValid()){ok=true;
			}else{std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
		}
	}

	//hora temperaturaMaxima
	for(ok=false;!ok;){
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
		}
		this->setHoraTemperaturaMaxima(Hora(val2,val));
		if (this->isValid()){ok=true;
		}else{std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
	}

	//temperaturaMinima
	for(ok=false;!ok;){
		std::cout<<"Temperatura minima "<<CYAN<<"[0]"<<RESET<<":\n\t->";
		std::getline(std::cin, cache);
		if(cache==""){
			ok=true;val=0;
			this->setTemperaturaMinima(val);
		}else{
			try{ok=true;val=std::stof(cache.c_str());}
			catch(...){std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
			this->setTemperaturaMinima(val);
			if (this->isValid()){ok=true;
			}else{std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
		}
	}

	//hora temperaturaMinima
	for(ok=false;!ok;){
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
		}
		this->setHoraTemperaturaMinima(Hora(val2,val));
		if (this->isValid()){ok=true;
		}else{std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
	}

	//temperaturaMedia
	for(ok=false;!ok;){
		std::cout<<"Temperatura media "<<CYAN<<"[0]"<<RESET<<":\n\t->";
		std::getline(std::cin, cache);
		if(cache==""){
			ok=true;val=0;
			this->setTemperaturaMedia(val);
		}else{
			try{ok=true;val=std::stof(cache.c_str());}
			catch(...){std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
			this->setTemperaturaMedia(val);
			if (this->isValid()){ok=true;
			}else{std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
		}
	}

	//humedaddRelativaMaxima
	for(ok=false;!ok;){
		std::cout<<"Humedad relativa maxima "<<CYAN<<"[0]"<<RESET<<":\n\t->";
		std::getline(std::cin, cache);
		if(cache==""){
			ok=true;val=0;
			this->setHumedadRelativaMaxima(val);
		}else{
			try{ok=true;val=std::stof(cache.c_str());}
			catch(...){std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
			this->setHumedadRelativaMaxima(val);
			if (this->isValid()){ok=true;
			}else{std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
		}
	}

	//humedaddRelativaMinima
	for(ok=false;!ok;){
		std::cout<<"Humedad relativa minima "<<CYAN<<"[0]"<<RESET<<":\n\t->";
		std::getline(std::cin, cache);
		if(cache==""){
			ok=true;val=0;
			this->setHumedadRelativaMinima(val);
		}else{
			try{ok=true;val=std::stof(cache.c_str());}
			catch(...){std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
			this->setHumedadRelativaMinima(val);
			if (this->isValid()){ok=true;
			}else{std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
		}
	}

	//humedaddRelativaMedia
	for(ok=false;!ok;){
		std::cout<<"Humedad relativa media "<<CYAN<<"[0]"<<RESET<<":\n\t->";
		std::getline(std::cin, cache);
		if(cache==""){
			ok=true;val=0;
			this->setHumedadRelativaMedia(val);
		}else{
			try{ok=true;val=std::stof(cache.c_str());}
			catch(...){std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
			this->setHumedadRelativaMedia(val);
			if (this->isValid()){ok=true;
			}else{std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
		}
	}

	//velocidadVientoMedia
	for(ok=false;!ok;){
		std::cout<<"Velocidad del viento media "<<CYAN<<"[0]"<<RESET<<":\n\t->";
		std::getline(std::cin, cache);
		if(cache==""){
			ok=true;val=0;
			this->setVelocidadVientoMedia(val);
		}else{
			try{ok=true;val=std::stof(cache.c_str());}
			catch(...){std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
			this->setVelocidadVientoMedia(val);
			if (this->isValid()){ok=true;
			}else{std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
		}
	}

	//direccionVientoMedia
	for(ok=false;!ok;){
		std::cout<<"Direcion media del viento "<<CYAN<<"[0]"<<RESET<<":\n\t->";
		std::getline(std::cin, cache);
		if(cache==""){
			ok=true;val=0;
			this->setDireccionVientoMedia(val);
		}else{
			try{ok=true;val=std::stof(cache.c_str());}
			catch(...){std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
			this->setDireccionVientoMedia(val);
			if (this->isValid()){ok=true;
			}else{std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
		}
	}

	//radiacionSolar
	for(ok=false;!ok;){
		std::cout<<"Radiacion solar "<<CYAN<<"[0]"<<RESET<<":\n\t->";
		std::getline(std::cin, cache);
		if(cache==""){
			ok=true;val=0;
			this->setRadiacionSolar(val);
		}else{
			try{ok=true;val=std::stof(cache.c_str());}
			catch(...){std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
			this->setRadiacionSolar(val);
			if (this->isValid()){ok=true;
			}else{std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
		}
	}

	//eto
	for(ok=false;!ok;){
		std::cout<<"Eto "<<CYAN<<"[0]"<<RESET<<":\n\t->";
		std::getline(std::cin, cache);
		if(cache==""){
			ok=true;val=0;
			this->setEto(val);
		}else{
			try{ok=true;val=std::stof(cache.c_str());}
			catch(...){std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
			this->setEto(val);
			if (this->isValid()){ok=true;
			}else{std::cout<<"introduzca"<<s<<"valor"<<s<<"valido"<<'\n';ok=false;}
		}
	}

	std::cout << "medicion leida correctamente" << '\n';
	this->escribirMedicion();
	std::cout <<'\n';


}

void Medicion::escribirMedicion() const {
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

std::string Medicion::getMedicionString() const {
	std::ostringstream stream;
	stream<<getFecha().getFechaString() << ";0;"
				<<getTemperaturaMaxima()<<";"
				<<getHoraTemperaturaMaxima().getHoraString()<<";"
				<<getTemperaturaMinima()<<";"
				<<getHoraTemperaturaMinima().getHoraString()<<";"
				<<getTemperaturaMedia()<<";"
				<<getHumedadRelativaMaxima()<<";"
				<<getHumedadRelativaMinima()<<";"
				<<getHumedadRelativaMedia()<<";"
				<<getVelocidadVientoMedia()<<";"
				<<getDireccionVientoMedia()<<";"
				<<getRadiacionSolar()<<";"
				<<getPrecipitacion()<<";"
				<<getEto();
	return stream.str();
}

void Medicion::cargarMedicionDeFichero(std::istream &stream){
	Medicion medicion;
	int h,m,dp;
	char cache_char[1000];
	stream.getline(cache_char, 10000, '\n');
	std::string all_cache=cache_char;
	size_t position;
	std::string cache;

		// std::cout <<CYAN<< "cache:" <<all_cache<< RESET<<'\n';
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
		// std::cout <<CYAN<< "ignores:" <<all_cache<< RESET<<'\n';
	position=all_cache.find(";",0);
	cache=all_cache.substr(0,position);
	all_cache=all_cache.substr(position+1,all_cache.size());
	position=all_cache.find(";",0);
	cache=all_cache.substr(0,position);
	all_cache=all_cache.substr(position+1,all_cache.size());

		// std::cout <<CYAN<< "tempmax:" <<all_cache<< RESET<<'\n';
	position=all_cache.find(";",0);
	cache=all_cache.substr(0,position);
	all_cache=all_cache.substr(position+1,all_cache.size());
	this->setTemperaturaMaxima(atof(cache.c_str()));
		// std::cout <<CYAN<< "\tval:<" <<atof(cache.c_str())<<">"<< RESET<<'\n';

		// std::cout <<CYAN<< "horatempmax:" <<all_cache<< RESET<<'\n';
	position=all_cache.find(";",0);
	cache=all_cache.substr(0,position);
	all_cache=all_cache.substr(position+1,all_cache.size());
	dp=cache.find(':');
	h=atoi(cache.substr(0,dp).c_str());
	m=atoi(cache.substr(dp+1,cache.size()).c_str());
	this->setHoraTemperaturaMaxima(Hora(h,m));
		// std::cout <<CYAN<< "\tval:<" <<cache<<">"<< RESET<<'\n';

		// std::cout <<CYAN<< "tempmin:" <<all_cache<< RESET<<'\n';
	position=all_cache.find(";",0);
	cache=all_cache.substr(0,position);
	all_cache=all_cache.substr(position+1,all_cache.size());
	this->setTemperaturaMinima(atof(cache.c_str()));
		// std::cout <<CYAN<< "\tval:<" <<atof(cache.c_str())<<">"<< RESET<<'\n';

		// std::cout <<CYAN<< "horatempmin:" <<all_cache<< RESET<<'\n';
	position=all_cache.find(";",0);
	cache=all_cache.substr(0,position);
	all_cache=all_cache.substr(position+1,all_cache.size());
	dp=cache.find(':');
	h=atoi(cache.substr(0,dp).c_str());
	m=atoi(cache.substr(dp+1,cache.size()).c_str());
	this->setHoraTemperaturaMinima(Hora(h,m));
		// std::cout <<CYAN<< "\tval:<" <<cache<<">"<< RESET<<'\n';

		// std::cout <<CYAN<< "tempmedia:" <<all_cache<< RESET<<'\n';
	position=all_cache.find(";",0);
	cache=all_cache.substr(0,position);
	all_cache=all_cache.substr(position+1,all_cache.size());
	this->setTemperaturaMedia(atof(cache.c_str()));
		// std::cout <<CYAN<< "\tval:<" <<atof(cache.c_str())<<">"<< RESET<<'\n';

		// std::cout <<CYAN<< "humrelmax:" <<all_cache<< RESET<<'\n';
	position=all_cache.find(";",0);
	cache=all_cache.substr(0,position);
	all_cache=all_cache.substr(position+1,all_cache.size());
	this->setHumedadRelativaMaxima(atof(cache.c_str()));
		// std::cout <<CYAN<< "\tval:<" <<atof(cache.c_str())<<">"<< RESET<<'\n';

		// std::cout <<CYAN<< "humrelmin:" <<all_cache<< RESET<<'\n';
	position=all_cache.find(";",0);
	cache=all_cache.substr(0,position);
	all_cache=all_cache.substr(position+1,all_cache.size());
	this->setHumedadRelativaMinima(atof(cache.c_str()));
		// std::cout <<CYAN<< "\tval:<" <<atof(cache.c_str())<<">"<< RESET<<'\n';

		// std::cout <<CYAN<< "humrelmed:" <<all_cache<< RESET<<'\n';
	position=all_cache.find(";",0);
	cache=all_cache.substr(0,position);
	all_cache=all_cache.substr(position+1,all_cache.size());
	this->setHumedadRelativaMedia(atof(cache.c_str()));
		// std::cout <<CYAN<< "\tval:<" <<atof(cache.c_str())<<">"<< RESET<<'\n';

		// std::cout <<CYAN<< "windspeed:" <<all_cache<< RESET<<'\n';
	position=all_cache.find(";",0);
	cache=all_cache.substr(0,position);
	all_cache=all_cache.substr(position+1,all_cache.size());
	this->setVelocidadVientoMedia(atof(cache.c_str()));
		// std::cout <<CYAN<< "\tval:<" <<atof(cache.c_str())<<">"<< RESET<<'\n';

		// std::cout <<CYAN<< "windangle:" <<all_cache<< RESET<<'\n';
	position=all_cache.find(";",0);
	cache=all_cache.substr(0,position);
	all_cache=all_cache.substr(position+1,all_cache.size());
	this->setDireccionVientoMedia(atof(cache.c_str()));
		// std::cout <<CYAN<< "\tval:<" <<atof(cache.c_str())<<">"<< RESET<<'\n';

	position=all_cache.find(";",0);
	cache=all_cache.substr(0,position);
	all_cache=all_cache.substr(position+1,all_cache.size());
	this->setRadiacionSolar(atof(cache.c_str()));
		// std::cout <<CYAN<< "\tval:<" <<atof(cache.c_str())<<">"<< RESET<<'\n';

		// std::cout <<CYAN<< "precipit:" <<all_cache<< RESET<<'\n';
	position=all_cache.find(";",0);
	cache=all_cache.substr(0,position);
	all_cache=all_cache.substr(position+1,all_cache.size());
	this->setPrecipitacion(atof(cache.c_str()));
		// std::cout <<CYAN<< "\tval:<" <<atof(cache.c_str())<<">"<< RESET<<'\n';

		// std::cout <<CYAN<< "eto:" <<all_cache<< RESET<<'\n';
	position=all_cache.find(";",0);
	cache=all_cache.substr(0,position);
	all_cache=all_cache.substr(position+1,all_cache.size());
	this->setEto(atof(cache.c_str()));
		// std::cout <<CYAN<< "\tval:<" <<atof(cache.c_str())<<">"<< RESET<<'\n';



	// std::cout <<UWHITE;
	// this->escribirMedicion();
	// std::cout <<RESET;
}

void Medicion::clear() {
	setFecha(Fecha(0,0,0));
	setPrecipitacion(0);
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
}


// Sobrecarga del operador de salida
std::ostream &operator<<(std::ostream &stream, Medicion const &medicion)
{
	stream << "WIP";
	stream << "\n";

  return stream;
}

// Sobrecarga del operador de entrada
std::istream &operator>>(std::istream &stream, Medicion &medicion)
{
	std::cout << "WIP" << '\n';
	// std::string cache;
	// std::getline(stream, cache, '-');
	// int dia=atoi(cache.c_str());
	// std::getline(stream, cache, '-');
	// int mes=atoi(cache.c_str());
	// std::getline(stream, cache, '-');
	// int ano=atoi(cache.c_str());
	// Fecha fecha(dia,mes,ano);
	// std::cout <<fecha.getFechaString()<< '\n';
	// medicion.setFecha(fecha);
	// std::getline(stream, cache, ';');
	// std::getline(stream, cache, ';');
	// medicion.setTemperaturaMaxima(atof(cache.c_str()));
	//
	// std::getline(stream, cache, ';');
	// int dp=cache.find(':');
	// int h=atoi(cache.substr(0,dp).c_str());
	// int m=atoi(cache.substr(dp+1,cache.size()).c_str());
	// medicion.setHoraTemperaturaMaxima(Hora (h,m));
	//
	// std::getline(stream, cache, ';');
	// medicion.setTemperaturaMinima(atof(cache.c_str()));
	//
	// std::getline(stream, cache, ';');
	// dp=cache.find(':');
	// h=atoi(cache.substr(0,dp).c_str());
	// m=atoi(cache.substr(dp+1,cache.size()).c_str());
	// medicion.setHoraTemperaturaMinima(Hora (h,m));
	//
	// std::getline(stream, cache, ';');
	// medicion.setTemperaturaMedia(atof(cache.c_str()));
	// std::getline(stream, cache, ';');
	// medicion.setHumedadRelativaMaxima(atof(cache.c_str()));
	// std::getline(stream, cache, ';');
	// medicion.setHumedadRelativaMinima(atof(cache.c_str()));
	// std::getline(stream, cache, ';');
	// medicion.setHumedadRelativaMedia(atof(cache.c_str()));
	// std::getline(stream, cache, ';');
	// medicion.setVelocidadVientoMedia(atof(cache.c_str()));
	// std::getline(stream, cache, ';');
	// medicion.setDireccionVientoMedia(atof(cache.c_str()));
	// std::getline(stream, cache, ';');
	// medicion.setRadiacionSolar(atof(cache.c_str()));
	// std::getline(stream, cache, ';');
	// medicion.setPrecipitacion(atof(cache.c_str()));
	// std::getline(stream, cache, '\n');
	// medicion.setEto(atof(cache.c_str()));
	// medicion.setValid(true);

  return stream;
}

} // Fin del espacio de nombres ed
