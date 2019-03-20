/*!
	\file PolinomioUnittest.cpp
	\brief test de unidad de las funciones y operaciones internas y externas de la clase Polinomio
*/


#include "gtest/gtest.h"
#include "Polinomio.hpp"
#include "operadoresExternosPolinomios.hpp"
#include "Monomio.hpp"
#include "operadoresExternosMonomios.hpp"
#include "macros.hpp"
#include <iostream>


    /////////////////
  // Constructor //
/////////////////

TEST(Polinomio, default_constructor)
{
	ed::Polinomio p1;
	ed::Monomio mNullo(0, 0);
	
	EXPECT_EQ(p1.getGrado(), 0);
	EXPECT_EQ(p1.getNumeroMonomios(), 0);
	EXPECT_TRUE(p1.esNulo());
	
	for (size_t i = 0; i < 100; i++) {
		EXPECT_FALSE(p1.existeMonomio(i));
		EXPECT_EQ(p1.getMonomio(i), mNullo);
	}
}

TEST(Polinomio, operator_equality)
{
	ed::Polinomio p1;
	ed::Polinomio p2 = ed::Polinomio(p1);
	
	EXPECT_EQ(p1, p2);
}

TEST(Polinomio, operator_asignation)
{
	ed::Polinomio p1;
	ed::Polinomio p2;
	ed::Polinomio p3;
	ed::Monomio mNullo(0, 0);
	ed::Monomio m1(1, 2);
	ed::Monomio m2 = 5;
	
	p1 = m1;
	
	EXPECT_EQ(p1.getGrado(), m1.getGrado());
	EXPECT_EQ(p1.getNumeroMonomios(), 1);
	EXPECT_FALSE(p1.esNulo());
	EXPECT_TRUE(p1.existeMonomio(m1.getGrado()));
	EXPECT_EQ(p1.getMonomio(m1.getGrado()), m1);
	
	p2 = 5;
	
	EXPECT_EQ(p2.getGrado(), m2.getGrado());
	EXPECT_EQ(p2.getNumeroMonomios(), 1);
	EXPECT_FALSE(p2.esNulo());
	EXPECT_TRUE(p2.existeMonomio(m2.getGrado()));
	EXPECT_EQ(p2.getMonomio(m2.getGrado()), m2);
	
	p3 = p2;
	
	EXPECT_EQ(p2, p3);
}


TEST(Polinomio, operator_plus_unary)
{
	ed::Polinomio p1;
	ed::Monomio m1(1, 2);
	
	p1 = m1;
	
	EXPECT_EQ(+(p1), p1);
	EXPECT_TRUE((+p1).existeMonomio(2));
	EXPECT_EQ((+p1).getMonomio(2), m1);
}

TEST(Polinomio, operator_minus_unary)
{
	ed::Polinomio p1;
	ed::Monomio m1(1, 2);
	ed::Monomio m2(-1, 2);

	p1 = m1;

	EXPECT_TRUE((-p1).existeMonomio(2));
	EXPECT_EQ((-p1).getMonomio(2), m2);
}


TEST(Polinomio, operator_plus_polinomio_polinomio)
{
	ed::Polinomio p1;
	ed::Polinomio p2;
	ed::Polinomio p3;
	ed::Polinomio p4;
	ed::Monomio m1(1, 2);
	ed::Monomio m2(1, 3);
	ed::Monomio m3(1, 2);
	ed::Monomio m4(2, 2);

	p1 = m1;
	p2 = m2;
	p3 = m3;

	p4 = p1 + p2 + p3;

	EXPECT_EQ(p4.getNumeroMonomios(), 2);
	EXPECT_FALSE(p4.existeMonomio(1));
	EXPECT_TRUE(p4.existeMonomio(2));
	EXPECT_TRUE(p4.existeMonomio(3));
	EXPECT_FALSE(p4.existeMonomio(4));
	EXPECT_EQ(p4.getMonomio(2), m4);
}

