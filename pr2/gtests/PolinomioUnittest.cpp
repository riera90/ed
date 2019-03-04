/*!
	\file MonomioUnittest.cpp
	\brief test de unidad de las funciones y operaciones internas y externas de la clase Monimio
*/


#include "gtest/gtest.h"
#include "Polinomio.hpp"
#include "operadoresExternosPolinomios.hpp"
#include <iostream>

#define FLOAT_PRESICION 0.0003

    /////////////////
  // Constructor //
/////////////////

TEST(Polinomio, default_constructor)
{
	EXPECT_EQ(1,1);
}