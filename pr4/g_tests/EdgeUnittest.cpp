#include "gtest/gtest.h"
#include "Edge.hpp"


TEST(Edge, Parametrized_builder){
	Vertex* v1=new Vertex(Point2D(1,1));
	Vertex* v2=new Vertex(Point2D(2,2));
	Edge e(v1,v2);
	EXPECT_TRUE(e.getVertex1()==v1);
	EXPECT_TRUE(e.getVertex2()==v2);
	EXPECT_TRUE(e.getOtherVertex(v1)==v2);
}

TEST(Edge, copy_builder){
	Vertex* v1=new Vertex(Point2D(1,1));
	Vertex* v2=new Vertex(Point2D(2,2));
	Edge e1(v1,v2);
	Edge e2(e1);
	EXPECT_TRUE(e2.getVertex1()==v1);
	EXPECT_TRUE(e2.getVertex2()==v2);
	EXPECT_TRUE(e2.getOtherVertex(v1)==v2);
}

TEST(Edge, seters_and_geters){
	Vertex* v1=new Vertex(Point2D(1,1));
	Vertex* v2=new Vertex(Point2D(2,2));
	Vertex* v3=new Vertex(Point2D(3,3));
	Edge e1(v1,v2);
	Edge e2(e1);
	e1.getVertex1()->setPoint(Point2D(3,3));
	EXPECT_TRUE(e1==e2);
}

TEST(Edge, operators){
	Vertex* v1=new Vertex(Point2D(1,1));
	Vertex* v2=new Vertex(Point2D(2,2));
	Vertex* v3=new Vertex(Point2D(3,3));
	Edge e1(v1,v2);
	Edge e2(v2,v3);
	Edge e3(v1,v2);
	EXPECT_TRUE(e1==e3);
	EXPECT_FALSE(e1==e2);
	EXPECT_FALSE(e3==e2);;
	e3=e2;
	EXPECT_TRUE(e2==e3);
	EXPECT_FALSE(e1==e2);
	EXPECT_FALSE(e1==e3);
}

TEST(Edge, extra_operators){
	Vertex* v1=new Vertex(Point2D(1,1));
	Vertex* v2=new Vertex(Point2D(2,2));
	Vertex* v3=new Vertex(Point2D(3,3));
	Edge e1(v1,v2);
	Edge e2(v2,v3);
	Edge e3(v1,v2);
	EXPECT_FALSE(e1!=e3);
	EXPECT_TRUE(e1!=e2);
	EXPECT_TRUE(e3!=e2);;
	e3=e2;
	EXPECT_FALSE(e2!=e3);
	EXPECT_TRUE(e1!=e2);
	EXPECT_TRUE(e1!=e3);
}
