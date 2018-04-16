#include "gtest/gtest.h"
#include "Fecha.hpp"

TEST(Fecha,builder){
	ed::Fecha a;
	EXPECT_EQ(a.getDia(),1);
	EXPECT_EQ(a.getMes(),1);
	EXPECT_EQ(a.getAgno(),1);
	EXPECT_EQ(a.getFechaString(),"1-1-1");
}

TEST(Fecha,builder_with_parapeters){
	ed::Fecha a(2,3,41);
	EXPECT_EQ(a.getDia(),2);
	EXPECT_EQ(a.getMes(),3);
	EXPECT_EQ(a.getAgno(),41);
	EXPECT_EQ(a.getFechaString(),"2-3-41");
}

TEST(Fecha,seters_and_geters){
	ed::Fecha a;
	a.setDia(2);
	a.setMes(3);
	a.setAgno(41);
	EXPECT_EQ(a.getDia(),2);
	EXPECT_EQ(a.getMes(),3);
	EXPECT_EQ(a.getAgno(),41);
	EXPECT_EQ(a.getFechaString(),"2-3-41");
}