TEST(Polinomio, operator_plus_polinomio_monomio)
{
	ed::Polinomio p1;
	ed::Polinomio p2;
	ed::Polinomio p3;
	ed::Monomio m1(1, 2);
	ed::Monomio m2(1, 3);
	ed::Monomio m3(1, 2);
	ed::Monomio m4(2, 2);

	p1 = m1;

	p3 = p1 + m2 + m3;

	EXPECT_EQ(p3.getNumeroMonomios(), 2);
	EXPECT_FALSE(p3.existeMonomio(1));
	EXPECT_TRUE(p3.existeMonomio(2));
	EXPECT_TRUE(p3.existeMonomio(3));
	EXPECT_FALSE(p3.existeMonomio(4));
	EXPECT_EQ(p3.getMonomio(2), m4);
}

TEST(Polinomio, operator_plus_monomio_polinomio)
{
	ed::Polinomio p1;
	ed::Polinomio p2;
	ed::Monomio m1(1, 2);
	ed::Monomio m2(1, 3);
	ed::Monomio m3(1, 3);

	p1 = m1;

	p2 = m2 + p1;

	EXPECT_EQ(p2.getNumeroMonomios(), 2);
	EXPECT_FALSE(p2.existeMonomio(1));
	EXPECT_TRUE(p2.existeMonomio(2));
	EXPECT_TRUE(p2.existeMonomio(3));
	EXPECT_FALSE(p2.existeMonomio(4));
	EXPECT_EQ(p2.getMonomio(3), m3);

}

TEST(Polinomio, operator_plus_polinomio_real)
{
	ed::Polinomio p1;
	ed::Polinomio p2;
	ed::Monomio m1(1, 2);
	ed::Monomio m2(5, 0);
	ed::Monomio m3(5, 0);

	p1 = m1;

	p2 = p1 + 5;

	EXPECT_EQ(p2.getNumeroMonomios(), 2);
	EXPECT_TRUE(p2.existeMonomio(0));
	EXPECT_FALSE(p2.existeMonomio(1));
	EXPECT_TRUE(p2.existeMonomio(2));
	EXPECT_FALSE(p2.existeMonomio(3));
	EXPECT_EQ(p2.getMonomio(0), m3);
}

TEST(Polinomio, operator_plus_real_polinomio)
{
	ed::Polinomio p1;
	ed::Polinomio p2;
	ed::Monomio m1(1, 2);
	ed::Monomio m2(5, 0);
	ed::Monomio m3(5, 0);

	p1 = m1;

	p2 = 5 + p1;

	EXPECT_EQ(p2.getNumeroMonomios(), 2);
	EXPECT_TRUE(p2.existeMonomio(0));
	EXPECT_FALSE(p2.existeMonomio(1));
	EXPECT_TRUE(p2.existeMonomio(2));
	EXPECT_FALSE(p2.existeMonomio(3));
	EXPECT_EQ(p2.getMonomio(0), m3);
}








TEST(Polinomio, operator_minus_polinomio_polinomio)
{
	ed::Polinomio p1;
	ed::Polinomio p2;
	ed::Polinomio p3;
	ed::Polinomio p4;
	ed::Monomio m1(1, 2);
	ed::Monomio m2(1, 3);
	ed::Monomio m3(1, 2);
	ed::Monomio m4(1, 3);

	p1 = m1;
	p2 = m2;
	p3 = m3;

	p4 = p1 + p2 - p3;

	EXPECT_EQ(p4.getNumeroMonomios(), 1);
	EXPECT_FALSE(p4.existeMonomio(1));
	EXPECT_FALSE(p4.existeMonomio(2));
	EXPECT_TRUE(p4.existeMonomio(3));
	EXPECT_FALSE(p4.existeMonomio(4));
	EXPECT_EQ(p4.getMonomio(3), m2);
}


TEST(Polinomio, operator_minus_polinomio_monomio)
{
	ed::Polinomio p1;
	ed::Polinomio p2;
	ed::Polinomio p3;
	ed::Polinomio p4;
	ed::Monomio m1(1, 2);
	ed::Monomio m2(1, 3);
	ed::Monomio m3(1, 2);
	ed::Monomio m4(1, 3);

	p1 = m1;
	p2 = m2;
	p3 = m3;

	p4 = p1 + p2 - m3;

	EXPECT_EQ(p4.getNumeroMonomios(), 1);
	EXPECT_FALSE(p4.existeMonomio(1));
	EXPECT_FALSE(p4.existeMonomio(2));
	EXPECT_TRUE(p4.existeMonomio(3));
	EXPECT_FALSE(p4.existeMonomio(4));
	EXPECT_EQ(p4.getMonomio(3), m2);
}

