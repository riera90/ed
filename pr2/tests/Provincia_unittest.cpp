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

#include "Provincia_handler.hpp"


TEST(Provincia_handler,load_data_data_addition_and_cursor_movenent){
	Provincia_handler a;
	Municipio municipio;
	Municipio municipio_head;
	a.load_data(csv_file_path);

	a.goto_head();
	municipio_head=a.get_municipio();
	int mens=2173;
	int womens=2063;
	EXPECT_EQ(14001,municipio_head.get_postal_code());
	EXPECT_EQ("Adamuz",municipio_head.get_name());
	EXPECT_EQ(mens,municipio_head.get_mens());
	EXPECT_EQ(womens,municipio_head.get_womens());
	EXPECT_EQ(mens+womens,municipio_head.get_habitants());

	a.goto_next();
	municipio=a.get_municipio();
	mens=6784;
	womens=6692;
	EXPECT_EQ(14002,municipio.get_postal_code());
	EXPECT_EQ("Aguilar de la Frontera",municipio.get_name());
	EXPECT_EQ(mens,municipio.get_mens());
	EXPECT_EQ(womens,municipio.get_womens());
	EXPECT_EQ(mens+womens,municipio.get_habitants());

	a.goto_previous();
	municipio=a.get_municipio();
	EXPECT_EQ(municipio_head.get_postal_code(),municipio.get_postal_code());
	EXPECT_EQ(municipio_head.get_name(),municipio.get_name());
	EXPECT_EQ(municipio_head.get_mens(),municipio.get_mens());
	EXPECT_EQ(municipio_head.get_womens(),municipio.get_womens());
	EXPECT_EQ(municipio_head.get_habitants(),municipio.get_habitants());

	a.goto_last();
	municipio=a.get_municipio();
	mens=326;
	womens=318;
	EXPECT_EQ(14075,municipio.get_postal_code());
	EXPECT_EQ("Zuheros",municipio.get_name());
	EXPECT_EQ(mens,municipio.get_mens());
	EXPECT_EQ(womens,municipio.get_womens());
	EXPECT_EQ(mens+womens,municipio.get_habitants());

	a.goto_next();
	municipio=a.get_municipio();
	mens=0;
	womens=0;
	EXPECT_EQ(municipio_head.get_postal_code(),municipio.get_postal_code());
	EXPECT_EQ(municipio_head.get_name(),municipio.get_name());
	EXPECT_EQ(municipio_head.get_mens(),municipio.get_mens());
	EXPECT_EQ(municipio_head.get_womens(),municipio.get_womens());
	EXPECT_EQ(municipio_head.get_habitants(),municipio.get_habitants());

	a.goto_previous();
	municipio=a.get_municipio();
	mens=326;
	womens=318;
	EXPECT_EQ(14075,municipio.get_postal_code());
	EXPECT_EQ("Zuheros",municipio.get_name());
	EXPECT_EQ(mens,municipio.get_mens());
	EXPECT_EQ(womens,municipio.get_womens());
	EXPECT_EQ(mens+womens,municipio.get_habitants());

	municipio.set_name("zztop");
	municipio.set_postal_code(11111);
	municipio.set_mens(123);
	municipio.set_womens(321);
	a.add(municipio);
	a.goto_last();
	municipio=a.get_municipio();
	mens=123;
	womens=321;
	EXPECT_EQ(11111,municipio.get_postal_code());
	EXPECT_EQ("zztop",municipio.get_name());
	EXPECT_EQ(mens,municipio.get_mens());
	EXPECT_EQ(womens,municipio.get_womens());
	EXPECT_EQ(mens+womens,municipio.get_habitants());

	municipio.set_name("Aaztec");
	municipio.set_postal_code(11111);
	municipio.set_mens(123);
	municipio.set_womens(321);
	a.add(municipio);
	a.goto_head();
	municipio=a.get_municipio();
	mens=123;
	womens=321;
	EXPECT_EQ(11111,municipio.get_postal_code());
	EXPECT_EQ("Aaztec",municipio.get_name());
	EXPECT_EQ(mens,municipio.get_mens());
	EXPECT_EQ(womens,municipio.get_womens());
	EXPECT_EQ(mens+womens,municipio.get_habitants());
}
