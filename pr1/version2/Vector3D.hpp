/*!
   \file Vector3D.hpp
   \brief Fichero de definición de la clase Vector3D: vector libre de tres dimensiones
	 \author Diego Rodriguez Riera90
	 \date february/2018
*/

#ifndef _VECTOR3D_HPP_
#define _VECTOR3D_HPP_

// Entrada y salida
#include <iostream>

// Para usar abs
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

// COMPLETAR, SI ES PRECISO


// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación números reales


// Se incluye la clase Vector3D dentro del espacio de nombre de la asigantura: ed
namespace ed {
//! \brief estructura que representa las coordenadas del vector
struct Punto{
	//! \brief coordenada x
	double x_;
	//! \brief coordenada y
	double y_;
	//! \brief coordenada z
	double z_;
};


//!  Definición de la clase Vector3D:  \f$ \vec{v} = (v_1, v_2, v_3) = v_1 \vec{i} + v_2 \vec{j} + v_3 \vec{k} \f$
class Vector3D
{
  //! \name Atributos privados de la clase Vector3D
  private:
	//! \brief coordenadas del objeto
	Punto coordenadas;

  //! \name Funciones o métodos públicos de la clase Vector3D
  public:

	//! \name Constructores de la clase Vector3D
	/*!
	\brief constructor sin parametros
	*/
	Vector3D() {
		coordenadas.x_=0;
		coordenadas.y_=0;
		coordenadas.z_=0;
	};
	/*!
	\brief constructor com parametros
	\param real: coordenada x del vector
	\param real: coordenada y del vector
	\param real: coordenada z del vector
	*/
	Vector3D(double _x ,double _y ,double _z) {
		coordenadas.x_=_x;
		coordenadas.y_=_y;
		coordenadas.z_=_z;
	};

	/*!
	\brief constructor de copia
	\param vector: el objeto a copiar
	*/
	Vector3D(const Vector3D &obj) {
		this->set1(obj.get1());
		this->set2(obj.get2());
		this->set3(obj.get3());
	};

////////////////////////////////////////////////////////////////////////////
	//! \name Observadores: funciones de consulta de Vector3D

	//geters
	/*!
	\brief geter de la coordenada x
	\return real: valor de coordenada x
	*/
	inline double get1() const {return coordenadas.x_;};
	/*!
	\brief geter de la coordenada y
	\return real: valor de coordenada y
	*/
	inline double get2() const {return coordenadas.y_;};
	/*!
	\brief geter de la coordenada z
	\return real: valor de coordenada z
	*/
	inline double get3() const {return coordenadas.z_;};


	//returns the module of the vector, is overloaded
	/*!
	\brief calcula el modulo de un vector
	\param vector: vector a calcular el modulo
	\return real: modulo del vector
	*/
	double modulo(Vector3D const &vector) const ;
	//overloaded version
	/*!
	\brief calcula el modulo del vector
	\return real: modulo del vector del objeto
	*/
	inline double modulo() const { return modulo(*this); };


	//returns the angle of v1 and v2, is overloaded
	/*!
	\brief calcula el angulo de un vector respecto a otro
	\param vector: vector 1
	\param vector: vector 2
	\return angulo: angulo entre vectores en radianes
	*/
	double angulo(Vector3D const &v1, Vector3D const &v2) const ;
	//overloaded version
	/*!
	\brief calcula en angulo entre unn vector y el vector objeto
	\param vector vector a calcular el angilo con
	\return angulo: angulo entre vectores this y parametro
	*/
	inline double angulo(Vector3D const &v2) const { return angulo(*this,v2); };


