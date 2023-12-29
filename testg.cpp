//  testg.cpp
//
//  Sharva Thakur
//  Project 3
//
//  This test file tests all the functions from barchart other than graph
//  using gtests
//

#include <iostream>
#include "barchartanimate.h"
#include <gtest/gtest.h>


TEST(barchart,defaultconstructor_1){
	BarChart B;
	
	ASSERT_EQ(B.getSize(),0);
}

TEST(barchart,defaultconstructor_2){
	BarChart Z;
	ASSERT_EQ(Z.getSize(),0);
}

TEST(barchart,parametrizedconstructor_1){
	BarChart A(10);
	
	ASSERT_EQ(A.getSize(),0);
	
}

TEST(barchart,parametrizedconstructor_2){
	BarChart A(5555);
	
	ASSERT_EQ(A.getSize(),0);
	
	A.clear();

	ASSERT_EQ(A.getSize(),0);
	
}

TEST(barchart, addbar_1){
	
	BarChart S(4);
	
	ASSERT_EQ(S.getSize(),0);
	
	ASSERT_TRUE(S.addBar("Mumbai", 10,"Asia"));
	ASSERT_TRUE(S.addBar("Chicago", 80,"USA"));
	
	ASSERT_EQ(S.getSize(),2);
	
	S.clear();
	
	ASSERT_EQ(S.getSize(),0);
}


TEST(barchart, addbar_2){
	
	BarChart S(2);
	
	ASSERT_EQ(S.getSize(),0);
	
	ASSERT_TRUE(S.addBar("Mumbai", 10,"Asia"));
	ASSERT_TRUE(S.addBar("Chicago", 60,"USA"));
	
	ASSERT_FALSE(S.addBar("Miami", 100,"USA"));
	ASSERT_FALSE(S.addBar("LA", 78,"USA"));
	
	ASSERT_EQ(S.getSize(),2);
	
	Bar N("Mumbai", 10,"Asia");
	
	ASSERT_EQ(S[0].getName(),N.getName());
	
	S.clear();
	
	ASSERT_EQ(S.getSize(),0);
	
}

TEST(barchart, copy_constructor_1){
	
	BarChart S(4);
	ASSERT_EQ(S.getSize(),0);
	
	ASSERT_TRUE(S.addBar("Mumbai", 10,"Asia"));
	ASSERT_TRUE(S.addBar("Chicago", 60,"USA"));
	
	ASSERT_EQ(S.getSize(),2);
	
	BarChart copy(S);
	
	ASSERT_EQ(copy.getSize(),2);
	ASSERT_EQ(copy[0].getName(),S[0].getName());
	
}

TEST(barchart, copy_constructor_empty){
	
	BarChart S;
	
	ASSERT_EQ(S.getSize(),0);
	
	BarChart copy(S);
	ASSERT_EQ(copy.getSize(),0);
	
}

TEST(barchart, copy_constructor_edgecase){
		BarChart S(4);
	
	ASSERT_EQ(S.getSize() ,0);
	
	ASSERT_TRUE(S.addBar("Mumbai", 10,"Asia"));
	ASSERT_TRUE(S.addBar("Chicago", 60,"USA"));
	
	ASSERT_TRUE(S.addBar("Miami", 100,"USA"));
	ASSERT_TRUE(S.addBar("LA", 78,"USA"));
	
	ASSERT_EQ(S.getSize() ,4);
	
	BarChart copy(S);
	
	ASSERT_EQ(copy.getSize(),4);
	ASSERT_EQ(copy[0].getName(),S[0].getName());
	ASSERT_EQ(copy[3].getName(),S[3].getName());
}


TEST(barchart, copy_constructor_equal1){
	
	BarChart S(4);
	ASSERT_EQ(S.getSize() ,0);
	
	ASSERT_TRUE(S.addBar("Mumbai", 10,"Asia"));
	ASSERT_TRUE(S.addBar("Chicago", 60,"USA"));
	
	ASSERT_TRUE(S.addBar("Miami", 100,"USA"));
	ASSERT_TRUE(S.addBar("LA", 78,"USA"));
	
	BarChart copy = S;
	
	ASSERT_EQ(copy.getSize(),4);
	ASSERT_EQ(copy[0].getName(),S[0].getName());
	ASSERT_EQ(copy[3].getName(),S[3].getName());
	
}


