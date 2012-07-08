/*
 * UserGroupInformation.cc
 *
 *  Created on: Jul 7, 2012
 *      Author: yank1
 */

#include <sstream>
#include <stdlib.h>
#include "security/UserGroupInformation.h"
#include "gtest/gtest.h"


using namespace std;
using namespace libhadoop;

TEST(UserGroupInformation, getCurrentUser) {
	UserGroupInformation& ugi1=UserGroupInformation::getCurrentUser();
	stringstream ss;
	ss << getenv("USER") << " (auth:" << "SIMPLE" << ")";
	EXPECT_EQ(ss.str(),ugi1.toString());

}