TEST(Polinomio, operator_minus_monomio_polinomio)
{
	ed::Polinomio p1;
	ed::Polinomio p2;
	ed::Monomio m1(1, 2);
	ed::Monomio m2(1, 3);
	ed::Monomio m3(-1, 3);

	p1 = m1;

	p2 = m2 - p1;

	EXPECT_EQ(p2.getNumeroMonomios(), 2);
	EXPECT_FALSE(p2.existeMonomio(1));
	EXPECT_TRUE(p2.existeMonomio(2));
	EXPECT_TRUE(p2.existeMonomio(3));
	EXPECT_FALSE(p2.existeMonomio(4));
	EXPECT_EQ(p2.getMonomio(3), m3);
}


TEST(Polinomio, operator_minus_polinomio_real)
{
	ed::Polinomio p1;
	ed::Polinomio p2;
	ed::Monomio m1(1, 2);
	ed::Monomio m2(5, 0);
	ed::Monomio m3(-5, 0);

	p1 = m1;

	p2 = p1 - 5;

	EXPECT_EQ(p2.getNumeroMonomios(), 2);
	EXPECT_TRUE(p2.existeMonomio(0));
	EXPECT_FALSE(p2.existeMonomio(1));
	EXPECT_TRUE(p2.existeMonomio(2));
	EXPECT_FALSE(p2.existeMonomio(3));
	EXPECT_EQ(p2.getMonomio(0), m3);	
}

TEST(Polinomio, operator_minus_real_polinomio)
{
	ed::Polinomio p1;
	ed::Polinomio p2;
	ed::Monomio m1(1, 2);
	ed::Monomio m2(5, 0);
	ed::Monomio m3(5, 0);
	ed::Monomio m4(-1, 2);

	p1 = m1;

	p2 = 5 - p1;

	EXPECT_EQ(p2.getNumeroMonomios(), 2);
	EXPECT_TRUE(p2.existeMonomio(0));
	EXPECT_FALSE(p2.existeMonomio(1));
	EXPECT_TRUE(p2.existeMonomio(2));
	EXPECT_FALSE(p2.existeMonomio(3));
	EXPECT_EQ(p2.getMonomio(0), m3);
	EXPECT_EQ(p2.getMonomio(2), m4);
}












TEST(Polinomio, operator_multiplication_polinomio_polinomio)
{
	ed::Polinomio p1;
	ed::Polinomio p2;
	ed::Polinomio p3;
	ed::Polinomio paux1;
	ed::Polinomio paux2;
	ed::Monomio m1(1, 2);
	ed::Monomio m2(1, 3);
	ed::Monomio m3(1, 4);
	ed::Monomio m4(1, 5);

	paux1 = m1;
	paux2 = m2;
	p1 = paux1 + paux2;
	paux1 = m3;
	paux2 = m4;
	p2 = paux1 + paux2;
	
	EXPECT_EQ(p1.getNumeroMonomios(), 2);
	EXPECT_FALSE(p1.existeMonomio(1));
	EXPECT_TRUE(p1.existeMonomio(2));
	EXPECT_TRUE(p1.existeMonomio(3));
	EXPECT_FALSE(p1.existeMonomio(4));
	EXPECT_FALSE(p1.existeMonomio(5));
	
	EXPECT_EQ(p2.getNumeroMonomios(), 2);
	EXPECT_FALSE(p2.existeMonomio(1));
	EXPECT_FALSE(p2.existeMonomio(2));
	EXPECT_FALSE(p2.existeMonomio(3));
	EXPECT_TRUE(p2.existeMonomio(4));
	EXPECT_TRUE(p2.existeMonomio(5));

	p3 = p1 * p2;

	EXPECT_EQ(p3.getNumeroMonomios(), 3);
	EXPECT_FALSE(p3.existeMonomio(1));
	EXPECT_FALSE(p3.existeMonomio(2));
	EXPECT_FALSE(p3.existeMonomio(3));
	EXPECT_FALSE(p3.existeMonomio(4));
	EXPECT_FALSE(p3.existeMonomio(5));
	EXPECT_TRUE(p3.existeMonomio(6));
	EXPECT_TRUE(p3.existeMonomio(7));
	EXPECT_TRUE(p3.existeMonomio(8));
	EXPECT_FALSE(p3.existeMonomio(9));
	EXPECT_FALSE(p3.existeMonomio(10));
	
	EXPECT_EQ(p3.getMonomio(6), ed::Monomio(1,6));
	EXPECT_EQ(p3.getMonomio(7), ed::Monomio(2,7));
	EXPECT_EQ(p3.getMonomio(8), ed::Monomio(1,8));
}