TEST(barchart, copy_constructor_equal2){
	
	BarChart S(4);
	ASSERT_EQ(S.getSize() ,0);
	
	ASSERT_TRUE(S.addBar("Mumbai", 10,"Asia"));
	ASSERT_TRUE(S.addBar("Chicago", 60,"USA"));
	
	ASSERT_TRUE(S.addBar("Miami", 100,"USA"));
	ASSERT_TRUE(S.addBar("LA", 78,"USA"));

	BarChart copy(1);
	
	ASSERT_EQ(copy.getSize(),0);

	ASSERT_TRUE(copy.addBar("Miami", 100,"USA"));
	
	ASSERT_EQ(copy.getSize(),1);
	
	copy = S;
	
	ASSERT_EQ(copy.getSize(),4);
	ASSERT_EQ(copy[0].getName(),S[0].getName());
	ASSERT_EQ(copy[3].getName(),S[3].getName());
	
}

TEST(barchart, clear1){
	
	BarChart S(1000);
	ASSERT_EQ(S.getSize() ,0);
	
	S.clear();
	
	ASSERT_EQ(S.getSize() ,0);
	
}


TEST(barchart, clear2){
	
	BarChart S(4);
	ASSERT_EQ(S.getSize() ,0);
	
	ASSERT_TRUE(S.addBar("Mumbai", 10,"Asia"));
	ASSERT_TRUE(S.addBar("Chicago", 60,"USA"));
	
	ASSERT_TRUE(S.addBar("Miami", 100,"USA"));
	ASSERT_TRUE(S.addBar("LA", 78,"USA"));

	ASSERT_EQ(S.getSize() ,4);

	S.clear();
	
	ASSERT_EQ(S.getSize() ,0);

}

TEST(barchart, setFrame_getframe){
	
	BarChart S;
	
	string frame = "Asia";
	S.setFrame(frame);
	
	ASSERT_TRUE(S.getFrame() == frame);
	
}

TEST(barchart, setFrame_getframe2){
	
	string frame = "Asia";
	BarChart S(4);
	ASSERT_EQ(S.getSize() ,0);
	
	ASSERT_TRUE(S.addBar("Mumbai", 10,"Asia"));
	ASSERT_TRUE(S.addBar("Chicago", 60,"USA"));
	
	ASSERT_TRUE(S.addBar("Miami", 100,"USA"));
	ASSERT_TRUE(S.addBar("LA", 78,"USA"));
	
	S.setFrame(frame);
	
	BarChart copy = S;
	
	ASSERT_TRUE(copy.getFrame() == frame);
	
	
}

TEST(barchart, dump){
	BarChart S(4);
	
	S.setFrame("2002");
	ASSERT_TRUE(S.addBar("Washington", 10,"USA"));
	ASSERT_TRUE(S.addBar("Chicago", 60,"USA"));
	
	ASSERT_TRUE(S.addBar("Miami", 100,"USA"));
	ASSERT_TRUE(S.addBar("LA", 78,"USA"));
	
	
	stringstream parser;
	
	S.dump(parser);
	
	string myout = parser.str();
	
	string expected;
	
	expected += "frame: " + S.getFrame() + "\n";
	for(int i = 0; i < S.getSize(); i++){
		expected += S[i].getName() + " ";
		int a = S[i].getValue();
		expected += to_string(a) + " USA" + '\n';
		
	}
	ASSERT_EQ(myout,expected);
	
}

TEST(barchart, dump2){
	BarChart S(4);
	
	S.setFrame("2002");
	ASSERT_TRUE(S.addBar("Mumbai", 10,"India"));
	ASSERT_TRUE(S.addBar("Delhi", 60,"India"));
	
	stringstream parser;
	
	S.dump(parser);
	
	string myout = parser.str();
	
	string expected;
	
	expected += "frame: " + S.getFrame() + "\n";
	for(int i = 0; i < S.getSize(); i++){
		expected += S[i].getName() + " ";
		int a = S[i].getValue();
		expected += to_string(a) + " India" + '\n';
		
	}
	ASSERT_EQ(myout,expected);
	
	ASSERT_TRUE(S.addBar("LA", 78,"USA"));
	S.dump(parser);
	
	myout = parser.str();
	
	ASSERT_FALSE(myout == expected);
	
}