	//returns the angle that forms the vector and the cardinal axis
	/*!
	\brief angulo de un vector y i
	\param vector:
	\return angulo: alfa
	*/
	inline double alfa(Vector3D const &v) const {
		Vector3D i(1,0,0);
		return angulo(v,i);
	};
	/*!
	\brief angulo de un vector y j
	\param vector:
	\return angulo: beta
	*/
	inline double beta(Vector3D const &v) const {
		Vector3D j(0,1,0);
		return angulo(v,j);
	};
	/*!
	\brief angulo de un vector y k
	\param un vector
	\return angulo gamma
	*/
	inline double gamma(Vector3D const &v) const {
		Vector3D k(0,0,1);
		return angulo(v,k);
	};
	//overloaded versions
	/*!
	\brief calcula el angulo entre this e i
	\return angulo: alfa
	*/
	inline double alfa() const { return alfa (*this); };
	/*!
	\brief calcula el angulo entre this e y
	\return angulo: beta
	*/
	inline double beta() const { return beta (*this); };
	/*!
	\brief calcula el angulo entre this y k
	\return angulo: gamma
	*/
	inline double gamma()const { return gamma(*this); };


	//scalar product, is overloaded
	/*!
	\brief calcula el producto escalar de un vector
	\param vector: vector 1
	\param vector: vector 2
	\return real: resultado del producto
	*/
	double dotProduct(Vector3D const &v1, Vector3D const &v2) const;
	//overloaded version
	/*!
	\brief calcula el producto escalar de this y un vector
	\param vector: vector con el que calcular el producto
	\return real: resultado del producto
	*/
	inline double dotProduct(Vector3D const &vector) const{//v1 is *this
		return dotProduct(*this,vector);
	};

	//vectorial product, is overloaded
	/*!
	\brief calcula el producto vectorial de dos vectores
	\param vector: vector 1 con el que calcular el producto
	\param vector: vector 2 con el que calcular el producto
	\return vector: resultado del producto
	*/
	Vector3D& crossProduct(Vector3D const &v1, Vector3D const &v2) const;
	//overloaded version
	/*!
	\brief calcula el producto vectorial de this y el parametro
	\param vector: vector con el que calcular el producto
	\return vector: resultado del producto
	*/
	inline Vector3D& crossProduct(Vector3D const &vector) const{//v1 is *this
		return crossProduct(*this,vector);
	};

	//mixt product, is overloaded
	/*!
	\brief calcula el producto mixto de dos vectores
	\param vector: vector 1 con el que calcular el producto
	\param vector: vector 2 con el que calcular el producto
	\param vector: vector 3 con el que calcular el producto
	\return real: resultado del producto
	*/
	double productoMixto(Vector3D v1, Vector3D const &v2, Vector3D const &v3) const;
	//overloaded version
	/*!
	\brief calcula el producto mixto de dos vectores
	\param vector: vector 1 con el que calcular el producto
	\param vector: vector 2 con el que calcular el producto
	\return real: resultado del producto
	*/
	inline double productoMixto(Vector3D const &v2, Vector3D const &v3) const{//v1 is *this
		return productoMixto(*this,v2,v3);
	};

	//make the vectorial sum of v1 and v2 and returns it
	/*!
	\brief calcula la suma vectorial de dos vectores
	\param vector: vector 1 con el que operar
	\param vector: vector 2 con el que operar
	\return vector: resultado de la suma
	*/
	inline Vector3D& sum(Vector3D const &v1, Vector3D const &v2)const{
		Vector3D *aux=new Vector3D();
		aux->set1(v1.get1()+v2.get1());
		aux->set2(v1.get2()+v2.get2());
		aux->set3(v1.get3()+v2.get3());
		return *aux;
	}




////////////////////////////////////////////////////////////////////////////
	//! \name Modificadores: funciones de modificación de Vector3D

	//seters
	/*!
	\brief seter de x
	\param real: nuevo valor de x
	*/
	inline void set1(double _x) {coordenadas.x_=_x;};
	/*!
	\brief seter de y
	\param real: nuevo valor de y
	*/
	inline void set2(double _y) {coordenadas.y_=_y;};
	/*!
	\brief seter de z
	\param real: nuevo valor de z
	*/
	inline void set3(double _z) {coordenadas.z_=_z;};