TEST(Polinomio, operator_multiplication_polinomio_monomio)
{
	ed::Polinomio p1;
	ed::Polinomio p2;
	ed::Polinomio paux1;
	ed::Polinomio paux2;
	ed::Monomio m1(1, 2);
	ed::Monomio m2(1, 3);
	ed::Monomio m3(1, 4);

	paux1 = m1;
	paux2 = m2;
	p1 = paux1 + paux2;
		
	p2 = p1 * m3;

	EXPECT_EQ(p2.getNumeroMonomios(), 2);
	EXPECT_FALSE(p2.existeMonomio(1));
	EXPECT_FALSE(p2.existeMonomio(2));
	EXPECT_FALSE(p2.existeMonomio(3));
	EXPECT_FALSE(p2.existeMonomio(4));
	EXPECT_FALSE(p2.existeMonomio(5));
	EXPECT_TRUE(p2.existeMonomio(6));
	EXPECT_TRUE(p2.existeMonomio(7));
	EXPECT_FALSE(p2.existeMonomio(8));
	EXPECT_FALSE(p2.existeMonomio(9));
	EXPECT_FALSE(p2.existeMonomio(10));
	
	EXPECT_EQ(p2.getMonomio(6), ed::Monomio(1,6));
	EXPECT_EQ(p2.getMonomio(7), ed::Monomio(1,7));
}


TEST(Polinomio, operator_multiplication_monomio_polinomio)
{
	ed::Polinomio p1;
	ed::Polinomio p2;
	ed::Polinomio paux1;
	ed::Polinomio paux2;
	ed::Monomio m1(1, 2);
	ed::Monomio m2(1, 3);
	ed::Monomio m3(1, 4);

	paux1 = m1;
	paux2 = m2;
	p1 = paux1 + paux2;
		
	p2 = m3 * p1;

	EXPECT_EQ(p2.getNumeroMonomios(), 2);
	EXPECT_FALSE(p2.existeMonomio(1));
	EXPECT_FALSE(p2.existeMonomio(2));
	EXPECT_FALSE(p2.existeMonomio(3));
	EXPECT_FALSE(p2.existeMonomio(4));
	EXPECT_FALSE(p2.existeMonomio(5));
	EXPECT_TRUE(p2.existeMonomio(6));
	EXPECT_TRUE(p2.existeMonomio(7));
	EXPECT_FALSE(p2.existeMonomio(8));
	EXPECT_FALSE(p2.existeMonomio(9));
	EXPECT_FALSE(p2.existeMonomio(10));
	
	EXPECT_EQ(p2.getMonomio(6), ed::Monomio(1,6));
	EXPECT_EQ(p2.getMonomio(7), ed::Monomio(1,7));
}



TEST(Polinomio, operator_multiplication_polinomio_real)
{
	ed::Polinomio p1;
	ed::Polinomio p2;
	ed::Polinomio paux1;
	ed::Polinomio paux2;
	ed::Monomio m1(1, 2);
	ed::Monomio m2(1, 3);
	ed::Monomio m3(1, 4);

	paux1 = m1;
	paux2 = m2;
	p1 = paux1 + paux2;
		
	p2 = p1 * 5;

	EXPECT_EQ(p2.getNumeroMonomios(), 2);
	EXPECT_FALSE(p2.existeMonomio(1));
	EXPECT_TRUE(p2.existeMonomio(2));
	EXPECT_TRUE(p2.existeMonomio(3));
	EXPECT_FALSE(p2.existeMonomio(4));
	EXPECT_FALSE(p2.existeMonomio(5));
	EXPECT_FALSE(p2.existeMonomio(6));
	EXPECT_FALSE(p2.existeMonomio(7));
	EXPECT_FALSE(p2.existeMonomio(8));
	EXPECT_FALSE(p2.existeMonomio(9));
	EXPECT_FALSE(p2.existeMonomio(10));
	
	EXPECT_EQ(p2.getMonomio(2), ed::Monomio(5,2));
	EXPECT_EQ(p2.getMonomio(3), ed::Monomio(5,3));
}


