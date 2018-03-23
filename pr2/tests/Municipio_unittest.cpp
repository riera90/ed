#include "gtest/gtest.h"

#include "Municipio.hpp"


TEST(Municipio, default_constructor){
	Municipio a;
	EXPECT_EQ(0,a.get_postal_code());
	EXPECT_EQ("",a.get_name());
	EXPECT_EQ(0,a.get_mens());
	EXPECT_EQ(0,a.get_womens());
}
