#include "gtest/gtest.h"
#include "Point3D.hpp"

TEST(Point3D, Defautl_builder){
	Point3D p;
	EXPECT_NEAR(0,p.getX(),00000001);
	EXPECT_NEAR(0,p.getY(),00000001);
	EXPECT_NEAR(0,p.getZ(),00000001);
}

TEST(Point3D, Parametrized_builder){
	Point3D p(1,2,3);
	EXPECT_NEAR(1,p.getX(),00000001);
	EXPECT_NEAR(2,p.getY(),00000001);
	EXPECT_NEAR(3,p.getZ(),00000001);
}
