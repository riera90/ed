#include "gtest/gtest.h"
#include "Medicion.hpp"

TEST(Medicion,builder){
	ed::Medicion a;
	EXPECT_EQ("1-1-1",a.getFecha().getFechaString());
	EXPECT_NEAR(0,a.getPrecipitacion(),0.000001);
}

TEST(Medicion,parametrized_builder){
	ed::Fecha f(1,2,3);
	ed::Medicion a(f,0.005);
	EXPECT_EQ("1-2-3",a.getFecha().getFechaString());
	EXPECT_NEAR(0.005,a.getPrecipitacion(),0.000001);
}

TEST(Medicion,copy_builder){
	ed::Fecha f(1,2,3);
	ed::Medicion a(f,0.005);
	ed::Medicion b(a);
	EXPECT_EQ("1-2-3",a.getFecha().getFechaString());
	EXPECT_EQ("1-2-3",b.getFecha().getFechaString());
	EXPECT_NEAR(0.005,a.getPrecipitacion(),0.000001);
	EXPECT_NEAR(0.005,b.getPrecipitacion(),0.000001);
}

TEST(Medicion,operators){
	ed::Fecha f(1,2,3);
	ed::Medicion a(f,0.005);
	ed::Medicion b(a);
	ed::Medicion c(f,0.001);
	ed::Medicion d;
	d=a;
	EXPECT_TRUE(a==b);
	EXPECT_FALSE(a==c);
	EXPECT_TRUE(a==d);
}

TEST(Medicion,seters){
	ed::Medicion a;
	a.setFecha(ed::Fecha(3,2,3));
	a.setPrecipitacion(0.5);
	EXPECT_EQ("3-2-3",a.getFecha().getFechaString());
	EXPECT_NEAR(0.5,a.getPrecipitacion(),0.000001);
}
