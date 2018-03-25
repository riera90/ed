#include "gtest/gtest.h"
#include "paths.hpp"

#include "Provincia_base.hpp"
#include "Provincia_handler.hpp"
#include "Provincia_controler.hpp"


TEST(Provincia_base, constructor){
	Provincia_base a;
	EXPECT_EQ(0,a.n_municipios());
}

TEST(Provincia_base, seters_and_geters){
	Provincia_base a;
	a.set_code(1);
	a.set_name("Córdoba");
	EXPECT_EQ(1,a.get_code());
	EXPECT_EQ("Córdoba",a.get_name());
}

TEST(Provincia_base, observers){
	Provincia_handler a;
	Municipio municipio;
	Municipio municipio_head;
	a.load_data(csv_file_path);
	EXPECT_EQ(386736,a.get_total_mens());
	EXPECT_EQ(401483,a.get_total_womens());
	EXPECT_EQ(401483+386736,a.get_total_habitants());
}

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

TEST(Provincia_handler, exists){
	Provincia_handler a;
	Municipio municipio;
	Municipio municipio_head;
	a.load_data(csv_file_path);
	EXPECT_EQ(true,a.exists("Adamuz"));
	EXPECT_EQ(false,a.exists("Ad"));
}

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

TEST(Provincia_handler, locate_and_remove){
	Provincia_handler a;
	Municipio municipio_head;
	a.load_data(csv_file_path);
	a.goto_head();
	municipio_head=a.get_municipio();
	EXPECT_EQ(municipio_head,*(a.locate(municipio_head)));
	a.erase(municipio_head);
	a.goto_head();
	EXPECT_EQ(false,a.exists(municipio_head.get_name()));
	EXPECT_EQ(false,a.is_empty());
	a.clear();
	EXPECT_EQ(true,a.is_empty());
}


TEST(Provincia_handler, modify){
	Provincia_handler a;
	Municipio municipio_head;
	Municipio municipio;
	a.load_data(csv_file_path);
	a.goto_head();
	municipio.set_postal_code(123);
	municipio.set_name("Zzz23");
	municipio.set_mens(2);
	municipio.set_womens(1);
	a.modify(municipio);
	a.goto_last();
	municipio_head=a.get_municipio();
	int mens=2;
	int womens=1;
	EXPECT_EQ(123,municipio.get_postal_code());
	EXPECT_EQ("Zzz23",municipio.get_name());
	EXPECT_EQ(mens,municipio.get_mens());
	EXPECT_EQ(womens,municipio.get_womens());
	EXPECT_EQ(mens+womens,municipio.get_habitants());
}
