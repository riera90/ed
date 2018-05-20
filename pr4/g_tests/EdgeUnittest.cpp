#include "gtest/gtest.h"
#include "Edge.hpp"


// TEST(Edge, Parametrized_builder){
// 	Vertex v1
// 	Vertex v2
// 	Edge e(v1,v2);
// 	EXPECT_TRUE(e.getVertex1()==v1);
// 	EXPECT_TRUE(e.getVertex2()==v2);
// 	EXPECT_TRUE(e.getOtherVertex(v1)==v2);
// }

// TEST(Edge, copy_builder){
// 	Vertex* v1=new Vertex();
// 	Vertex* v2=new Vertex();
// 	Edge e(v1,v2);
// 	EXPECT_TRUE(e.getVertex1()==v1);
// 	EXPECT_TRUE(e.getVertex2()==v2);
// 	EXPECT_TRUE(e.getOtherVertex(v1)==v2);
// }
//
// TEST(Edge, seters_and_geters){
// 	Vertex* v1=new Vertex();
// 	Vertex* v2=new Vertex();
// 	Vertex* v3=new Vertex();
// 	Edge e1(v1,v2);
// 	Edge e2(e1);
// 	EXPECT_TRUE(e1==e2);
// }
//
// TEST(Edge, operators){
// 	Vertex* v1=new Vertex();
// 	Vertex* v2=new Vertex();
// 	Vertex* v3=new Vertex();
// 	Edge e1(v1,v2);
// 	Edge e2(v2,v3);
// 	Edge e3(v1,v2);
// 	EXPECT_TRUE(e1==e3);
// 	EXPECT_FALSE(e1==e2);
// 	EXPECT_FALSE(e3==e2);
// 	e3=e2;
// 	EXPECT_TRUE(e2==e3);
// 	EXPECT_FALSE(e1==e2);
// 	EXPECT_FALSE(e1==e3);
// }
