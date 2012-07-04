/*
 * NameNode.h
 *
 *  Created on: Jul 2, 2012
 *      Author: yank1
 */

#ifndef NAMENODE_H_
#define NAMENODE_H_

#include <string>
#include <stdlib.h>
#include <iostream>

#include "net/InetSocketAddress.h"
#include "conf/Configuration.h"
#include "net/URI.h"
#include "net/NetUtils.h"
#include "fs/FileSystem.h"
#include "util/Logger.h"
#include "util/StringUtils.h"
#include "hdfs/protocol/FSConstants.h"

namespace libhadoop {

class NameNode {
public:
	const static int32_t DEFAULT_PORT;
	const static std::string LOG_NAME;

	static InetSocketAddress getAddress(const libhadoop::Configuration& conf);

	static InetSocketAddress getAddress(const std::string& conf);
};

} /* namespace libhadoop */
#endif /* NAMENODE_H_ */
