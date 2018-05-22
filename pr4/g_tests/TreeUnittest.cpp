#include "gtest/gtest.h"
#include "Tree.hpp"

TEST(Tree, Builder){
	Tree t;
	EXPECT_TRUE(t.getRoot()==NULL);
}

TEST(Tree, getSon_and_parent_empty){
	Tree t;
	EXPECT_TRUE(t.getParent(t.getRoot())==NULL);
	EXPECT_EQ(t.getSons(t.getRoot()).size(),0);
}
