/*
 * DFSClient_test.cpp
 *
 *  Created on: Jun 26, 2012
 *      Author: yank1
 */


#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>

#include "gtest/gtest.h"

#include "../../src/hdfs/DFSClient.h"

using namespace std;
using namespace libhadoop;

TEST(FileSystem, GETDEFAULTURI) {
	Configuration conf;
	conf.set("fs.default.name","hdfs://localhost:9000");
	DFSClient dfsClient(conf);
	dfsClient.delete_m("/test/t",false);
}

