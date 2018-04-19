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

TEST(Fecha,fechaCompare){
	ed::Fecha a(1,1,1);
	ed::Fecha b(1,1,1);
	ed::Fecha c(2,1,1);
	ed::Fecha d(1,2,1);
	ed::Fecha e(1,1,2);
	EXPECT_EQ(a.fechaCompare(b),0);
	EXPECT_EQ(a.fechaCompare(c),-1);
	EXPECT_EQ(a.fechaCompare(d),-1);
	EXPECT_EQ(a.fechaCompare(e),-1);

	EXPECT_EQ(e.fechaCompare(e),0);
	EXPECT_EQ(a.fechaCompare(a),0);
	EXPECT_EQ(e.fechaCompare(a),1);
	EXPECT_EQ(e.fechaCompare(c),1);
	EXPECT_EQ(e.fechaCompare(d),1);
}