TEST(Polinomio, operator_multiplication_real_polinomio)
{
	ed::Polinomio p1;
	ed::Polinomio p2;
	ed::Polinomio paux1;
	ed::Polinomio paux2;
	ed::Monomio m1(1, 2);
	ed::Monomio m2(1, 3);
	ed::Monomio m3(1, 4);

	paux1 = m1;
	paux2 = m2;
	p1 = paux1 + paux2;
		
	p2 = 5 * p1;

	EXPECT_EQ(p2.getNumeroMonomios(), 2);
	EXPECT_FALSE(p2.existeMonomio(1));
	EXPECT_TRUE(p2.existeMonomio(2));
	EXPECT_TRUE(p2.existeMonomio(3));
	EXPECT_FALSE(p2.existeMonomio(4));
	EXPECT_FALSE(p2.existeMonomio(5));
	EXPECT_FALSE(p2.existeMonomio(6));
	EXPECT_FALSE(p2.existeMonomio(7));
	EXPECT_FALSE(p2.existeMonomio(8));
	EXPECT_FALSE(p2.existeMonomio(9));
	EXPECT_FALSE(p2.existeMonomio(10));
	
	EXPECT_EQ(p2.getMonomio(2), ed::Monomio(5,2));
	EXPECT_EQ(p2.getMonomio(3), ed::Monomio(5,3));
}






// TEST(Polinomio, operator_division_polinomio_polinomio)
// {
// 	ed::Polinomio p1;
// 	ed::Polinomio p2;
// 	ed::Polinomio p3;
// 	ed::Polinomio paux1;
// 	ed::Polinomio paux2;
// 	ed::Monomio m1(1, 2);
// 	ed::Monomio m2(1, 3);
// 	ed::Monomio m3(1, 4);
// 	ed::Monomio m4(1, 5);
// 
// 	paux1 = m1;
// 	paux2 = m2;
// 	p1 = paux1 + paux2;
// 	paux1 = m3;
// 	paux2 = m4;
// 	p2 = paux1 + paux2;
// 
// 
// 	p3 = p2 / p1;
// 
// 	EXPECT_EQ(p3.getNumeroMonomios(), 1);
// 	EXPECT_TRUE(p3.existeMonomio(2));
// 	EXPECT_EQ(p3.getMonomio(2), ed::Monomio(1,2));
// 
// 	p3 = p1 / p2;
// 
// 	EXPECT_EQ(p3.getNumeroMonomios(), 0);
// }































    //////////////////////////////////
  // complex asignation operators //
//////////////////////////////////


TEST(Polinomio, operator_asignation_plus_polinomio)
{
	ed::Polinomio p1;
	ed::Polinomio p2;
	ed::Monomio m1(1, 2);
	ed::Monomio m2(2, 3);

	p1 = m1;
	p2 = m2;
	p1 += p2;
	
	
	EXPECT_EQ(p1.getNumeroMonomios(), 2);
	EXPECT_FALSE(p1.existeMonomio(1));
	EXPECT_TRUE(p1.existeMonomio(2));
	EXPECT_TRUE(p1.existeMonomio(3));
	EXPECT_FALSE(p1.existeMonomio(4));
	
	EXPECT_EQ(p1.getMonomio(2), ed::Monomio(1,2));
	EXPECT_EQ(p1.getMonomio(3), ed::Monomio(2,3));
}


TEST(Polinomio, operator_asignation_plus_monomio)
{
	ed::Polinomio p1;
	ed::Monomio m1(1, 2);
	ed::Monomio m2(2, 3);

	p1 = m1;
	p1 += m2;
	
	
	EXPECT_EQ(p1.getNumeroMonomios(), 2);
	EXPECT_FALSE(p1.existeMonomio(1));
	EXPECT_TRUE(p1.existeMonomio(2));
	EXPECT_TRUE(p1.existeMonomio(3));
	EXPECT_FALSE(p1.existeMonomio(4));
	
	EXPECT_EQ(p1.getMonomio(2), ed::Monomio(1,2));
	EXPECT_EQ(p1.getMonomio(3), ed::Monomio(2,3));
}


