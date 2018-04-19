#include "gtest/gtest.h"
#include "MonticuloMediciones.hpp"


TEST(Medicion,builder){
	ed::MonticuloMediciones h;
	EXPECT_TRUE(h.isEmpty());
}

TEST(Medicion,is_empty){
	ed::MonticuloMediciones h;
	EXPECT_TRUE(h.isEmpty());
	ed::Medicion m(ed::Fecha(1,2,3),0.005);
	h.insert(m);
	EXPECT_FALSE(h.isEmpty());
}

TEST(Medicion,ordered_insert){
	ed::MonticuloMediciones h;
	ed::Medicion a(ed::Fecha(1,1,1),0.0);
	ed::Medicion b(ed::Fecha(2,1,1),0.0);
	ed::Medicion c(ed::Fecha(3,1,1),0.0);
	ed::Medicion d(ed::Fecha(4,1,1),0.0);
	ed::Medicion e(ed::Fecha(5,1,1),0.0);
	h.insert(a);
	h.insert(b);
	h.insert(c);
	h.insert(d);
	h.insert(e);
	EXPECT_TRUE(a.equal(h.getElement(0)));
	EXPECT_TRUE(b.equal(h.getElement(1)));
	EXPECT_TRUE(c.equal(h.getElement(2)));
	EXPECT_TRUE(d.equal(h.getElement(3)));
	EXPECT_TRUE(e.equal(h.getElement(4)));
}


TEST(Medicion,disordered_insert){
	ed::MonticuloMediciones h;
	ed::Medicion a(ed::Fecha(1,1,1),0.0);
	ed::Medicion b(ed::Fecha(2,1,1),0.0);
	ed::Medicion c(ed::Fecha(3,1,1),0.0);
	ed::Medicion d(ed::Fecha(4,1,1),0.0);
	ed::Medicion e(ed::Fecha(5,1,1),0.0);
	h.insert(e);
	h.insert(d);
	h.insert(b);
	h.insert(c);
	h.insert(a);
	EXPECT_TRUE(a.equal(h.getElement(0)));
	EXPECT_TRUE(b.equal(h.getElement(1)));
	EXPECT_TRUE(c.equal(h.getElement(4)));
	EXPECT_TRUE(d.equal(h.getElement(2)));
	EXPECT_TRUE(e.equal(h.getElement(3)));
}
