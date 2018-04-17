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
