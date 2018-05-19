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


TEST(Point3D, seters_and_geters){
	Point3D p;
	p.setX(2);
	p.setY(3);
	p.setZ(1);
	EXPECT_NEAR(2,p.getX(),00000001);
	EXPECT_NEAR(3,p.getY(),00000001);
	EXPECT_NEAR(1,p.getZ(),00000001);
}

TEST(Point3D, string_seters_and_geters){
	Point3D p;
	p.SetPointString("1 2 3");
	EXPECT_NEAR(1,p.getX(),00000001);
	EXPECT_NEAR(2,p.getY(),00000001);
	EXPECT_NEAR(3,p.getZ(),00000001);
	EXPECT_EQ(p.getPointString(),"1 2 3");
}

// TEST(Point3D, readers_and_writers){
// 	Point3D p;
// 	std::cout << "enter a point: ";
// 	p.readPointStdin();
// 	p.writePointStdout();
// 	std::cout << "is this ok? [y/n] > ";
// 	std::string ok;
// 	std::cin >> ok;
// 	EXPECT_EQ("y",ok);
// }
