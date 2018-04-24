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

TEST(Medicion,seters_and_getters_extensive){
	ed::Medicion a;
	a.setFecha(ed::Fecha(3,2,3));
	a.setPrecipitacion(0.5);
	a.setTemperaturaMaxima(0.3);
	a.setHoraTemperaturaMaxima("maxima");
	a.setTemperaturaMinima(0.1);
	a.setHoraTemperaturaMinima("minima");
	a.setTemperaturaMedia(0.2);
	a.setHumedaddRelativaMaxima(1);
	a.setHumedaddRelativaMinima(0);
	a.setHumedadRelativaMedia(0.5);
	a.setVelocidadVientoMedia(30);
	a.setDireccionVientoMedia(40);
	a.setRadiacionSolar(2);
	a.setEto(10);
	EXPECT_EQ("3-2-3",a.getFecha().getFechaString());
	EXPECT_EQ("maxima",a.getHoraTemperaturaMaxima());
	EXPECT_EQ("minima",a.getHoraTemperaturaMinima());
	EXPECT_NEAR(0.5	,a.getPrecipitacion()					,0.000001);
	EXPECT_NEAR(0.3	,a.getTemperaturaMaxima()			,0.000001);
	EXPECT_NEAR(0.1	,a.getTemperaturaMinima()			,0.000001);
	EXPECT_NEAR(0.2	,a.getTemperaturaMedia()			,0.000001);
	EXPECT_NEAR(1		,a.getHumedaddRelativaMaxima()	,0.000001);
	EXPECT_NEAR(0		,a.getHumedaddRelativaMinima()	,0.000001);
	EXPECT_NEAR(0.5	,a.getHumedadRelativaMedia()		,0.000001);
	EXPECT_NEAR(30	,a.getVelocidadVientoMedia()	,0.000001);
	EXPECT_NEAR(40	,a.getDireccionVientoMedia()	,0.000001);
	EXPECT_NEAR(2		,a.getRadiacionSolar()				,0.000001);
	EXPECT_NEAR(10	,a.getEto()										,0.000001);
}

TEST(Medicion,builder_extensive){
	ed::Medicion a;
	EXPECT_EQ("1-1-1",a.getFecha().getFechaString());
	EXPECT_EQ("nval",a.getHoraTemperaturaMaxima());
	EXPECT_EQ("nval",a.getHoraTemperaturaMinima());
	EXPECT_NEAR(0	,a.getPrecipitacion()					,0.000001);
	EXPECT_NEAR(0	,a.getTemperaturaMaxima()			,0.000001);
	EXPECT_NEAR(0	,a.getTemperaturaMinima()			,0.000001);
	EXPECT_NEAR(0	,a.getTemperaturaMedia()			,0.000001);
	EXPECT_NEAR(0	,a.getHumedaddRelativaMaxima()	,0.000001);
	EXPECT_NEAR(0	,a.getHumedaddRelativaMinima()	,0.000001);
	EXPECT_NEAR(0	,a.getHumedadRelativaMedia()		,0.000001);
	EXPECT_NEAR(0	,a.getVelocidadVientoMedia()	,0.000001);
	EXPECT_NEAR(0	,a.getDireccionVientoMedia()	,0.000001);
	EXPECT_NEAR(0	,a.getRadiacionSolar()				,0.000001);
	EXPECT_NEAR(0	,a.getEto()										,0.000001);
}
