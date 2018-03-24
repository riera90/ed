#include "gtest/gtest.h"
#include "paths.hpp"

#include "Provincia.hpp"

TEST(Provincia, constructor){
	Provincia a;
	EXPECT_EQ(0,a.n_municipios());
}

TEST(Provincia, seters_and_geters){
	Provincia a;
	a.set_code(1);
	a.set_name("Córdoba");
	EXPECT_EQ(1,a.get_code());
	EXPECT_EQ("Córdoba",a.get_name());
}

#include "Provincia_controler.hpp"


TEST(Provincia_controler, constructor){
	Provincia_controler a;
	EXPECT_EQ(0,a.n_municipios());
}

TEST(Provincia_controler, seters_and_geters){
	Provincia_controler a;
	a.set_code(1);
	a.set_name("Córdoba");
	EXPECT_EQ(1,a.get_code());
	EXPECT_EQ("Córdoba",a.get_name());
}

TEST(Provincia_controler,load_data_and_short){
	Provincia_controler a;
	Municipio municipio;
	Municipio municipio_head;
	a.load_data(csv_file_path);

	a.got_head();
	municipio_head=a.get_municipio();
	mans=0
	womens=0
	EXPECT_EQ(00000,municipio_head.get_postal_code());
	EXPECT_EQ("ndef",municipio_head.get_name());
	EXPECT_EQ(mans,municipio_head.get_mans());
	EXPECT_EQ(womens,municipio_head.get_womens());
	EXPECT_EQ(mans+womens,municipio_head.get_habitants());

	// a.goto_next();
	// municipio=a.get_municipio();
	// mans=0
	// womens=0
	// EXPECT_EQ(00000,municipio.get_postal_code());
	// EXPECT_EQ("ndef",municipio.get_name());
	// EXPECT_EQ(mans,municipio.get_mans());
	// EXPECT_EQ(womens,municipio.get_womens());
	// EXPECT_EQ(mans+womens,municipio.get_habitants());
	//
	// a.goto_previous();
	// municipio=a.get_municipio();
	// mans=0
	// womens=0
	// EXPECT_EQ(municipio_head.get_postal_code(),municipio.get_postal_code());
	// EXPECT_EQ(municipio_head.get_name(),municipio.get_name());
	// EXPECT_EQ(municipio_head.get_mans(),municipio.get_mans());
	// EXPECT_EQ(municipio_head.get_womens(),municipio.get_womens());
	// EXPECT_EQ(municipio_head.get_habitants(),municipio.get_habitants());
	//
	// a.goto_last();
	// municipio=a.get_municipio();
	// mans=0
	// womens=0
	// EXPECT_EQ(00000,municipio.get_postal_code());
	// EXPECT_EQ("ndef",municipio.get_name());
	// EXPECT_EQ(mans,municipio.get_mans());
	// EXPECT_EQ(womens,municipio.get_womens());
	// EXPECT_EQ(mans+womens,municipio.get_habitants());
	//
	// a.goto_next();
	// municipio=a.get_municipio();
	// mans=0
	// womens=0
	// EXPECT_EQ(municipio_head.get_postal_code(),municipio.get_postal_code());
	// EXPECT_EQ(municipio_head.get_name(),municipio.get_name());
	// EXPECT_EQ(municipio_head.get_mans(),municipio.get_mans());
	// EXPECT_EQ(municipio_head.get_womens(),municipio.get_womens());
	// EXPECT_EQ(municipio_head.get_habitants(),municipio.get_habitants());
}