	//sum overloaded
	/*!
	\brief suma una constante a los componentes de un vector
	\param vector: vector a sumar constante
	\param real: constante a sumar
	\return vector: vector con valor actualizado
	*/
	void sumConst(Vector3D const &vector, double diference);
	/*!
	\brief suma dos vectores componente a componente
	\param vector: vector 1 a sumar constante
	\param vector: vector 2 a sumar constante
	\return vector: vector con valor actualizado
	*/
	void sumConst(Vector3D const &v1, Vector3D const &v2);
	//overloaded version
	/*!
	\brief suma una constante a los componentes de un vector this
	\param real: constante a sumar
	\return vector: vector con valor actualizado
	*/
	inline void sumConst(double diference){ sumConst(*this,diference); };
	/*!
	\brief suma de un vector y los componentes de un vector this
	\param vector: vector a sumar con this
	\return vector: vector con valor actualizado
	*/
	inline void sumConst(Vector3D const &v2){ sumConst(*this,v2); };


	//mult overloaded
	/*!
	\brief multiplica por constante los componentes de un vector
	\param vector: vector a multiplicar constante
	\param real: multiplo
	\return vector: vector con valor actualizado
	*/
	void multConst(Vector3D vector, double mult);
	/*!
	\brief multiplica dos vectores entre si
	\param vector: vector 1 a multiplicar
	\param vector: vector 2 a multiplicar
	\return vector: vector con valor actualizado
	*/
	void multConst(Vector3D const &v1, Vector3D const &v2);
	//overloaded version
	/*!
	\brief multiplica por constante los componentes de un vector This
	\param real: multiplo
	\return vector: vector con valor actualizado
	*/
	inline void multConst(double mult){ multConst(*this,mult); };
	/*!
	\brief multiplica un vector por this
	\param vector: vector a multiplicar
	\return vector: vector con valor actualizado
	*/
	inline void multConst(Vector3D const &vector){ multConst(*this,vector); };

	//vectorial multiplication overloaded
	/*!
	\brief multiplicacion vectorial de dos vectores
	\param vector: vector donde se guardara el valor de la operacion y vector 1 de la operacion
	\param vector: vector 2 de la operación
	*/
	void multVect(Vector3D v1, Vector3D const &v2);
	//overloaded version
	/*!
	\brief multiplicacion vectorial de dos vectores this y el parametro, guardandose en this
	\param vector: uno de los vectores de la operación
	*/
	inline void multVect(Vector3D const &vector){ multVect(*this,vector); };


	//reads the elements of the vector, is overloaded
	/*!
	\brief lee desde la pantalla los valores de un vector y los asigna
	\param vector: vector a asignar
	*/
	inline void leerVector3D(Vector3D &vector){
		double temp;
		std::cout << "enter x >> ";
		std::cin>>temp;
		vector.set1(temp);

		std::cout << "enter y >> ";
		std::cin>>temp;
		vector.set2(temp);

		std::cout << "enter z >> ";
		std::cin>>temp;
		vector.set3(temp);
	};
	//overloaded version
	/*!
	\brief lee desde la pantalla los valores de un vector y los asigna a el vector this
	*/
	inline void leerVector3D(){ leerVector3D(*this); };

	//whrites the elements of the vector, is overloaded
	/*!
	\brief escribe en pantalla un vector
	\param vector: vector a imprimir
	*/
	inline void escribirVector3D(Vector3D const &vector)const{
		std::cout<<"("<<	vector.get1()<<',';
		std::cout<<				vector.get2()<<',';
		std::cout<<				vector.get3()<<')'<<'\n';
	};
	//overloaded version
	/*!
	\brief escribe en pantalla el vector this
	*/
	inline void escribirVector3D() const { escribirVector3D(*this);	};
	/*!
	\brief comprueba la igualdad de dos vectores
	\param vector: vector 1 a comprobar la igualdad
	\param vector: vector 2 a comprobar la igualdad
	\return boolean: verdadero si se cumple la igualdad
	*/
	inline bool is_equal(Vector3D const &v1, Vector3D const &v2) const {
		if (v1.get1()==v2.get1()
		and v1.get2()==v2.get2()
		and	v1.get3()==v2.get3()){
			return true;
		}else return false;
	}

////////////////////////////////////////////////////////////////////////////
  //! \name Operadores de la clase



