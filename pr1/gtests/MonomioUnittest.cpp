#include "gtest/gtest.h"
#include "Monomio.hpp"


TEST(Monomio, default_constructor)
{
	m = ed::Monomio();
	EXPECT_NEAR(m.getCoeficiente(), 0.0);
	EXPECT_EQ(m.getGrado(), 0);
}


TEST(Monomio, constructor)
{
	m = ed::Monomio(1.2, 3);
	EXPECT_NEAR(m.getCoeficiente(), 1.2);
	EXPECT_EQ(m.getGrado(), 3);
}

TEST(Monomio, faulty_constructor)
{
	m = ed::Monomio(-1.2, -3);
	EXPECT_NEAR(m.getCoeficiente(), -1.2);
	EXPECT_NEQ(m.getGrado(), 3);
	EXPECT_EQ(m.getGrado(), 0);
}

TEST(Monomio, copy_constructor)
{
	m1 = ed::Monomio(1.2, 3);
	m2 = ed::Monomio(m1);
	EXPECT_NEAR(m2.getCoeficiente(), m1.getCoeficiente());
	EXPECT_EQ(m2.getGrado(), m1.getGrado());
}

TEST(Monomio, faulty_constructor)
{
	m = ed::Monomio(-1.2, -3);
	EXPECT_NEAR(m.getCoeficiente(), -1.2);
	EXPECT_NEQ(m.getGrado(), -3);
	EXPECT_EQ(m.getGrado(), 0);
}

TEST(Monomio, getters_and_setters)
{
	m = ed::Monomio();
	EXPECT_TRUE(m.setCoeficiente(1.2));
	EXPECT_TRUE(m.setGrado(3));
	EXPECT_NEAR(m.getCoeficiente(), 1.2);
	EXPECT_EQ(m.getGrado(), 3);
}


TEST(Monomio, faulty_getters_and_setters)
{
	m = ed::Monomio();
	EXPECT_TRUE(m.setCoeficiente(-1.2));
	EXPECT_FALSE(m.setGrado(-3));
	EXPECT_NEAR(m.getCoeficiente(), -1.2);
	EXPECT_EQ(m.getGrado(), 0);
}

TEST(Monomio, operator_equality)
{
	m1 = ed::Monomio(1, 2);
	m2 = ed::Monomio(1, 2);
	m3 = ed::Monomio(2, 1);
	EXPECT_TRUE(m1 == m2);
	EXPECT_FALSE(m1 == m3);
	EXPECT_EQ(m1, m2); // redundant but I like to test it
	EXPECT_NEQ(m1, m3);
}

TEST(Monomio, operator_assignation)
{
	m1 = ed::Monomio(1, 2);
	m2 = ed::Monomio(3, 4);
	EXPECT_EQ(m2, (m1 = m2));
	EXPECT_EQ(m1, m2);

	m3 = ed::Monomio(5, 0);
	EXPECT_EQ(m3, (m1 = 5));
}

TEST(Monomio, operator_plus_unary)
{
	m1 = ed::Monomio(1, 2);
	m2 = ed::Monomio(1, 2);
	EXPECT_EQ(m1, +m2)
}

TEST(Monomio, operator_plus_unary)
{
	m1 = ed::Monomio(1, 2);
	m2 = ed::Monomio(-1, 2);
	EXPECT_EQ(m1, -m2)
}

TEST(Monomio, operator_plus)
{
	m1 = ed::Monomio(3, 2);
	m2 = ed::Monomio(1, 2);
	m3 = ed::monomio(4, 2);
	EXPECT_EQ(m3, (m1 + m2));
}

TEST(Monomio, operator_minus)
{
	m1 = ed::Monomio(3, 2);
	m2 = ed::Monomio(1, 2);
	m3 = ed::monomio(2, 2);
	EXPECT_EQ(m3, (m1 - m2));
}

TEST(Monomio, operator_multiply)
{
	m1 = ed::Monomio(5, 2);
	m2 = ed::Monomio(5, 3);
	m3 = ed::monomio(25, 5);
	EXPECT_EQ(m3, (m1 * m2));

	m4 = ed::monomio(25, 2);
	EXPECT_EQ(m4, (5 * m1));
	// EXPECT_EQ(m4, (m1 * 5)); // it would be nice to implement
}

TEST(Monomio, operator_division)
{
	m1 = ed::Monomio(10, 3);
	m2 = ed::Monomio(5, 2);
	m3 = ed::monomio(1, 1);
	EXPECT_EQ(m3, (m1 / m2));

	m4 = ed::monomio(2, 3);
	EXPECT_EQ(m4, (m1 / 5));

	m5 = ed::monomio(0.5, 0);
	EXPECT_EQ(m5, (5 / m1));
}

TEST(Monomio, operator_plus_equal)
{
	m1 = ed::Monomio(10, 3);
	m2 = ed::Monomio(5, 3);
	m3 = ed::monomio(15, 3);
	EXPECT_EQ(m3, (m1 += m2));
}

TEST(Monomio, operator_minus_equal)
{
	m1 = ed::Monomio(10, 3);
	m2 = ed::Monomio(5, 3);
	m3 = ed::monomio(5, 3);
	EXPECT_EQ(m3, (m1 -= m2));
}

TEST(Monomio, operator_multiply_equal)
{
	m1 = ed::Monomio(10, 3);
	m2 = ed::Monomio(5, 3);
	m3 = ed::monomio(50, 6);
	EXPECT_EQ(m3, (m1 *= m2));

	m4 = ed::monomio(50, 3);
	EXPECT_EQ(m4, (m1 *= 5));
}

TEST(Monomio, operator_division_equal)
{
	m1 = ed::Monomio(10, 3);
	m2 = ed::Monomio(5, 3);
	m3 = ed::monomio(5, 6);
	EXPECT_EQ(m3, (m1 /= m2));

	m4 = ed::monomio(5, 3);
	EXPECT_EQ(m4, (m1 /= 2));
}

TEST(Monomio, calcularValor)
{
	m = ed::Monomio(2, 3);
	EXPECT_NEAR(m.calcularValor(5), 250);
}
