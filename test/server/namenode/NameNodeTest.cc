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

using namespace libhadoop;

TEST(NameNode, getAddress) {
	try {
		libhadoop::Configuration conf;
		conf.set("fs.default.name", "hdfs://master:9000");
		NameNode namenode;
		InetSocketAddress address = namenode.getAddress(conf);
		EXPECT_EQ("master", address.hostname);
		EXPECT_EQ(8020, address.port);
	} catch (std::string& msg) {
		std::cout << msg << std::endl;
	}catch (...) {
		std::cout << "error" << std::endl;
		abort();
	}

}

