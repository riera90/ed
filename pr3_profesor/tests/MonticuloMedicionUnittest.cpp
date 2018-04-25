#include "gtest/gtest.h"
#include "MonticuloMediciones.hpp"


void print(ed::MonticuloMediciones h){
	for (size_t i = 0; i < h.size(); i++) {
		std::cout <<i<<"->";
		h.getElement(i).escribirMedicion();
	}
}

TEST(MonticuloMediciones,builder){
	ed::MonticuloMediciones h;
	EXPECT_TRUE(h.isEmpty());
}

TEST(MonticuloMediciones,is_empty){
	ed::MonticuloMediciones h;
	EXPECT_TRUE(h.isEmpty());
	ed::Medicion m(ed::Fecha(1,2,3),0.005);
	h.insert(m);
	EXPECT_FALSE(h.isEmpty());
}

TEST(MonticuloMediciones,ordered_insert){
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
	EXPECT_TRUE(a.equal(h.getElement(3)));
	EXPECT_TRUE(b.equal(h.getElement(2)));
	EXPECT_TRUE(c.equal(h.getElement(4)));
	EXPECT_TRUE(d.equal(h.getElement(1)));
	EXPECT_TRUE(e.equal(h.getElement(0)));
}


TEST(MonticuloMediciones,shift_up_and_disordered_insert){
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
	EXPECT_TRUE(a.equal(h.getElement(4)));
	EXPECT_TRUE(b.equal(h.getElement(2)));
	EXPECT_TRUE(c.equal(h.getElement(3)));
	EXPECT_TRUE(d.equal(h.getElement(1)));
	EXPECT_TRUE(e.equal(h.getElement(0)));
}


TEST(MonticuloMediciones,remove_and_shift_down){
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
	h.remove();
	EXPECT_TRUE(a.equal(h.getElement(3)));
	EXPECT_TRUE(b.equal(h.getElement(2)));
	EXPECT_TRUE(d.equal(h.getElement(0)));
	EXPECT_TRUE(c.equal(h.getElement(1)));
}
