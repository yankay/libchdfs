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

#include "server/namenode/NameNode.h"

using namespace std;
using namespace libhadoop;

TEST(NameNode, getAddress) {
	Configuration conf;
	conf.set("fs.default.name", "hdfs://master:9000");
	NameNode namenode;
	InetSocketAddress address = namenode.getAddress(conf);
	string s = address.toString();
	EXPECT_EQ("master:9000", s);
}

