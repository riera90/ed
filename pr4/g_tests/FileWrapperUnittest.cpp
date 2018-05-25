#include "gtest/gtest.h"
#include "FileWrapper.hpp"

TEST(FileWrapper, read){
	FileWrapper f("output/vertices.txt");
	DenseGraph g=f.read();
	EXPECT_EQ(g.getVertexes().size(),5);
}


TEST(FileWrapper, minTreePrim){
	FileWrapper f("output/vertices.txt");
	DenseGraph g=f.read();
	g.minTreePrim().printTree();
}

TEST(FileWrapper, minTreeKruskal){
	FileWrapper f("output/vertices.txt");
	DenseGraph g=f.read();
	g.minTreeKruskal().printTree();
}