	// COMPLETAR COMENTARIOS DE DOXYGEN
	/*!
	\brief operador de asignación
	\param vector: vector a asignar a this
	\return vector: parametro asignado
	*/
	Vector3D& operator=(Vector3D const &objeto);

	// COMPLETAR COMENTARIOS DE DOXYGEN
	/*!
	\brief comprueba la igualdad de dos vectores
	\param vector: vector a comprobar igualdad con
	\return boolean: verdadero si se cumple la igualdad
	*/
	bool operator == (Vector3D const &objeto) const;

	/*!
	\brief calcula el producto escalar de dos vectores (this por el parametro)
	\param vector: vector con el que operar
	\return vector: vector con el valor actualizado
	*/
	Vector3D& operator* (ed::Vector3D const & v)const;
	/*!
	\brief calcula el producto de una cosntante por los componentes de un vector this
	\param real: constante
	\return vector: vector con el valor actualizado
	*/
	Vector3D& operator*(double k)const;
	/*!
	\brief calcula el producto vectorial de dos vectores (this por el parametro)
	\param vector: vector con el que operar
	\return vector: vector con el valor actualizado
	*/
	Vector3D& operator^(ed::Vector3D const & v)const;

	/*!
	\brief calcula la suma de dos vectores (this + parametro)
	\param vector: vector con el que operar
	\return vector: vector con el valor actualizado
	*/
	Vector3D& operator+(Vector3D const &v)const;
	/*!
	\brief crea una copia del vector parametro
	\return vector: vector copia
	*/
	Vector3D& operator+(void)const;

	/*!
	\brief calcula la resta de dos vectores (this - parametro)
	\param vector: vector con el que operar
	\return vector: vector con el valor actualizado
	*/
	Vector3D& operator-(Vector3D const &v)const;
	//changes the sign of the vector
	/*!
	\brief crea una copia del vector parametro y niega los signos de sus componentes
	\return vector: vector copia con signo negado
	*/
	Vector3D& operator-(void)const;


	//! \name Funciones lectura y escritura de la clase Vector3D

	// COMPLETAR

}; // Fin de la definición de la clase Vector3D


////////////////////////////////////////////////////////////////////////////
//! \name Funciones que utilizan un objetos de la clase Vector3D, pero que no pertenecen a la clase Vector3D

	// COMPLETAR COMENTARIOS DE DOXYGEN
	/*!
	\brief multiplica un vector (componentes) por una cosntante
	\param real: constante a multiplicar el vector
	\param vector: vector con el que multiplicar
	\return vector: vector con valor actualzado
	*/
  Vector3D & operator*(double k, Vector3D const & objeto);


	// COMPLETAR COMENTARIOS DE DOXYGEN
	/*!
	\brief lee de un stream los valores de un vector
	\param stream: stream de entrada de datos
	\param vector: vector al que actualizar los datos
	\return vector: vector con los datos actualizados
	*/
  istream &operator>>(istream &stream, Vector3D &objeto);

	// COMPLETAR COMENTARIOS DE DOXYGEN
	/*!
	\brief escribe en un stream los valores de un vector
	\param stream: stream a actualizar de salida de datos
	\param vector: vector al imprimir los datos
	\return stream: stream de salida actualizado
	*/
	ostream &operator<<(ostream &stream, Vector3D const &objeto);



} // \brief Fin de namespace ed.

//  _VECTOR3D_HPP_
#endif
