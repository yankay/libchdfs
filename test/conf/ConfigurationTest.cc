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

#include "../../src/conf/Configuration.h"

# define INT32_MIN		(-2147483647-1)
# define INT32_MAX		(2147483647)

TEST(Configure, SETTRIM) {
	libhadoop::Configuration conf;
	conf.set("key1"," value1 ");
	conf.set("key2","value2");
	EXPECT_EQ("value2",conf.get("key2"));
	EXPECT_EQ("value1",conf.getTrimmed("key1"));
}

TEST(Configure, SETINT) {
	libhadoop::Configuration conf;
	conf.setInt("key1",100);
	conf.setInt("key2",-100);
	EXPECT_EQ(100,conf.getInt("key1",0));
	EXPECT_EQ(-100,conf.getInt("key2",0));
}

TEST(Configure, SETLONG) {
	libhadoop::Configuration conf;
	conf.setLong("key1",(int64_t)INT32_MAX+1);
	conf.setLong("key2",(int64_t)INT32_MIN-1);
	EXPECT_EQ((int64_t)INT32_MAX+1,conf.getLong("key1",0));
	EXPECT_EQ((int64_t)INT32_MIN-1,conf.getLong("key2",0));
}

TEST(Configure, SETSTRINGS) {
	libhadoop::Configuration conf;
	conf.set("key1","1,2,3");
	std::stringstream ss;
	std::string value;
	std::vector<std::string> v=conf.getStringCollection("key1");
	for (size_t i = 0; i < v.size(); ++i) {
		ss << v[i];
	}
	ss >> value;
	EXPECT_EQ("123",value);
}


TEST(Configure, SETTREAM) {
	libhadoop::Configuration conf;
	conf.set("key1"," 1 2 3 ");
	std::stringstream ss;
	std::string value;
	std::vector<std::string> v=conf.getTrimmedStringCollection("key1");
	for (size_t i = 0; i < v.size(); ++i) {
		ss << v[i];
	}
	ss >> value;
	EXPECT_EQ("123",value);
}


TEST(Configure, SETSTRINGS2) {
	libhadoop::Configuration conf;
	std::vector<std::string> s;
	s.push_back("1");
	s.push_back("2");
	s.push_back("3");
	conf.setStrings("key1",s);
	EXPECT_EQ("1,2,3",conf.get("key1",""));
	EXPECT_EQ(s,conf.getStringCollection("key1"));
}


//TEST(Configure,substituteVars){
//	libhadoop::Configuration conf;
//	std::string result(conf.substituteVars("${USER} use ${LANG}"));
//	std::cout << result << std::endl;
//	EXPECT_EQ("yankai use en_US.UTF-8",result);
//}
