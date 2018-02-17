/*!
   \file Vector3D.hpp
   \brief Fichero de definición de la clase Vector3D: vector libre de tres dimensiones
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


//!  Definición de la clase Vector3D:  \f$ \vec{v} = (v_1, v_2, v_3) = v_1 \vec{i} + v_2 \vec{j} + v_3 \vec{k} \f$
class Vector3D
{
  //! \name Atributos privados de la clase Vector3D
   private:

	double x_, y_, z_;


   //! \name Funciones o métodos públicos de la clase Vector3D
   public:

	//! \name Constructores de la clase Vector3D
	Vector3D() : x_(0), y_(0), z_(0) {};
	Vector3D(double _x ,double _y ,double _z) : x_(_x), y_(_y), z_(_z) {};

	//copy constructor
	Vector3D(const Vector3D &obj) {
		this->set1(obj.get1());
		this->set2(obj.get2());
		this->set3(obj.get3());
	};

////////////////////////////////////////////////////////////////////////////
	//! \name Observadores: funciones de consulta de Vector3D

	//geters
	inline double get1() const {return x_;};
	inline double get2() const {return y_;};
	inline double get3() const {return z_;};


	//returns the module of the vector, is overloaded
	double modulo(Vector3D const &vector) const ;
	//overloaded version
	inline double modulo() const { return modulo(*this); };


	//returns the angle of v1 and v2, is overloaded
	double angulo(Vector3D const &v1, Vector3D const &v2) const ;
	//overloaded version
	inline double angulo(Vector3D const &v2) const { return angulo(*this,v2); };


	//returns the angle that forms the vector and the cardinal axis
	inline double alfa(Vector3D const &v) const {
		Vector3D i(1,0,0);
		return angulo(v,i);
	};
	inline double beta(Vector3D const &v) const {
		Vector3D j(0,1,0);
		return angulo(v,j);
	};
	inline double gamma(Vector3D const &v) const {
		Vector3D k(0,0,1);
		return angulo(v,k);
	};
	//overloaded versions
	inline double alfa() const { return alfa (*this); };
	inline double beta() const { return beta (*this); };
	inline double gamma()const { return gamma(*this); };


	//scalar product, is overloaded
	double dotProduct(Vector3D const &v1, Vector3D const &v2) const;
	//overloaded version
	inline double dotProduct(Vector3D const &vector) const{//v1 is *this
		return dotProduct(*this,vector);
	};

	//vectorial product, is overloaded
	Vector3D crossProduct(Vector3D const &v1, Vector3D const &v2) const;
	//overloaded version
	inline Vector3D crossProduct(Vector3D const &vector) const{//v1 is *this
		return crossProduct(*this,vector);
	};

	//mixt product, is overloaded
	double productoMixto(Vector3D v1, Vector3D const &v2, Vector3D const &v3) const;
	//overloaded version
	inline double productoMixto(Vector3D const &v2, Vector3D const &v3) const{//v1 is *this
		return productoMixto(*this,v2,v3);
	};




////////////////////////////////////////////////////////////////////////////
	//! \name Modificadores: funciones de modificación de Vector3D

	//seters
	inline void set1(double _x) {x_=_x;};
	inline void set2(double _y) {y_=_y;};
	inline void set3(double _z) {z_=_z;};

	//sum overloaded
	void sumConst(Vector3D vector, double diference);
	//overloaded version
	inline void sumConst(double diference){ sumConst(*this,diference); };

	//mult overloaded
	void multConst(Vector3D vector, double mult);
	//overloaded version
	inline void multConst(double mult){ multConst(*this,mult); };

	//vectorial multiplication overloaded
	void multVect(Vector3D v1, Vector3D const &v2);
	//overloaded version
	inline void multVect(Vector3D const &vector){ multVect(*this,vector); };


	//reads the elements of the vector, is overloaded
	inline void leeVector3D(Vector3D vector){
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
	inline void leeVector3D(){ leeVector3D(*this); };

	//whrites the elements of the vector, is overloaded
	inline void escribirVector3D(Vector3D const &vector)const{
		std::cout<<"("<<	vector.get1()<<',';
		std::cout<<				vector.get2()<<',';
		std::cout<<				vector.get3()<<')'<<'\n';
	};
	//overloaded version
	inline void escribirVector3D() const { escribirVector3D(*this);	};

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
	Vector3D& operator=(Vector3D const &objeto);

	// COMPLETAR COMENTARIOS DE DOXYGEN
	bool operator == (Vector3D const &objeto) const;

	Vector3D& operator+(Vector3D const &v);
	Vector3D& operator-(Vector3D const &v);
	double operator* (ed::Vector3D const & v)const;
	Vector3D& operator^(ed::Vector3D const & v)const;


	//! \name Funciones lectura y escritura de la clase Vector3D

	// COMPLETAR

}; // Fin de la definición de la clase Vector3D


////////////////////////////////////////////////////////////////////////////
//! \name Funciones que utilizan un objetos de la clase Vector3D, pero que no pertenecen a la clase Vector3D

	// COMPLETAR COMENTARIOS DE DOXYGEN
  Vector3D & operator*(double k, Vector3D const & objeto);


	// COMPLETAR COMENTARIOS DE DOXYGEN
  istream &operator>>(istream &stream, Vector3D &objeto);

	// COMPLETAR COMENTARIOS DE DOXYGEN
	ostream &operator<<(ostream &stream, Vector3D const &objeto);


} // \brief Fin de namespace ed.

//  _VECTOR3D_HPP_
#endif
