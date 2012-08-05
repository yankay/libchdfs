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
#include <string>

#include "gtest/gtest.h"
#include "io/UTF8.h"

using namespace std;
using namespace libhadoop;

TEST(FileSystem, READ) {
	int8_t bytes[]= {-23, -94, -100, -27, -68, -128};
	wstringstream buffer;
	UTF8::readChars(bytes,buffer,6);
	wstring s=L"颜开";
	EXPECT_EQ(s,buffer.str());
}

