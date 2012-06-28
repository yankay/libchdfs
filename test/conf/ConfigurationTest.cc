/*
 * ConfigurationTest.cpp
 *
 *  Created on: Jun 26, 2012
 *      Author: yank1
 */
#include <iostream>
#include "gtest/gtest.h"

#include "../../src/conf/Configuration.h"

//TEST(Configure, SETGET) {
//	hadoop::Configuration conf;
//	conf.set("key1","value1");
//	conf.set("key2","value2");
//	EXPECT_EQ("value1",conf.get("key1"));
//}

TEST(Configure,substituteVars){
	hadoop::Configuration conf;
	std::string result(conf.substituteVars("${USER} use ${LANG}"));
	std::cout << result << std::endl;
	EXPECT_EQ("yankai use en_US.UTF-8",result);
}
