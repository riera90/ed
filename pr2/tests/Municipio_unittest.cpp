#include "gtest/gtest.h"

#include "Municipio.hpp"


TEST(Municipio, default_constructor){
	Municipio a;
	EXPECT_EQ("",a.get_name());
	EXPECT_EQ(0,a.get_postal_code());
	EXPECT_EQ(0,a.get_mens());
	EXPECT_EQ(0,a.get_womens());
}

TEST(Municipio, constructor_with_paramethers){
	Municipio a("test",1000,12,13);
	EXPECT_EQ("test",a.get_name());
	EXPECT_EQ(1000,a.get_postal_code());
	EXPECT_EQ(12,a.get_mens());
	EXPECT_EQ(13,a.get_womens());
}

TEST(Municipio, compare_habitants){
	Municipio a("test" ,1000,12,13);
	Municipio b("test2",1000,12,14);
	 EXPECT_EQ(true,compare_habitants(a,b));
}

TEST(Municipio, operators){
	Municipio a("test" ,1000,12,13);
	Municipio b("test2",1000,12,14);
	EXPECT_EQ(true,a<b);
}
