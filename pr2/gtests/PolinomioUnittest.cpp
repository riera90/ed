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

TEST(Polinomio, operator_plus)
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

TEST(Polinomio, operator_minus)
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