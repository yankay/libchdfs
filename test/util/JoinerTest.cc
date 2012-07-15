/*
 * ConfigurationTest.cpp
 *
 *  Created on: Jun 26, 2012
 *      Author: yank1
 */
#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>

#include "gtest/gtest.h"

#include "util/Joiner.h"

using namespace std;
using namespace libhadoop;

TEST(Joiner, JOIN) {
	vector<string> v;
	v.push_back("a");
	v.push_back("b");
	v.push_back("c");
	Joiner j=Joiner::on(",");
	string s=j.join(v);
	EXPECT_EQ("a,b,c",s);
}

