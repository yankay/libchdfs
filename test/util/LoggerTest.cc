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

#include "util/Logger.h"

using namespace std;
using namespace libhadoop;

TEST(Logger, TEST) {
	LOG_TRACE("LogTest","test1")
	LOG_WARN("LogTest","test2")
}

