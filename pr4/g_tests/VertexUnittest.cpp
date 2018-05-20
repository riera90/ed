#include "gtest/gtest.h"
#include "Vertex.hpp"

TEST(Vertex, Default_builder){
	Point3D p(1,2,3);
	Vertex v;
	v.setPoint(p);
	EXPECT_EQ(v.getPoint(),p);
}

TEST(Vertex, parametrized_builder){
	Point3D p(1,2,3);
	Vertex v(p);
	v.setPoint(p);
	EXPECT_EQ(v.getPoint(),p);
}

TEST(Vertex, operators){
	Vertex v1(Point3D(1,1,1));
	Vertex v2(Point3D(2,2,2));
	EXPECT_TRUE(v1.getPoint()==Point3D(1,1,1));
	EXPECT_TRUE(v2.getPoint()==Point3D(2,2,2));
	EXPECT_FALSE(v1==v2);
	v1=v2;
	EXPECT_TRUE(v1.getPoint()==Point3D(2,2,2));
	EXPECT_TRUE(v2.getPoint()==Point3D(2,2,2));
	EXPECT_FALSE(v2.getPoint()==Point3D(2,2,1));
	EXPECT_TRUE(v1==v2);
}
