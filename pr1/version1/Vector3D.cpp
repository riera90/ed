/*!
   \file Vector3D.cpp
   \brief Fichero que contiene el código de las funciones de la clase Vector3D
*/


// Ficheros de cabecera
#include <iostream>

// Para usar sqrt, acos
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

#include "Vector3D.hpp"

////////////////////////////////////////////////////////////////////////////
// OBSERVADORES

double ed::Vector3D::modulo(Vector3D const &vector) const {
	double aux;
	aux =powl(vector.get1(),(double)2);
	aux+=powl(vector.get2(),(double)2);
	aux+=powl(vector.get3(),(double)2);

	return sqrtl(aux);
}

double ed::Vector3D::angulo(Vector3D const &v1, Vector3D const &v2) const {
	if (v1.modulo()*v2.modulo()<=0) {
		return -1;
	}
	double aux=dotProduct(v1,v2);
	aux/=modulo(v1)*modulo(v2);
	aux=acos(aux);
	return aux;
}

double ed::Vector3D::dotProduct(ed::Vector3D const &v1,
																ed::Vector3D const &v2) const{
	double aux;
	aux =v1.get1()*v2.get1();
	aux+=v1.get2()*v2.get2();
	aux+=v1.get3()*v2.get3();
	return aux;
}

ed::Vector3D& ed::Vector3D::crossProduct(Vector3D const &v1, Vector3D const &v2) const{
	ed::Vector3D *aux=new ed::Vector3D();
	aux->set1( 		(v1.get2()	*	v2.get3()) - 		(v1.get3()	*	v2.get2()));
	aux->set2( (-	(v1.get1())	*	v2.get3()) + 		(v1.get3()	*	v2.get1()));
	aux->set3( 		(v1.get1()	*	v2.get2()) - (-	(v1.get2())	*	v2.get1()));
	return *aux;
}

double ed::Vector3D::productoMixto(	ed::Vector3D v1,
																		ed::Vector3D const &v2,
																		ed::Vector3D const &v3) const{
	return dotProduct(v1,crossProduct(v2,v3));
}


////////////////////////////////////////////////////////////////////////////
// MODIFICADORES

void ed::Vector3D::sumConst(ed::Vector3D const &vector, double diference){
	this->set1(vector.get1()+diference);
	this->set2(vector.get2()+diference);
	this->set3(vector.get3()+diference);
}

void ed::Vector3D::sumConst(Vector3D const &v1, Vector3D const &v2){
	this->set1(v1.get1()+v2.get1());
	this->set2(v1.get2()+v2.get2());
	this->set3(v1.get3()+v2.get3());
}

void ed::Vector3D::multConst(ed::Vector3D vector, double mult){
	this->set1(vector.get1()*mult);
	this->set2(vector.get2()*mult);
	this->set3(vector.get3()*mult);
}

void ed::Vector3D::multConst(Vector3D const &v1, Vector3D const &v2){
	this->set1(v1.get1()*v2.get1());
	this->set2(v1.get2()*v2.get2());
	this->set3(v1.get3()*v2.get3());
}

void ed::Vector3D::multVect(ed::Vector3D v1, ed::Vector3D const &v2){
	this->set1(	v1.get1()*v2.get1()	);
	this->set2(	v1.get2()*v2.get2()	);
	this->set3(	v1.get3()*v2.get3()	);
}



////////////////////////////////////////////////////////////////////////////
// OPERADORES

ed::Vector3D& ed::Vector3D::operator=(ed::Vector3D const &objeto){
	set1(objeto.get1());
	set2(objeto.get2());
	set3(objeto.get3());
	return *this;
}
bool ed::Vector3D::operator == (ed::Vector3D const &objeto) const{
	return is_equal(*this,objeto);
}

ed::Vector3D& ed::Vector3D::operator* (ed::Vector3D const & v)const{
	return ed::Vector3D::crossProduct(*this,v);
}

ed::Vector3D& ed::Vector3D::operator* (double k)const{
	ed::Vector3D *vectorResultado = new ed::Vector3D();

	vectorResultado->multConst(*this,k);

	return *vectorResultado;
}

ed::Vector3D& ed::Vector3D::operator^ (ed::Vector3D const & v)const{
	ed::Vector3D *aux=new ed::Vector3D();
	*aux=ed::Vector3D::crossProduct(*this,v);
	return *aux;
}

ed::Vector3D& ed::Vector3D::operator+(ed::Vector3D const &v)const{
	ed::Vector3D* aux=new ed::Vector3D();
	aux->set1(this->get1()+v.get1());
	aux->set2(this->get2()+v.get2());
	aux->set3(this->get3()+v.get3());
	return *aux;
}

ed::Vector3D& ed::Vector3D::operator+(void)const{
	ed::Vector3D* aux=new ed::Vector3D();
	return *aux;
}


ed::Vector3D& ed::Vector3D::operator-(ed::Vector3D const &v)const{
	ed::Vector3D* aux=new ed::Vector3D();
	aux->set1(this->get1()-v.get1());
	aux->set2(this->get2()-v.get2());
	aux->set3(this->get3()-v.get3());
	return *aux;
}

ed::Vector3D& ed::Vector3D::operator-(void)const{
	ed::Vector3D* aux=new ed::Vector3D();
	*aux=*this;
	aux->set1(-(aux->get1()));
	aux->set2(-(aux->get2()));
	aux->set3(-(aux->get3()));
	return *aux;
}








////////////////////////////////////////////////////////////////////////////
// FUNCIONES DE LECTURA Y ESCRITURA



////////////////////////////////////////////////////////////////////////////



// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed{


// Producto "por un" escalar (prefijo): k * v
ed::Vector3D & operator* (double k, ed::Vector3D const & objeto)
{
	ed::Vector3D *vectorResultado = new ed::Vector3D();

	vectorResultado->multConst(objeto,k);

	return *vectorResultado;
}


// Sobrecarga del operador de salida
// Se escriben por pantalla las coordenadas del vector 3D  de la forma (v1, v2, v3)
ostream &operator<<(ostream &stream, ed::Vector3D const &objeto)
{
	stream<<"x:"<<objeto.get1()<<'\t';
	stream<<"y:"<<objeto.get2()<<'\t';
	stream<<"z:"<<objeto.get3()<<'\n';
  return stream;
}

// Sobrecarga del operador de entrada
istream &operator>>(istream &stream, ed::Vector3D &objeto)
{
	double temp;
	std::cout << "enter x >> ";
	stream>>temp;
	objeto.set1(temp);

	std::cout << "enter y >> ";
	stream>>temp;
	objeto.set2(temp);

	std::cout << "enter z >> ";
	stream>>temp;
	objeto.set3(temp);

  return stream;
}



} // Fin del espacio de nombres ed
