/*
 * ConfigurationTest.cpp
 *
 *  Created on: Jun 26, 2012
 *      Author: yank1
 */

#include "gtest/gtest.h"

#include "../../src/conf/Configuration.h"

TEST(Configure, ReturnOne) {
	hadoop::Configuration conf;
	EXPECT_EQ(1,conf.returnOne());
}

