#include "gtest/gtest.h"
#include "Point2D.hpp"

TEST(Point2D, Defautl_builder){
	Point2D p;
	EXPECT_NEAR(0,p.getX(),00000001);
	EXPECT_NEAR(0,p.getY(),00000001);
}

TEST(Point2D, Parametrized_builder){
	Point2D p(1,2);
	EXPECT_NEAR(1,p.getX(),00000001);
	EXPECT_NEAR(2,p.getY(),00000001);
}


TEST(Point2D, seters_and_geters){
	Point2D p;
	p.setX(2);
	p.setY(3);
	EXPECT_NEAR(2,p.getX(),00000001);
	EXPECT_NEAR(3,p.getY(),00000001);
}

TEST(Point2D, string_seters_and_geters){
	Point2D p;
	p.SetPointString("1 2");
	EXPECT_NEAR(1,p.getX(),00000001);
	EXPECT_NEAR(2,p.getY(),00000001);
	EXPECT_EQ(p.getPointString(),"1 2");
}

// TEST(Point2D, readers_and_writers){
// 	Point2D p;
// 	std::cout << "enter a point: ";
// 	p.readPointStdin();
// 	p.writePointStdout();
// 	std::cout << "is this ok? [y/n] > ";
// 	std::string ok;
// 	std::cin >> ok;
// 	EXPECT_EQ("y",ok);
// }

TEST(Point2D, operators){
	Point2D p1(1,2);
	Point2D p2;
	p2=p1;
	EXPECT_NEAR(1,p2.getX(),00000001);
	EXPECT_NEAR(2,p2.getY(),00000001);
	EXPECT_TRUE(p1==p2);
}

TEST(Point2D, more_operators){
	Point2D p1(1,2);
	Point2D p2;
	p2=p1;
	EXPECT_NEAR(1,p2.getX(),00000001);
	EXPECT_NEAR(2,p2.getY(),00000001);
	EXPECT_FALSE(p1!=p2);
}
