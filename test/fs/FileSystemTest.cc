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

#include "../../src/fs/FileSystem.h"

using namespace std;
using namespace libhadoop;

TEST(FileSystem, GETDEFAULTURI) {
	Configuration conf;
	URI uri=FileSystem::getDefaultUri(conf);
	EXPECT_EQ("file:///",uri.toString());

	conf.set("fs.default.name","local");
	uri=FileSystem::getDefaultUri(conf);
	EXPECT_EQ("file:///",uri.toString());

	conf.set("fs.default.name","hdfs://master:9000");
	uri=FileSystem::getDefaultUri(conf);
	EXPECT_EQ("hdfs://master:9000",uri.toString());

	conf.set("fs.default.name","master:9000");
	uri=FileSystem::getDefaultUri(conf);
	EXPECT_EQ("hdfs://master:9000",uri.toString());


	conf.set("fs.default.name","hdfs://master:abcd");
	uri=FileSystem::getDefaultUri(conf);
	EXPECT_EQ("hdfs://master",uri.toString());
}