TEST(Polinomio, operator_asignation_plus_float)
{
	ed::Polinomio p1;
	ed::Polinomio p2;
	ed::Monomio m1(1, 2);

	p1 = m1;
	p1 += 4;
	
	
	EXPECT_EQ(p1.getNumeroMonomios(), 2);
	EXPECT_TRUE(p1.existeMonomio(0));
	EXPECT_FALSE(p1.existeMonomio(1));
	EXPECT_TRUE(p1.existeMonomio(2));
	EXPECT_FALSE(p1.existeMonomio(3));
	EXPECT_FALSE(p1.existeMonomio(4));
	
	EXPECT_EQ(p1.getMonomio(0), ed::Monomio(4,0));
	EXPECT_EQ(p1.getMonomio(2), ed::Monomio(1,2));
}


TEST(Polinomio, operator_asignation_minus_polinomio)
{
	ed::Polinomio p1;
	ed::Polinomio p2;
	ed::Monomio m1(1, 2);
	ed::Monomio m2(2, 3);

	p1 = m1;
	p2 = m2;
	p1 -= p2;
	
	
	EXPECT_EQ(p1.getNumeroMonomios(), 2);
	EXPECT_FALSE(p1.existeMonomio(1));
	EXPECT_TRUE(p1.existeMonomio(2));
	EXPECT_TRUE(p1.existeMonomio(3));
	EXPECT_FALSE(p1.existeMonomio(4));
	
	EXPECT_EQ(p1.getMonomio(2), ed::Monomio(1,2));
	EXPECT_EQ(p1.getMonomio(3), ed::Monomio(-2,3));
}


TEST(Polinomio, operator_asignation_minus_monomio)
{
	ed::Polinomio p1;
	ed::Monomio m1(1, 2);
	ed::Monomio m2(2, 3);

	p1 = m1;
	p1 -= m2;
	
	
	EXPECT_EQ(p1.getNumeroMonomios(), 2);
	EXPECT_FALSE(p1.existeMonomio(1));
	EXPECT_TRUE(p1.existeMonomio(2));
	EXPECT_TRUE(p1.existeMonomio(3));
	EXPECT_FALSE(p1.existeMonomio(4));
	
	EXPECT_EQ(p1.getMonomio(2), ed::Monomio(1,2));
	EXPECT_EQ(p1.getMonomio(3), ed::Monomio(-2,3));
}


TEST(Polinomio, operator_asignation_minus_float)
{
	ed::Polinomio p1;
	ed::Polinomio p2;
	ed::Monomio m1(1, 2);

	p1 = m1;
	p1 -= 4;
	
	
	EXPECT_EQ(p1.getNumeroMonomios(), 2);
	EXPECT_TRUE(p1.existeMonomio(0));
	EXPECT_FALSE(p1.existeMonomio(1));
	EXPECT_TRUE(p1.existeMonomio(2));
	EXPECT_FALSE(p1.existeMonomio(3));
	EXPECT_FALSE(p1.existeMonomio(4));
	
	EXPECT_EQ(p1.getMonomio(0), ed::Monomio(-4,0));
	EXPECT_EQ(p1.getMonomio(2), ed::Monomio(1,2));
}






TEST(Polinomio, operator_asignation_multiplication_polinomio)
{
	ed::Polinomio p1;
	ed::Polinomio p2;
	ed::Polinomio p3;
	ed::Polinomio paux1;
	ed::Polinomio paux2;
	ed::Monomio m1(1, 2);
	ed::Monomio m2(1, 3);
	ed::Monomio m3(1, 4);
	ed::Monomio m4(1, 5);

	paux1 = m1;
	paux2 = m2;
	p1 = paux1 + paux2;
	paux1 = m3;
	paux2 = m4;
	p2 = paux1 + paux2;
	
	EXPECT_EQ(p1.getNumeroMonomios(), 2);
	EXPECT_FALSE(p1.existeMonomio(1));
	EXPECT_TRUE(p1.existeMonomio(2));
	EXPECT_TRUE(p1.existeMonomio(3));
	EXPECT_FALSE(p1.existeMonomio(4));
	EXPECT_FALSE(p1.existeMonomio(5));
	
	EXPECT_EQ(p2.getNumeroMonomios(), 2);
	EXPECT_FALSE(p2.existeMonomio(1));
	EXPECT_FALSE(p2.existeMonomio(2));
	EXPECT_FALSE(p2.existeMonomio(3));
	EXPECT_TRUE(p2.existeMonomio(4));
	EXPECT_TRUE(p2.existeMonomio(5));

	p1 *= p2;

	EXPECT_EQ(p1.getNumeroMonomios(), 3);
	EXPECT_FALSE(p1.existeMonomio(1));
	EXPECT_FALSE(p1.existeMonomio(2));
	EXPECT_FALSE(p1.existeMonomio(3));
	EXPECT_FALSE(p1.existeMonomio(4));
	EXPECT_FALSE(p1.existeMonomio(5));
	EXPECT_TRUE(p1.existeMonomio(6));
	EXPECT_TRUE(p1.existeMonomio(7));
	EXPECT_TRUE(p1.existeMonomio(8));
	EXPECT_FALSE(p1.existeMonomio(9));
	EXPECT_FALSE(p1.existeMonomio(10));
	
	EXPECT_EQ(p1.getMonomio(6), ed::Monomio(1,6));
	EXPECT_EQ(p1.getMonomio(7), ed::Monomio(2,7));
	EXPECT_EQ(p1.getMonomio(8), ed::Monomio(1,8));
}


TEST(Polinomio, operator_asignation_multiplication_monomio)
{
	ed::Polinomio p1;
	ed::Polinomio p2;
	ed::Polinomio paux1;
	ed::Polinomio paux2;
	ed::Monomio m1(1, 2);
	ed::Monomio m2(1, 3);
	ed::Monomio m3(1, 4);

	paux1 = m1;
	paux2 = m2;
	p1 = paux1 + paux2;
		
	p1 *= m3;

	EXPECT_EQ(p1.getNumeroMonomios(), 2);
	EXPECT_FALSE(p1.existeMonomio(1));
	EXPECT_FALSE(p1.existeMonomio(2));
	EXPECT_FALSE(p1.existeMonomio(3));
	EXPECT_FALSE(p1.existeMonomio(4));
	EXPECT_FALSE(p1.existeMonomio(5));
	EXPECT_TRUE(p1.existeMonomio(6));
	EXPECT_TRUE(p1.existeMonomio(7));
	EXPECT_FALSE(p1.existeMonomio(8));
	EXPECT_FALSE(p1.existeMonomio(9));
	EXPECT_FALSE(p1.existeMonomio(10));
	
	EXPECT_EQ(p1.getMonomio(6), ed::Monomio(1,6));
	EXPECT_EQ(p1.getMonomio(7), ed::Monomio(1,7));
}


TEST(Polinomio, operator_asignation_multiplication_real)
{
	ed::Polinomio p1;
	ed::Polinomio p2;
	ed::Polinomio paux1;
	ed::Polinomio paux2;
	ed::Monomio m1(1, 2);
	ed::Monomio m2(1, 3);
	ed::Monomio m3(1, 4);

	paux1 = m1;
	paux2 = m2;
	p1 = paux1 + paux2;
		
	p1 *= 5;

	EXPECT_EQ(p1.getNumeroMonomios(), 2);
	EXPECT_FALSE(p1.existeMonomio(1));
	EXPECT_TRUE(p1.existeMonomio(2));
	EXPECT_TRUE(p1.existeMonomio(3));
	EXPECT_FALSE(p1.existeMonomio(4));
	EXPECT_FALSE(p1.existeMonomio(5));
	EXPECT_FALSE(p1.existeMonomio(6));
	EXPECT_FALSE(p1.existeMonomio(7));
	EXPECT_FALSE(p1.existeMonomio(8));
	EXPECT_FALSE(p1.existeMonomio(9));
	EXPECT_FALSE(p1.existeMonomio(10));
	
	EXPECT_EQ(p1.getMonomio(2), ed::Monomio(5,2));
	EXPECT_EQ(p1.getMonomio(3), ed::Monomio(5,3));
}